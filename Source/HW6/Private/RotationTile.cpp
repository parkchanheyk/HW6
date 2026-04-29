// Fill out your copyright notice in the Description page of Project Settings.

#include "RotationTile.h"

DEFINE_LOG_CATEGORY(LogRotationTile);

// Sets default values
ARotationTile::ARotationTile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot")); // 루트 컴포넌트 생성
	SetRootComponent(SceneRoot); // 씬 루트로 지정

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh")); // 스태틱 매시 생성
	StaticMeshComp->SetupAttachment(SceneRoot); // 스태틱 메시를 씬 루트에 붙이는 함수

	// UPROPERTY로 설정해서 스태틱 메시, 머테리얼을 블루프린트 에디터에서 설정할 수 있음
}

// Called when the game starts or when spawned
void ARotationTile::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("RotationTile BeginPlay"));
	UE_LOG(LogRotationTile, Error, TEXT("RotationTile BeginPlay"));
	RotationSpeed = FMath::RandRange(-200.0f, 200.0f); // 랜덤한 회전 속도 설정

	// 최솟값 보정
	if (FMath::Abs(RotationSpeed) < 50.0f) RotationSpeed += 100.0f;
}

// Called every frame
void ARotationTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, DeltaTime * RotationSpeed, 0.0f)); // y, z ,x 축 회전 
	}
}

void ARotationTile::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void ARotationTile::Destroyed()
{
	Super::Destroyed();
}

void ARotationTile::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}