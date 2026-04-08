#include "OrbitActorComponent.h"


UOrbitActorComponent::UOrbitActorComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
    OrbitAxis = FVector(0.f, 1.f, 0.f);
	Radius = 500.f;
}


// Called when the game starts
void UOrbitActorComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UOrbitActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (OrbitAxis.IsNearlyZero())
    {
       
    }
}

