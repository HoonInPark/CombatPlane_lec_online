// Fill out your copyright notice in the Description page of Project Settings.


#include "CP_GM_Tick.h"

ACP_GM_Tick::ACP_GM_Tick()
{
	DefaultPawnClass = ACP_Pawn_Tick::StaticClass();
	PlayerControllerClass = ACP_PC_Construct::StaticClass();
}

