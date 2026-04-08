#include "SpawnActor.h"
#include "MoveActor.h"

// Sets default values
ASpawnActor::ASpawnActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Spawndist = 500.f;
	Spawnrotation = 360.f;
	SpawnActorSpeed = 1000.f;
}

// Called when the game starts or when spawned
void ASpawnActor::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(Timehandle, this, &ASpawnActor::RandomSpawn, 4.0f, true);
}

// Called every frame
void ASpawnActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnActor::RandomSpawn()
{
	float vecx = FMath::RandRange(0.f, Spawndist);
	float vecy = FMath::RandRange(0.f, Spawndist);
	float vecz = FMath::RandRange(0.f, Spawndist);
	float rotx = FMath::RandRange(0.f, Spawnrotation);
	float roty = FMath::RandRange(0.f, Spawnrotation);
	float rotz = FMath::RandRange(0.f, Spawnrotation);
	float Actorspeed = FMath::RandRange(0.f, SpawnActorSpeed);
	FVector Location(vecx, vecy, vecz);
	FRotator Rotation(rotx, roty, rotz);

	AMoveActor* NewActor = GetWorld()->SpawnActor<AMoveActor>(AMoveActor::StaticClass(), Location, Rotation);
	NewActor->SetMaxDistance(10000);
	NewActor->SetMoveSpeed(Actorspeed);
	NewActor->Isdestroy(true);

}

