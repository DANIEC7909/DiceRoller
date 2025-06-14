// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/DiceCreatorButton.h"

#include "DiceControllerPlayer.h"

void UDiceCreatorButton::NativeConstruct()
{
	Super::NativeConstruct();
	if (IsValid(butt))
	{
		butt->OnClicked.AddDynamic(this,&UDiceCreatorButton::ButtonClicked);
	}
}

void UDiceCreatorButton::NativeDestruct()
{
	Super::NativeDestruct();
	if (IsValid(butt))
	{
		butt->OnClicked.RemoveDynamic(this,&UDiceCreatorButton::ButtonClicked);
	}
}

void UDiceCreatorButton::ButtonClicked()
{
	if (player.IsValid())
	{
		player->RemoveDiceFromScheme(DiceType);
	}
	RemoveFromParent();
}

void UDiceCreatorButton::Build(EDiceType dType, ADiceControllerPlayer* _player)
{
	DiceType = dType;
	player = _player;
}
