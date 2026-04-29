// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SprintArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SprintArm"));
	SprintArm->SetupAttachment(RootComponent); // 스프링 암 루트 컴포넌트에 붙이기

	SprintArm->TargetArmLength = 300.0f; // 카메라와 캐릭터 사이의 거리 설정
	SprintArm->bUsePawnControlRotation = true; // 캐릭터의 회전에 따라 카메라가 회전하도록 설정

	SprintCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("SprintCamera"));
	SprintCamera->SetupAttachment(SprintArm, USpringArmComponent::SocketName); // 카메라를 스프링 암에 붙이기

	SprintCamera->bUsePawnControlRotation = false; // 카메라가 스프링 암의 회전을 따르도록 설정
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

