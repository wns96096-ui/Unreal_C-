// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor2.h"
#include "Engine/Engine.h"

// Sets default values
AMyActor2::AMyActor2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor2::BeginPlay()
{
	Super::BeginPlay();
	FVector StartPosition = FVector(0.0f, 0.0f, 50.0f);
	SetActorLocation(StartPosition);
}

// Called every frame
void AMyActor2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Time = Time + DeltaTime;
	while (Step < 10)
	{
	
	if (Time >= 1)
	{
		Time = 0.0f;

		Move();
		Turn();
		TriggerEvent();
		Step++;
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, FString::Printf(TEXT("%d 번째 이동"), Step));
	}
	if (Step == 10)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Blue, FString::Printf(TEXT("총 이동거리 : %.2f"), TotalDistance));
		GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Green, FString::Printf(TEXT("총 이벤트 발생 횟수 : %d"), EventCount));
	}
	break;
	}
}
void AMyActor2::Move()
{
	float RandX = FMath::FRandRange(-50.0f, 50.0f);
	float RandY = FMath::FRandRange(-50.0f, 50.0f);

	FVector CurrentPosition = GetActorLocation();
	FVector NewPosition = CurrentPosition + FVector(RandX, RandY, 0.0f);

	SetActorLocation(NewPosition);
	TotalDistance += FVector::Dist(CurrentPosition, NewPosition);
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Blue, FString::Printf(TEXT("현재좌표 : %s"), *NewPosition.ToString()));
	
}

void AMyActor2::Turn()
{
	float RandYaw = FMath::FRandRange(-30.0f, 30.0f);
	FRotator CurrentRotation = GetActorRotation();
	FRotator NewRotation = CurrentRotation + FRotator(0.0f, RandYaw, 0.0f);
	SetActorRotation(NewRotation);
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Magenta, FString::Printf(TEXT("현재Yaw : %.2f"), NewRotation.Yaw));
}
void AMyActor2::TriggerEvent()
{
	if (FMath::RandRange(0, 1) == 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, TEXT("이벤트 발동!"));
		EventCount++;
	}
}

