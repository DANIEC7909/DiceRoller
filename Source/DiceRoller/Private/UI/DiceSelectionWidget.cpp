// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/DiceSelectionWidget.h"

#include "DiceControllerPlayer.h"
#include "DiceGameInstance.h"

void UDiceSelectionWidget::NativeConstruct()
{
	Super::NativeConstruct();
	dGInst =Cast<UDiceGameInstance>(GetGameInstance());
}

void UDiceSelectionWidget::AddDice(EDiceType dType)
{
	if (dGInst)
	{
		if (dGInst->Player.IsValid())
		{
			dGInst->Player->AddDiceToScheme(dType);
		}
	}
}
void UDiceSelectionWidget::RemoveDice(EDiceType dType)
{
	if (dGInst)
	{
		if (dGInst->Player.IsValid())
		{
			dGInst->Player->RemoveDiceFromScheme(dType);
		}
	}
}