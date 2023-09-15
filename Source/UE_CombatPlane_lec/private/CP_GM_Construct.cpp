// Fill out your copyright notice in the Description page of Project Settings.


#include "CP_GM_Construct.h"

ACP_GM_Construct::ACP_GM_Construct()
{
	DefaultPawnClass = ACP_Pawn_Construct::StaticClass();
	PlayerControllerClass = ACP_PC_Construct::StaticClass();
}

void ACP_GM_Construct::PostLogin(APlayerController* _NewPlayer)
{
	Super::PostLogin(_NewPlayer);
}
