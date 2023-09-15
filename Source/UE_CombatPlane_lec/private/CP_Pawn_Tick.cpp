// Fill out your copyright notice in the Description page of Project Settings.


#include "CP_Pawn_Tick.h"

ACP_Pawn_Tick::ACP_Pawn_Tick()
{
	IsOverInfPt = 0; // 변곡점을 지나지 않고 각도가 증가하는 상태
	TakeOffState = EInfPt::BEFORE_45;
}

void ACP_Pawn_Tick::BeginPlay()
{
	Super::BeginPlay();

}

void ACP_Pawn_Tick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//CPLOG(Warning, TEXT(" DelataTime : %f"), DeltaTime);
	MoveWithEnum(DeltaTime);
}

void ACP_Pawn_Tick::MoveWithCurve(float _DeltaTime)
{
	SetActorLocation(GetActorLocation() + FVector(_DeltaTime * 500.f, 0.f, _DeltaTime * _DeltaTime * 5000.f));
	SetActorRotation(GetActorRotation() + FRotator(_DeltaTime * 10.f, 0.f, 0.f));
}

void ACP_Pawn_Tick::MoveWithInfPt(float _DeltaTime)
{
	if (GetActorRotation().Pitch > 45.f)
		IsOverInfPt = 1; // 변곡점을 지났고 각도가 감소하는 상태
	else if (GetActorRotation().Pitch < 0.f && IsOverInfPt == 1)
		IsOverInfPt = 2; // 변곡점을 지났고 각도가 0인 상태

	switch (IsOverInfPt)
	{
	case 0:
		SetActorLocation(GetActorLocation() + FVector(_DeltaTime * 500.f, 0.f, _DeltaTime * _DeltaTime * 5000.f));
		SetActorRotation(GetActorRotation() + FRotator(_DeltaTime * 10.f, 0.f, 0.f));
		break;
	case 1:
		SetActorLocation(GetActorLocation() + FVector(_DeltaTime * 500.f, 0.f, _DeltaTime * _DeltaTime * 5000.f));
		SetActorRotation(GetActorRotation() + FRotator(_DeltaTime * -10.f, 0.f, 0.f));
		break;
	case 2:
		SetActorLocation(GetActorLocation() + FVector(_DeltaTime * 750.f, 0.f, 0.f));
		break;
	default:
		break;
	}
}

void ACP_Pawn_Tick::MoveWithEnum(float _DeltaTime)
{
	if (GetActorRotation().Pitch > 45.f)
		TakeOffState = EInfPt::AFTER_45; // 변곡점을 지났고 각도가 감소하는 상태
	else if (GetActorRotation().Pitch < 0.f && TakeOffState == EInfPt::AFTER_45)
		TakeOffState = EInfPt::AFTER_0; // 변곡점을 지났고 각도가 0인 상태

	switch (TakeOffState)
	{
	case EInfPt::BEFORE_45:
		SetActorLocation(GetActorLocation() + FVector(_DeltaTime * 500.f, 0.f, _DeltaTime * _DeltaTime * 5000.f));
		SetActorRotation(GetActorRotation() + FRotator(_DeltaTime * 10.f, 0.f, 0.f));
		break;
	case EInfPt::AFTER_45:
		SetActorLocation(GetActorLocation() + FVector(_DeltaTime * 500.f, 0.f, _DeltaTime * _DeltaTime * 5000.f));
		SetActorRotation(GetActorRotation() + FRotator(_DeltaTime * -10.f, 0.f, 0.f));
		break;
	case EInfPt::AFTER_0:
		SetActorLocation(GetActorLocation() + FVector(_DeltaTime * 750.f, 0.f, 0.f));
		break;
	default:
		break;
	}

}


