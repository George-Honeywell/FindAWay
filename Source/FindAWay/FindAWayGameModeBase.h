// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FindAWayGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class FINDAWAY_API AFindAWayGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	virtual void StartPlay() override;
	
};
