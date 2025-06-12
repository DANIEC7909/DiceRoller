// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "DetectionPoint.generated.h"


UCLASS( ClassGroup=(DiceDetection), meta=(BlueprintSpawnableComponent) )
class DICEROLLER_API UDetectionPoint : public USceneComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	int32 Value;
public:	
	UDetectionPoint();
	FORCEINLINE int32 GetValue(){return Value;}
protected:
virtual void BeginPlay() override;
	
};
