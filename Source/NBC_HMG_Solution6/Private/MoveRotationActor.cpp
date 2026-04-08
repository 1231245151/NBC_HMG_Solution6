#include "MoveRotationActor.h"
#include "RotationActorComponent.h"
#include "MoveActorComponent.h"

// Sets default values
AMoveRotationActor::AMoveRotationActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	MovementComp = CreateDefaultSubobject<UMoveActorComponent>(TEXT("MoveComponent"));
	RotationActorComp = CreateDefaultSubobject<URotationActorComponent>(TEXT("RetationComp"));
}

// Called when the game starts or when spawned
void AMoveRotationActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMoveRotationActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

