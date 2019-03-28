// Copyright Research Institute of Systems Planning, Inc. All Right Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class CommROSBridgeSampleTarget : TargetRules
{
	public CommROSBridgeSampleTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "CommROSBridgeSample" } );
	}
}
