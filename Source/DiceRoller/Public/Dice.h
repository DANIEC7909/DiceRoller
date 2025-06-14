// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "MyUserWidget.h"
#include "Components/WidgetComponent.h"
#include "Engine/StaticMeshActor.h"
#include "Dice.generated.h"

class UWidgetComponent;
class UDetectionPoint;

UCLASS()
class DICEROLLER_API ADice : public AStaticMeshActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UWidgetComponent* wComp;
	UPROPERTY(EditAnywhere)
	TArray<TWeakObjectPtr<UDetectionPoint>> Components;
	UPROPERTY(EditAnywhere)
	UMyUserWidget* diceHUD;
	UPROPERTY(EditAnywhere)
	float DETECTION_TRESHOLD =0.90f;
	UPROPERTY(EditAnywhere)
	float SETTLE_TRESHOLD =0.4f;

public:
	void PointWidgetTowardCamera(FVector vec)
	{
		FVector dir = (vec-wComp->GetComponentLocation()).GetSafeNormal();
		FRotator rotator = FRotationMatrix::MakeFromX(dir).Rotator();	
		wComp->SetWorldRotation(rotator);
		
	}
	void AddImpuls();
	int32 EvaluateScore();

	FORCEINLINE bool IsDiceSettled(){return GetStaticMeshComponent()->GetComponentVelocity().SizeSquared()<SETTLE_TRESHOLD/*KINDA_SMALL_NUMBER*/;}
	FORCEINLINE void HideDiceHUD(){diceHUD->HideTEXT();}
private:
	ADice();
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;
};		

