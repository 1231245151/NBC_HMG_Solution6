// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RotationActorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NBC_HMG_SOLUTION6_API URotationActorComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Rotation Settings", meta = (ClampMin = "-1.0", ClampMax = "1.0", UIMin = "-1.0", UIMax = "1.0"))
	FRotator SpinRotator;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Rotation Settings", meta = (ClampMin = "0.0", UIMin = "0.0"))
	float SpinSpeed;


	// ·£´ý ±¸Çö
	FTimerHandle Timehandle;

	// ÆÄ±« È°¼º
	bool Isdestroy;

public:	
	// Sets default values for this component's properties
	URotationActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void destroy();
		
};
