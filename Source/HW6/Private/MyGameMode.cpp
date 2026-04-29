// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"
#include "MyPawn.h"
#include "MyPlayerController.h"

AMyGameMode :: AMyGameMode()
{
	DefaultPawnClass = AMyPawn::StaticClass();
	PlayerControllerClass = AMyPlayerController::StaticClass();
}

void AMyGameMode::BeginPlay()
{
	Super::BeginPlay();
	SpawnActors();
}	

void AMyGameMode::SpawnActors() // 게임 시작 시 무작위 액터 생성
{
    for (int32 i = 0; i < SpawnCount; i++)
    {
        // z축 방향으로 상승하며 배치, X와 Y는 랜덤 오프셋
        FVector SpawnLocation = FVector(FMath::RandRange(-600.f, 600.f), FMath::RandRange(-600.f, 600.f), i * SpawnSpace);

        // 50:50 확률로 스폰할 클래스 결정
        TSubclassOf<AActor> SelectedClass = (FMath::RandBool()) ? MovingTileClass : RotationTileClass;

        if (SelectedClass)
        {
            GetWorld()->SpawnActor<AActor>(SelectedClass, SpawnLocation, FRotator::ZeroRotator);
        }
    }
}