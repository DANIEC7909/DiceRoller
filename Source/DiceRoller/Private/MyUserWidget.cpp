// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"

#include "Components/TextBlock.h"

void UMyUserWidget::HideTEXT()
{
	if (bShown)
	{
		PlayAnimationReverse(Animation);
		bShown = false;
	}
}

void UMyUserWidget::ShowTEXT(int32 Score)
{
	if (!bShown)
	{
		if (IsValid(Text))
		{
			Text->SetText(FText::FromString(FString::FromInt(Score)));
			PlayAnimation(Animation);
			bShown=true;
		}
	}
}
