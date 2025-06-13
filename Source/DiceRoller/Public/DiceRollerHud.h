// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "DiceRollerHud.generated.h"

/**
 * 
 */
UCLASS()
class DICEROLLER_API ADiceRollerHud : public AHUD
{
	GENERATED_BODY()
	
	virtual void BeginPlay() override;
};
