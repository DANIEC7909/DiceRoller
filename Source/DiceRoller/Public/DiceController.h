// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedPlayerInput.h"
#include "InputMappingContext.h"

#include "DiceController.generated.h"

/**
 * 
 */
UCLASS()
class DICEROLLER_API ADiceController : public APlayerController
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
	UInputMappingContext* MappingContext;
	UPROPERTY(EditAnywhere)
	UInputAction* InputAction;


};

				
