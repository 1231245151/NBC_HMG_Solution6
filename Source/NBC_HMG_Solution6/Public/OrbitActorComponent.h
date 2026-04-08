// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OrbitActorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NBC_HMG_SOLUTION6_API UOrbitActorComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	float CurrentAngle;

	FVector OrbitAxis;
	float Radius;


public:	
	// Sets default values for this component's properties
	UOrbitActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
