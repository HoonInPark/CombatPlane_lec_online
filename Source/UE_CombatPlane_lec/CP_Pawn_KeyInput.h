// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UE_CombatPlane_lec.h"
#include "CP_Pawn_Construct.h"
#include "CP_Pawn_KeyInput.generated.h"

/**
 * 
 */
UCLASS()
class UE_COMBATPLANE_LEC_API ACP_Pawn_KeyInput : public ACP_Pawn_Construct
{
	GENERATED_BODY()
	
	ACP_Pawn_KeyInput();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float _DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* _InputComponent) override;

private:
	void ProcessPitch(float _Value);
	void ProcessYaw(float _Value);

	void StabilizeRoll(float _DeltaTime);

	const float AxisSpeed{ 250.f };

	float CurrentSpeed_Pitch{ 0.f };
	float CurrentSpeed_Yaw{ 0.f };
	float CurrentSpeed_Roll{ 0.f };

public:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* pSpringArm;

private:
	const FRotator DefaultSpringArmRotation{ FRotator(-15.f, 0.f, 0.f) };
	void StabilizeSpringArm(float _DeltaTime);
};
