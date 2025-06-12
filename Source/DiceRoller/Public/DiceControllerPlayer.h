// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Pawn.h"
#include "DiceControllerPlayer.generated.h"

class UInputMappingContext;
class UInputAction;
class ADice;
UCLASS()
class DICEROLLER_API ADiceControllerPlayer : public APawn
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
	UInputMappingContext* MappingContext;
	UPROPERTY(EditAnywhere)
	UInputAction* InputAction;
	UPROPERTY(EditAnywhere)
	UInputAction* InputActionGuess;
	UPROPERTY(EditAnywhere)
	TArray<TWeakObjectPtr<ADice>> CurrentDices;
public:
	ADiceControllerPlayer();

protected:
	void TriggerCurrentDices(const FInputActionValue& InputActionValue);
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
