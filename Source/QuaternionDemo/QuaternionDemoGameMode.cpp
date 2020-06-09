// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "QuaternionDemoGameMode.h"
#include "QuaternionDemoBall.h"

AQuaternionDemoGameMode::AQuaternionDemoGameMode()
{
	// set default pawn class to our ball
	DefaultPawnClass = AQuaternionDemoBall::StaticClass();
}
