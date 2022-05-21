// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Creates a first person camera component and checks whether it's a nullptr
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	check(CameraComponent != nullptr);
	
	// Attach the camera component to the capsule component
	CameraComponent->SetupAttachment(CastChecked<USceneComponent, UCapsuleComponent>(GetCapsuleComponent()));

	// Position the camera slightly above the eyes and enable the pawn to control camera rotation
	CameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));
	CameraComponent->bUsePawnControlRotation = true;

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();

	check(GEngine != nullptr)
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("[DEBUG] Using MainCharacter Class."));
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult hit;
	FVector traceStart = CameraComponent->GetComponentLocation();
	FRotator rotation = GetControlRotation();
	FVector traceEnd = traceStart + rotation.Vector() * reachDistance;
	worldRef->LineTraceSingleByChannel(hit, traceStart, traceEnd, ECollisionChannel::ECC_GameTraceChannel1);
	// DrawDebugLine(worldRef, traceStart, traceEnd, FColor::Red, false, 3.0f, 0, 3.0f);
	DrawDebugPoint(worldRef, hit.Location, 20.0f ,FColor::Green, false, 3.0f);


	AActor* hitActor = hit.GetActor();
	if(hitActor != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Raycast Fired. Hit Actor %s"), *hitActor->GetName());
	} 
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("Raycast Fired. No Actor Hit."));
	}
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// Axis mappings for movement
	PlayerInputComponent->BindAxis("MoveForward", this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMainCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &AMainCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AMainCharacter::AddControllerPitchInput);

	//PlayerInputComponent->BindAction("FireCast", EInputEvent::IE_Pressed, this, &AMainCharacter::Raycast);
	PlayerInputComponent->BindAction("Interact", EInputEvent::IE_Pressed, this, &AMainCharacter::Interact);
}

void AMainCharacter::MoveForward(float value)
{
	// Find out which way is FORWARD
	FVector direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(direction, value);
}

void AMainCharacter::MoveRight(float value)
{
	FVector direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(direction, value);
}

void AMainCharacter::Interact()
{
	UE_LOG(LogTemp, Warning, TEXT("[DEBUG] - Interaction Button Pressed."));
}

void AMainCharacter::Raycast()
{
	// UWorld* worldRef = GetWorld();
	// FHitResult hit;
	// FVector traceStart = CameraComponent->GetComponentLocation();
	// FRotator rotation = GetControlRotation();
	// FVector traceEnd = traceStart + rotation.Vector() * reachDistance;
	// worldRef->LineTraceSingleByChannel(hit, traceStart, traceEnd, ECollisionChannel::ECC_GameTraceChannel1);
	// DrawDebugLine(worldRef, traceStart, traceEnd, FColor::Red, false, 3.0f, 0, 3.0f);
	// DrawDebugPoint(worldRef, hit.Location, 20.0f ,FColor::Green, false, 3.0f);


	// AActor* hitActor = hit.GetActor();
	// if(hitActor != nullptr)
	// {	
	// 	UE_LOG(LogTemp, Warning, TEXT("Raycast Fired. Hit Actor %s"), *hitActor->GetName());
	// } 
	// else 
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("Raycast Fired. No Actor Hit."));
	// }
}