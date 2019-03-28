// Copyright Research Institute of Systems Planning, Inc. All Right Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "Runtime/Engine/Classes/Engine/StaticMeshActor.h"

#include "ROSIntegration/Classes/RI/Topic.h"
#include "ROSIntegration/Classes/ROSIntegrationGameInstance.h"
#include "ROSIntegration/Public/geometry_msgs/Vector3.h"

#include "Communicator.generated.h"

// Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUpdatePosDelegate, const FVector, TargetPos);


UCLASS()
class COMMROSBRIDGESAMPLE_API ACommunicator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACommunicator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Delegate
	UPROPERTY(BlueprintAssignable, Category = "ROSBridgeSample")
		FUpdatePosDelegate OnUpdatePosDelegate;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// Watch charactor
	UPROPERTY(BlueprintReadWrite, Category = "Variable", Meta = (ExposeOnSpawn = true))
		ACharacter* TargetCharactor;

	// Target object
	UPROPERTY(BlueprintReadWrite, Category = "Variable", Meta = (ExposeOnSpawn = true))
		AStaticMeshActor* TargetActor;

private:
	UFUNCTION()
		void UpdateTarget(FVector Target);

private:
	UTopic* VectorSender;
	UTopic* VectorReceiver;
	
};
