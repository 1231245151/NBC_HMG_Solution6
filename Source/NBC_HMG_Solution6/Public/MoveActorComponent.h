// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MoveActorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NBC_HMG_SOLUTION6_API UMoveActorComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	FVector StartLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Movement Settings", meta = (ClampMin = "-1.0", ClampMax = "1.0", UIMin = "-1.0", UIMax = "1.0"))
	FVector VecDir;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Movement Settings", meta = (ClampMin = "0.0", UIMin = "0.0"))
	float MaxDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Movement Settings", meta = (ClampMin = "0.0", UIMin = "0.0"))
	float MoveSpeed;

	bool IsArrival;		// 목적지 도착

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Movement Settings")
	bool IsRoof;		// 루프?

	bool IsReturnbase;	// flase : S->E, true : E->S


	// 랜덤 구현
	FTimerHandle Timehandle;
	FTimerHandle DestroyTimerHandle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Movement Settings")
	float warpDist;		// 순간 이동되는 거리
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Movement Settings")
	bool IsWarp;		// 매타임마다 순간이동 활성

	// 파괴 활성
	bool Isdestroy;

public:	
	// Sets default values for this component's properties
	UMoveActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void Movement(float DeltaTime);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// 일정한 방향으로 이동
	void Warp();

	// 삭제
	void destroy();
		

	// get/set
	void SetVecDir(FVector& _vec) { VecDir = _vec; VecDir.Normalize(); }
	void SetMaxDistance(float _dist) { MaxDistance = _dist; }
	void SetMoveSpeed(float _speed) { MoveSpeed = _speed; }
	void SetIsRoof(bool _true) { IsRoof = _true; }
	void SetIsWarp(bool _true) { IsWarp = _true; }
	void SetIsdestroy(bool _true) { Isdestroy = _true; GetWorld()->GetTimerManager().SetTimer(DestroyTimerHandle, this, &UMoveActorComponent::destroy, 3.0f, true); }
};
