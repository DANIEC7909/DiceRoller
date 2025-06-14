// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/VerticalBox.h"
#include "UI/RecordWidget.h"
#include "GameplayHud.generated.h"

/**
 * 
 */
UCLASS()
class DICEROLLER_API UGameplayHud : public UUserWidget
{
	GENERATED_BODY()
private:
	int32 mainOrder;
private:
	UFUNCTION()
	void RoundEnded();
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
public:
	UPROPERTY(EditAnywhere,meta=(BindWidgetOptional))
	UVerticalBox* RecordsVBox;
	UPROPERTY(EditAnywhere)
	TSubclassOf<URecordWidget> RecordWidget;
public:
	void AddRecordOnTheTop(int32 order, int32 value);
	
};
