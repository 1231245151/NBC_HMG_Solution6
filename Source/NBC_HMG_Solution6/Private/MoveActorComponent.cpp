// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveActorComponent.h"

// Sets default values for this component's properties
UMoveActorComponent::UMoveActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	StartLocation = FVector::ZeroVector;
	VecDir = FVector(1.f, 1.f, 1.f);
	MaxDistance = 500.f;

	MoveSpeed = 30.f;
	IsArrival = false;
	IsRoof = true;
	IsReturnbase = false;
}


// Called when the game starts
void UMoveActorComponent::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetOwner()->GetActorLocation();
}


// Called every frame
void UMoveActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Movement(DeltaTime);
}

void UMoveActorComponent::Movement(float DeltaTime)
{

	// 이동처리
	if (!FMath::IsNearlyZero(MoveSpeed))
	{
		// 조건 : 루프도는놈이 아닐경우 도착상태가 아니어야함 
		if (!IsArrival || IsRoof)
		{
			// 방향 정규화
			FVector MoveDir = VecDir.GetSafeNormal();

			// 현재위치
			FVector pLocation = GetOwner()->GetActorLocation();
			// 현재 목적지
			FVector TargetPos = IsReturnbase ? StartLocation : StartLocation + (MoveDir * MaxDistance);

			// 벡터 계산
			FVector movevec = TargetPos - pLocation;

			// Tick 이동거리
			float tickDistance = MoveSpeed * DeltaTime;

			// 가려는 길이보다 도착지까지 길이가 더 가까운 경우 목적지위치로 고정 + IsArrival = ture
			if (movevec.Length() < tickDistance)
			{
				GetOwner()->SetActorLocation(TargetPos);
				IsArrival = true;
			}
			// 계속 이동
			else
			{
				FVector tickvec = movevec.GetSafeNormal() * tickDistance;
				GetOwner()->AddActorWorldOffset(tickvec);
			}
		}

		// 타이머 줄일이 있을지도 모르니 분리
		// 만일 도착상태인데 루프인경우 
		if (IsArrival && IsRoof)
		{
			// 반전
			IsReturnbase = !IsReturnbase;
			IsArrival = false;
		}
	}
}

