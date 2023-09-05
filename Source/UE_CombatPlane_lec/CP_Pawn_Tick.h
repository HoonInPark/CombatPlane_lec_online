// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UE_CombatPlane_lec.h"
#include "CP_Pawn_Construct.h"
#include "CP_Pawn_Tick.generated.h"

/**
 * 
 */
UCLASS()
class UE_COMBATPLANE_LEC_API ACP_Pawn_Tick : public ACP_Pawn_Construct
{
	GENERATED_BODY()
	
public:
	ACP_Pawn_Tick();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	int32 IsOverInfPt;

	enum class EInfPt 
	{
		BEFORE_45,
		AFTER_45,
		AFTER_0
	};

	EInfPt TakeOffState;

	void MoveWithCurve(float _DeltaTime);
	void MoveWithInfPt(float _DeltaTime);
	void MoveWithEnum(float _DeltaTime);
};
