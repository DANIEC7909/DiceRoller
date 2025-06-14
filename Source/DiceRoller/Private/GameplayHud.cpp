// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayHud.h"

#include "DiceControllerPlayer.h"
#include "DiceGameInstance.h"
#include "DiceStatics.h"
#include "Components/GridSlot.h"
#include "Components/PanelWidget.h"
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

if (RecordsVBox->GetChildrenCount()>0)
{
	UGridSlot* gs =Cast<UGridSlot>(RecordsVBox->GetChildAt(0)->Slot);
	gs->SetRow(gs->Row+1);//++;
}
	RecordsVBox->AddChildToGrid(rWidg,0);
	
	for (int32 i=2;i<RecordsVBox->GetChildrenCount();i++)
	{
	UGridSlot* gs =	Cast<UGridSlot>(RecordsVBox->GetChildAt(i)->Slot);
		gs->SetRow(gs->Row+1);
	}
}
