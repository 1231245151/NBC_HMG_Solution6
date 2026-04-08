// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnActor.generated.h"

UCLASS()
class NBC_HMG_SOLUTION6_API ASpawnActor : public AActor
{
	GENERATED_BODY()
	
protected:
	float Spawndist;
	float Spawnrotation;
	float SpawnActorSpeed;
	FTimerHandle Timehandle;

public:	
	// Sets default values for this actor's properties
	ASpawnActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void RandomSpawn();

};
