// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class HW6_API AMyGameMode : public AGameMode
{
	GENERATED_BODY()
	

public:
	AMyGameMode();

private:
	virtual void BeginPlay() override; // 게임이 시작될 때 호출되는 함수, 게임 모드가 초기화된 후에 호출

	UPROPERTY(EditAnywhere, Category = "Level Design")
	TSubclassOf<class AActor> MovingTileClass;

	UPROPERTY(EditAnywhere,Category = "Level Design")
	TSubclassOf<class AActor> RotationTileClass;

	UPROPERTY(EditAnywhere, Category = "Level Design")
	int32 SpawnCount = 10; // 생성할 타일의 개수, 블루프린트에서 수정 가능

	UPROPERTY(EditAnywhere, Category = "Level Design")
	float SpawnSpace = 100.0f; // 타일이 생성될 영역, 블루프린트에서 수정 가능

	void SpawnActors(); // 타일을 생성하는 함수
};
