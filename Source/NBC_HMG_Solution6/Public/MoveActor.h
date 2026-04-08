// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "MoveActorComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveActor.generated.h"


UCLASS()
class NBC_HMG_SOLUTION6_API AMoveActor : public AActor
{
	GENERATED_BODY()
	

protected:
	USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components Settings")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components Settings")
	UMoveActorComponent* MovementComp;

public:	
	// Sets default values for this actor's properties
	AMoveActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Movement(float DeltaTime);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetVecDir(FVector& _vec) { MovementComp->SetVecDir(_vec); }
	void SetMaxDistance(float _dist) { MovementComp->SetMaxDistance(_dist); }
	void SetMoveSpeed(float _speed) { MovementComp->SetMoveSpeed(_speed); }
	void SetIsRoof(bool _true) { MovementComp->SetIsRoof(_true); }
	void SetIsWarp(bool _true) { MovementComp->SetIsWarp(_true); }
	void Isdestroy(bool _true) { MovementComp->SetIsdestroy(_true); }


};
