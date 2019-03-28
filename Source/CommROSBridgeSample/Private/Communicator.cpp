// Copyright Research Institute of Systems Planning, Inc. All Right Reserved.

#include "Communicator.h"


// Sets default values
ACommunicator::ACommunicator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACommunicator::BeginPlay()
{
	Super::BeginPlay();

	// Attach delegate
	OnUpdatePosDelegate.AddDynamic(this, &ACommunicator::UpdateTarget);

	// Advertise topics
	UROSIntegrationGameInstance* ROSInst = Cast<UROSIntegrationGameInstance>(GetGameInstance());
	VectorSender = NewObject<UTopic>(UTopic::StaticClass());
	VectorSender->Init(ROSInst->ROSIntegrationCore, TEXT("/location"), TEXT("geometry_msgs/Vector3"));
	VectorSender->Advertise();

	// Subscribe topics
	VectorReceiver = NewObject<UTopic>(UTopic::StaticClass());
	VectorReceiver->Init(ROSInst->ROSIntegrationCore, TEXT("/target_pos"), TEXT("geometry_msgs/Vector3"));

	std::function<void(TSharedPtr<FROSBaseMsg>)> SubscribeCallback = [&](TSharedPtr<FROSBaseMsg> msg) -> void {
		auto Concrete = StaticCastSharedPtr<ROSMessages::geometry_msgs::Vector3>(msg);
		if (Concrete.IsValid()) {
			FVector vec;
			vec.X = Concrete->x;
			vec.Y = Concrete->y;
			vec.Z = Concrete->z;
			OnUpdatePosDelegate.Broadcast(vec);
		}
		return;
	};

	VectorReceiver->Subscribe(SubscribeCallback);
}

// Called every frame
void ACommunicator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector location = this->TargetCharactor->GetActorLocation();
	double x = location.X;
	double y = location.Y;
	double z = location.Z;
	TSharedPtr<ROSMessages::geometry_msgs::Vector3> vector3Message(new ROSMessages::geometry_msgs::Vector3(x, y, z));
	VectorSender->Publish(vector3Message);
}

void ACommunicator::UpdateTarget(FVector Target)
{
	FVector location = this->TargetActor->GetActorLocation();
	Target.Z = location.Z;

	this->TargetActor->SetActorLocation(Target);
}

