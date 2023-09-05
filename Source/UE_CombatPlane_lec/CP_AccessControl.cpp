// Fill out your copyright notice in the Description page of Project Settings.


#include "CP_AccessControl.h"

// Sets default values
ACP_AccessControl::ACP_AccessControl()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	pStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ROCK"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Rock(TEXT("/Script/Engine.StaticMesh'/Game/_01_BasicSettings/Meshes/SM_Rock.SM_Rock'"));
	RootComponent = pStaticMeshComponent;
	pStaticMeshComponent->SetStaticMesh(Rock.Object);

	DoOnce = true;
}

// Called when the game starts or when spawned
void ACP_AccessControl::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACP_AccessControl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (DoOnce)
	{
		Speed_Mov = RockNum * 100.f;
		Speed_Rot = RockNum * 100.f;
		DoOnce = false;
	}

	SetActorLocation(GetActorLocation() + FVector(0.f, 0.f, Speed_Mov * DeltaTime));
	SetActorRotation(GetActorRotation() + FRotator(0.f, Speed_Rot * DeltaTime, 0.f));
}

// a = a0 + VT

