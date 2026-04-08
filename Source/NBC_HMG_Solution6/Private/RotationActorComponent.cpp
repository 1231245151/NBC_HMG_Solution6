// Fill out your copyright notice in the Description page of Project Settings.


#include "RotationActorComponent.h"

// Sets default values for this component's properties
URotationActorComponent::URotationActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	SpinRotator = FRotator(0.f, 1.f, 0.f);
	SpinSpeed = 300.f;

}


// Called when the game starts
void URotationActorComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void URotationActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!FMath::IsNearlyZero(SpinSpeed))
	{
		GetOwner()->AddActorWorldRotation(SpinRotator * SpinSpeed * DeltaTime);
	}
}

