// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineGlobals.h"
#include "Engine/Engine.h" 

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HP_Spawn_Parent.h" //needs to be included
#include "HP_Spawn_Controller.generated.h"

UCLASS()
class GEE_7_API AHP_Spawn_Controller : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AHP_Spawn_Controller();

	//AHP_Spawn_Controller(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;


	float generateX(float DeltaSeconds); // generate a new x

	float generateY(float DeltaSeconds); // generate a new y

	float currentTime; // keep the current alive time

	float xCord; // Holds the new x cord
	float yCord; // Holds the new y cord

	FTransform ourOldSpawnLocation; // holds all of ous old spawn information

	FVector ourLoc; // Holds our spawn location

	FRotator ourRotation; // hold the rotation of the object


	//AHP_Spawn_Parent* ourSpawningObject; // "/PowerUps/PowerUP_Parent.h"
	UPROPERTY(EditDefaultsOnly, Category = "Our Spawning Object")

	TSubclassOf<AHP_Spawn_Parent> ourSpawningObject; // holds our blueprint of the object we want to spawn
};
