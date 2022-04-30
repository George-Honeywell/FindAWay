// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "Engine/Canvas.h"

#include "CrosshairHUD.generated.h"

/**
 * 
 */
UCLASS()
class FINDAWAY_API ACrosshairHUD : public AHUD
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	UTexture2D* Crosshair;

public:
	// Primary draw call for the HUD
	virtual void DrawHUD() override;

	
};
