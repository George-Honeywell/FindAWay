// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "MainCharacterController.generated.h"

/**
 * 
 */
UCLASS()
class FINDAWAY_API AMainCharacterController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	AMainCharacter* mainCharacter;

	UWorld* worldRef = GetWorld();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PlayerHUD/UI")
		TSubclassOf<class UUserWidget> HUD_ItemPrompt;
	
};
