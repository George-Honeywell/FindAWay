// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Engine/StaticMesh.h"
#include "Components/BoxComponent.h"

#include "GameFramework/Actor.h"
#include "TESTActor.generated.h"

UCLASS()
class FINDAWAY_API ATESTActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATESTActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Details")
		UStaticMeshComponent* boxMesh;

	UPROPERTY(VisibleAnywhere, category = "Details")
		UBoxComponent* boxCollision;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Details")
		FString itemName;

};
