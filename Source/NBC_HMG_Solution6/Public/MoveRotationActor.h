// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveRotationActor.generated.h"

class UMoveActorComponent;
class URotationActorComponent;

UCLASS()
class NBC_HMG_SOLUTION6_API AMoveRotationActor : public AActor
{
	GENERATED_BODY()
	
protected:
	USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components Settings")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components Settings")
	URotationActorComponent* RotationActorComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components Settings")
	UMoveActorComponent* MovementComp;

public:	
	// Sets default values for this actor's properties
	AMoveRotationActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
