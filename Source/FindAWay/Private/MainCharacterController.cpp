// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacterController.h"
#include "Blueprint/UserWidget.h"
#include "Engine/Engine.h"

void AMainCharacterController::BeginPlay()
{
    Super::BeginPlay();

    mainCharacter = Cast<AMainCharacter>(worldRef->GetFirstPlayerController()->GetCharacter());
    UE_LOG(LogTemp, Warning, TEXT("Character Controller in use"));
    UUserWidget* ItemPrompt = CreateWidget(this, HUD_ItemPrompt);
    if(ItemPrompt != nullptr)
    {
        ItemPrompt->AddToViewport();
    }
}

