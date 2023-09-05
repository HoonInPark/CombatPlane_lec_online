// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UE_CombatPlane_lec.h"
#include "GameFramework/Actor.h"
#include "CP_AccessControl.generated.h"

UCLASS()
class UE_COMBATPLANE_LEC_API ACP_AccessControl : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACP_AccessControl();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UStaticMeshComponent* pStaticMeshComponent;

	bool DoOnce;

private:
	int32 RockNum;
	float Speed_Mov;
	float Speed_Rot;

};
