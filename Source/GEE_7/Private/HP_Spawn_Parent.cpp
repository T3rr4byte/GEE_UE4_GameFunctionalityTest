// Fill out your copyright notice in the Description page of Project Settings.

#include "HP_Spawn_Parent.h"

// Sets default values
AHP_Spawn_Parent::AHP_Spawn_Parent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHP_Spawn_Parent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHP_Spawn_Parent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

