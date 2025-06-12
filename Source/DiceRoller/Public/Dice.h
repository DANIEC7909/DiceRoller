// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "Engine/StaticMeshActor.h"
#include "Dice.generated.h"

class UDetectionPoint;

UCLASS()
class DICEROLLER_API ADice : public AStaticMeshActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<TWeakObjectPtr<UDetectionPoint>> Components;
	static constexpr float DETECTION_TRESHOLD =0.90f;

public:
	void AddImpuls();
	int32 EvaluateScore();
	FORCEINLINE bool IsDiceSettled(){return GetStaticMeshComponent()->GetComponentVelocity().SizeSquared()<0.1f/*KINDA_SMALL_NUMBER*/;}
private:
	ADice();
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;
	virtual void Tick(float DeltaTime) override;
};		

