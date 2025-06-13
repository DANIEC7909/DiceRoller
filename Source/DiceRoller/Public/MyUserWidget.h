// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class DICEROLLER_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite,meta=(BindWidgetOptional))
	UTextBlock* Text;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,meta=(BindWidgetAnim),Transient)
	UWidgetAnimation* Animation;
	bool bShown = true;
public:
	UFUNCTION(BlueprintCallable)
	void HideTEXT();
	UFUNCTION(BlueprintCallable)
	void ShowTEXT(int32 Score);
};
