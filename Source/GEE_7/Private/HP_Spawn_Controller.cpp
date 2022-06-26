// Fill out your copyright notice in the Description page of Project Settings.

#include "HP_Spawn_Controller.h"

// Sets default values
AHP_Spawn_Controller::AHP_Spawn_Controller()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	currentTime = 0.f;
	xCord = 0.f;

	// set vector and rotator to zero
	ourRotation.ZeroRotator;
	ourLoc.X = 0.f;
	ourLoc.Y = 100.f;
	ourLoc.Z = 4000.f;
}

// Called when the game starts or when spawned
void AHP_Spawn_Controller::BeginPlay()
{
	Super::BeginPlay();

	//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("We are alive"));
	
}

// Called every frame
void AHP_Spawn_Controller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	currentTime = currentTime + 1 * DeltaTime;
	FString ourString = FString::SanitizeFloat(currentTime);

	//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("Our Current Time: ") + ourString);

	if (currentTime >= 20.f)
	{
		// gen a new X
		xCord = generateX(DeltaTime);

		// gen a new Y
		yCord = generateY(DeltaTime);

		//set the x and in the location
		ourLoc.X = xCord;
		ourLoc.Y = yCord;
		

		// Create Spawn params
		FActorSpawnParameters spawnParams;

		//who did the spawn, and we are say this controller did
		spawnParams.Owner = this;

		//set the instigator to default
		spawnParams.Instigator = GetInstigator(); //changed to GetInstigator from just only Instigator

		//spawn the object now
		AHP_Spawn_Parent* ourNewObject = GetWorld()->SpawnActor<AHP_Spawn_Parent>(ourSpawningObject, ourLoc, ourRotation, spawnParams);

		//debug
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::White, TEXT("Bomb dropped"));

		//currentTime back to 0
		currentTime = 0.f;
	}



}

float AHP_Spawn_Controller::generateX(float DeltaSeconds) // -- Generate a new number -- //
{
	float passBack = 0.f;

	passBack = FMath::RandRange(-2000, 2000);

	passBack = passBack + DeltaSeconds;

	return passBack;
}

float AHP_Spawn_Controller::generateY(float DeltaSeconds) // -- Generate a new number -- //
{
	float passBack = 0.f;

	passBack = FMath::RandRange(-2000, 2000);

	passBack = passBack + DeltaSeconds;

	return passBack;
}