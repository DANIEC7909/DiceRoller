// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DiceStatics.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FApplyDiceDeck);

UENUM(BlueprintType)
enum class EDiceType:uint8
{
	D6,
	D20
};
UCLASS()
class DICEROLLER_API UDiceStatics : public UObject
{
	GENERATED_BODY()
public:
	static FApplyDiceDeck OnApplyDiceDeck;
};
