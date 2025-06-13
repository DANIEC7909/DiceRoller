// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DiceStatics.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "DiceCreatorButton.generated.h"


class ADiceControllerPlayer;

UCLASS()
class DICEROLLER_API UDiceCreatorButton : public UUserWidget
{
	GENERATED_BODY()
	private:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	UFUNCTION()
	void ButtonClicked();
public:
	UFUNCTION(BlueprintCallable)
	void Build(EDiceType dType, ADiceControllerPlayer* _player);
	
private:
	UPROPERTY(EditAnywhere)
	TWeakObjectPtr<ADiceControllerPlayer> player;
	UPROPERTY(EditAnywhere,meta=(BindWidgetOptional))
	UButton* butt;
public:
	
	UPROPERTY(EditAnywhere)
	EDiceType DiceType;
};
