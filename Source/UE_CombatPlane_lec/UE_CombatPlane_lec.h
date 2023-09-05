// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "EngineMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(UE_CombatPlane_lec, Log, All);

// 로그를 쓴 함수명과 그 로그가 위치한 행을 출력
#define CPLOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))

// 로그를 UE_LOG로 쓸 수도 있으나 아래와 같이 커스텀 로그를 설정하면 필요한 정보만 쓸 수 있다.
#define CPLOG_S(Verbosity) UE_LOG(UE_CombatPlane_lec, Verbosity, TEXT("%s"), *CPLOG_CALLINFO)

// 해당 행에서 접근할 수 있는 변수 값을 로그로 출력하고 싶으면 다음 로그 매크로를 사용.
#define CPLOG(Verbosity, Format, ...) UE_LOG(UE_CombatPlane_lec, Verbosity, TEXT("%s%s"), *CPLOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))

// 조건이 참이 아니면 Error 로그가 뜨도록 만듦
#define CPCHECK(Expr, ...)	{ if(!(Expr)) {CPLOG(Error, TEXT("ASSERTION : %s"), TEXT("'"#Expr"'")); return __VA_ARGS__; }}