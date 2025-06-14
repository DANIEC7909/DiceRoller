// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DiceStatics.h"
#include "Blueprint/UserWidget.h"
#include "DiceSelectionWidget.generated.h"

class UDiceStatics;
class UDiceGameInstance;
enum class EDiceType : uint8;
/**
 * 
 */
UCLASS()
class DICEROLLER_API UDiceSelectionWidget : public UUserWidget
{
	GENERATED_BODY()
	virtual void NativeConstruct() override;
public:
	UFUNCTION(BlueprintCallable)
	void AddDice(EDiceType dType);
	UFUNCTION(BlueprintCallable)
	void RemoveDice(EDiceType dType);
	UFUNCTION(BlueprintCallable)
	void SendApplyEvent(){UDiceStatics::OnApplyDiceDeck.Broadcast();};
private:
	UDiceGameInstance* dGInst;
	
};
