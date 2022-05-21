// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Camera/CameraComponent.h"				// For Camera Component
#include "Components/CapsuleComponent.h"		// For Capsule Component
#include "Components/SceneComponent.h"			// For GetComponentLocation
#include "TESTActor.h"
#include "Engine/Engine.h"

#include "DrawDebugHelpers.h"	// For Raycast Debug Line

#include "MainCharacter.generated.h"

UCLASS()
class FINDAWAY_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void Raycast();

	UPROPERTY(VisibleAnywhere)
	USceneComponent* sceneComp = nullptr;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Camera Setup
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComponent;
	
	// Handles input for moving Forwards and Backwards
	UFUNCTION()
	void MoveForward(float value);

	// Handles input for moving left and right
	UFUNCTION()
	void MoveRight(float value);

	UFUNCTION()
		void Interact();

private:
	UPROPERTY(EditAnywhere)
	float reachDistance;

	UWorld* worldRef = GetWorld();

	UPROPERTY()
		ATESTActor* testActor;

};
