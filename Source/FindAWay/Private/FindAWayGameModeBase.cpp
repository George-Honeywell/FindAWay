// Copyright Epic Games, Inc. All Rights Reserved.


#include "FindAWayGameModeBase.h"

void AFindAWayGameModeBase::StartPlay()
{
    Super::StartPlay();

    check(GEngine != nullptr)
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("[DEBUG] Using FindAWayGameModeBase."));
}