// Fill out your copyright notice in the Description page of Project Settings.


#include "CP_AccessControl_Spawner.h"

// Sets default values
ACP_AccessControl_Spawner::ACP_AccessControl_Spawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnNum = 0;
}

// Called when the game starts or when spawned
void ACP_AccessControl_Spawner::BeginPlay()
{
	Super::BeginPlay();
	
	for (int32 i = 0; i < 5; i++) 
	{
		const FHorizontalPoint HorizontalPoint = { 200.f * i, 200.f * i };
		Spawn_CP_AccessControl(HorizontalPoint, 20 * i);
	}
}

// Called every frame
void ACP_AccessControl_Spawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACP_AccessControl_Spawner::Spawn_CP_AccessControl(const FHorizontalPoint _HorizontalPoint, float _Speed)
{
	SpawnNum++;
	const FActorSpawnParameters SpawnParams;
	GetWorld()->SpawnActor<ACP_AccessControl>(
		ACP_AccessControl::StaticClass(),
		FTransform(FRotator::ZeroRotator, FVector(_HorizontalPoint.Pt_X, _HorizontalPoint.Pt_Y, 0.f)),
		SpawnParams
	);
}

