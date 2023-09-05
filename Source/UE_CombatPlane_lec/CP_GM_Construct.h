// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UE_CombatPlane_lec.h"
#include "CP_Pawn_Construct.h"
#include "CP_PC_Construct.h"

#include "GameFramework/GameModeBase.h"
#include "CP_GM_Construct.generated.h"

/**
 * 
 */
UCLASS()
class UE_COMBATPLANE_LEC_API ACP_GM_Construct : public AGameModeBase
{
	GENERATED_BODY()
	
	ACP_GM_Construct();

public:
	virtual void PostLogin(APlayerController* _NewPlayer) override;
};
