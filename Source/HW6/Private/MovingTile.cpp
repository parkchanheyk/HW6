// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingTile.h"

// Sets default values
AMovingTile::AMovingTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot")); // 루트 컴포넌트 생성
	SetRootComponent(SceneRoot); // 씬 루트로 지정

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh")); // 스태틱 매시 생성
	StaticMeshComp->SetupAttachment(SceneRoot); // 스태틱 메시를 씬 루트에 붙이는 함수

	// UPROPERTY로 설정해서 스태틱 메시, 머테리얼을 블루프린트 에디터에서 설정할 수 있음

	StartLocation = FVector::ZeroVector;
	MoveSpeed = 100.0f;

}

// Called when the game starts or when spawned
void AMovingTile::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("MovingTile BeginPlay"));

	StartLocation = GetActorLocation(); // 액터의 현재 위치를 시작 위치로 설정

	GetWorld()->GetTimerManager().SetTimer(MoveTimerHandle, this, &AMovingTile::ReverseDirection, MoveDuration, true);
	// MoveDuration마다 ReverseDirection 함수를 호출하는 타이머 설정, true는 반복적으로 호출하도록 설정
}

// Called every frame
void AMovingTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalOffset(FVector(MoveSpeed * DeltaTime * MoveDirection, 0.f, 0.f));
}

void AMovingTile::ReverseDirection()
{
	MoveDirection *= -1; // 이동 방향 반전
}



void AMovingTile::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void AMovingTile::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void AMovingTile::Destroyed()
{
	Super::Destroyed();
}


