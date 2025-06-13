// Fill out your copyright notice in the Description page of Project Settings.


#include "DiceControllerPlayer.h"

#include "Dice.h"
#include "DiceController.h"
#include "DiceGameInstance.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"

ADiceControllerPlayer::ADiceControllerPlayer()
{
 PrimaryActorTick.bCanEverTick = true;
}

void ADiceControllerPlayer::TriggerCurrentDices(const FInputActionValue& InputActionValue)
{
	for (TWeakObjectPtr<ADice> dice : CurrentDices)
	{
		dice->AddImpuls();
	}
}

void ADiceControllerPlayer::DeckApplied()
{
	for (TWeakObjectPtr<ADice> dice : CurrentDices)
	{
		if (dice.IsValid())
		{
			dice->Destroy();
		}
	}
	CurrentDices.Empty();
	for (TSubclassOf<ADice>diceSub:DiceScheme)
	{
		FActorSpawnParameters spawnParameters;
		spawnParameters.Owner = this;
		/*spawnParameters.*/
		CurrentDices.Add(GetWorld()->SpawnActor<ADice>(diceSub,FVector(0,0,1000),FRotator::ZeroRotator,spawnParameters));
	}
}

void ADiceControllerPlayer::BeginPlay()
{
	Super::BeginPlay();
	UDiceStatics::OnApplyDiceDeck.AddDynamic(this,&ADiceControllerPlayer::DeckApplied);
	if(ADiceController* DC = Cast<ADiceController>( GetWorld()->GetFirstPlayerController()))
	{
		EnableInput(DC);

		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(DC->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(MappingContext, 0);
		}
		if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
		{
			EnhancedInput->BindAction(InputAction, ETriggerEvent::Started, this, &ADiceControllerPlayer::TriggerCurrentDices);
		}
		/*if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
		{
			EnhancedInput->BindAction(InputActionGuess, ETriggerEvent::Started, this, &ADice::Guess);
		}*/
	}
	camComp = GetComponentByClass<UCameraComponent>();
}
void ADiceControllerPlayer::AddDiceToScheme(EDiceType dType)
{
	DiceScheme.Add(GetDiceClass(dType));
}
void ADiceControllerPlayer::RemoveDiceFromScheme(EDiceType dType)
{
	int32 id =DiceScheme.Find(GetDiceClass(dType));
	DiceScheme.RemoveAt(id);
}
void ADiceControllerPlayer::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	Cast<UDiceGameInstance>(GetGameInstance())->Player=this;
}

void ADiceControllerPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	this->AddActorWorldRotation(FRotator(0,DeltaTime*10,0));
	for (TWeakObjectPtr<ADice> dice : CurrentDices)
	{
		if (dice.IsValid())
		{
			if (dice->IsDiceSettled())
			{
				dice->EvaluateScore();
				dice->PointWidgetTowardCamera(camComp->GetComponentLocation());
			}
			else
			{
				dice->HideDiceHUD();
			}
		}
	}
}

