// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "RecordWidget.generated.h"

/**
 * 
 */
UCLASS()
class URecordWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,meta=(BindWidgetOptional))
	UTextBlock* Order;
	UPROPERTY(EditAnywhere,meta=(BindWidgetOptional))
	UTextBlock* Value;
};
