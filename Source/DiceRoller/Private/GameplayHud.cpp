// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayHud.h"

#include "DiceControllerPlayer.h"
#include "DiceGameInstance.h"
#include "DiceStatics.h"

void UGameplayHud::RoundEnded()
{
	mainOrder++;
	AddRecordOnTheTop(mainOrder,Cast<UDiceGameInstance>(GetGameInstance())->Player->GetSumValue());
}

void UGameplayHud::NativeConstruct()
{
	Super::NativeConstruct();
	UDiceStatics::OnRoundEnded.AddDynamic(this,&UGameplayHud::RoundEnded);
}

void UGameplayHud::NativeDestruct()
{
	UDiceStatics::OnRoundEnded.RemoveDynamic(this,&UGameplayHud::RoundEnded);
	Super::NativeDestruct();
}

void UGameplayHud::AddRecordOnTheTop(int32 order, int32 value)
{
	URecordWidget* rWidg =CreateWidget<URecordWidget>(this,RecordWidget);
	rWidg->Order->SetText(FText::FromString(FString::FromInt(order)));
	rWidg->Value->SetText(FText::FromString(FString::FromInt(value)));
	RecordsVBox->AddChildToVerticalBox(rWidg);
	RecordsVBox->ShiftChild(0,rWidg);
}
