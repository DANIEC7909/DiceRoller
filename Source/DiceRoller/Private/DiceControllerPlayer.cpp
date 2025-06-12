// Fill out your copyright notice in the Description page of Project Settings.


#include "DiceControllerPlayer.h"

#include "Dice.h"
#include "DiceController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

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

void ADiceControllerPlayer::BeginPlay()
{
	Super::BeginPlay();
	
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
}

void ADiceControllerPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	this->AddActorWorldRotation(FRotator(0,DeltaTime*10,0));
}

