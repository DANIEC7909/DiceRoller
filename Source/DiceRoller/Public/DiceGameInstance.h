// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DiceGameInstance.generated.h"

class ADiceControllerPlayer;
/**
 * 
 */
UCLASS()
class DICEROLLER_API UDiceGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	TWeakObjectPtr<ADiceControllerPlayer> Player;
	
	
};
