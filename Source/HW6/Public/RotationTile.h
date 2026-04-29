// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotationTile.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogRotationTile, Log, All);

UCLASS()
class HW6_API ARotationTile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARotationTile(); // 생성자

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void PostInitializeComponents() override; // 컴포넌트 초기화가 끝난 후에 호출되는 함수

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override; // 액터가 게임에서 제거될 때 호출되는 함수, EndPlayReason는 제거되는 이유를 나타냄

	virtual void Destroyed() override; // 액터가 완전히 제거될 때 호출되는 함수, Destroyed는 액터가 제거된 후에 호출되며, EndPlay와는 달리 제거되는 이유를 알 수 없음

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tile")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float RotationSpeed=100.0f;
};
