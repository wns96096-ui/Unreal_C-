// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class PROJECT1_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();
protected:
    // 이 줄이 반드시 있어야 합니다!
    virtual void BeginPlay() override;
public:
    virtual void Tick(float DeltaTime) override;

    void Move();
    void Turn();
    void TriggerEvent(); // 과제: 나만의 이벤트 함수

private:
    int32 StepCount = 0;          // 현재 몇 번째 이동인지
    float TotalDistance = 0.0f;   // 누적 이동 거리
    int32 EventCount = 0;         // 이벤트 발생 횟수
    FVector PreviousLocation;     // 이전 좌표 저장용

    float TimeSinceLastStep = 0.0f; // 이동 간격을 위한 타이머
};
