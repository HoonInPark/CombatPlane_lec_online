// Fill out your copyright notice in the Description page of Project Settings.


#include "CP_Pawn_Construct.h"

// Sets default values
ACP_Pawn_Construct::ACP_Pawn_Construct()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	pMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BODY"));
	pCamera = CreateAbstractDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	RootComponent = pMeshComp;
	pCamera->SetupAttachment(pMeshComp);
	pCamera->SetRelativeLocation(FVector(-300.f, 0.f, 250.f));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_BODY(TEXT("/Script/Engine.SkeletalMesh'/Game/_01_BasicSettings/SkeletalMeshes/SK_West_UAV_MQ1.SK_West_UAV_MQ1'"));
	if (SK_BODY.Succeeded())
	{
		pMeshComp->SetSkeletalMesh(SK_BODY.Object);
	}
}

// Called when the game starts or when spawned
void ACP_Pawn_Construct::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void ACP_Pawn_Construct::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACP_Pawn_Construct::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

