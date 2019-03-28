// Copyright Research Institute of Systems Planning, Inc. All Right Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class CommROSBridgeSampleEditorTarget : TargetRules
{
	public CommROSBridgeSampleEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "CommROSBridgeSample" } );
	}
}
