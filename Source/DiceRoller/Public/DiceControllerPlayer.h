// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Dice.h"
#include "DiceStatics.h"
#include "InputActionValue.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "DiceControllerPlayer.generated.h"

enum class EDiceType : uint8;
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
#pragma region BP_REFERENCES
	UPROPERTY(EditAnywhere)
	TSubclassOf<ADice> D6BP;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ADice> D20BP;
	UPROPERTY()
	UCameraComponent* camComp;

#pragma endregion
public:
	bool IsRoundStarted;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<TSubclassOf<ADice>> DiceScheme;
public:
	ADiceControllerPlayer();

protected:
	UFUNCTION(BlueprintCallable)
	void TriggerCurrentDices(const FInputActionValue& InputActionValue);
	UFUNCTION()
	void DeckApplied();
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

public:
	UFUNCTION(BlueprintCallable)
	int32 GetSumValue()
	{
		int32 sum = 0;
		for (TWeakObjectPtr<ADice> dice : CurrentDices)
		{
			checkf(dice.IsValid(), TEXT("Dice is invalid. Error at %s"),TEXT(__FILE__));
			sum+=dice->EvaluateScore();
		}
		return sum;
	}
	UFUNCTION(BlueprintCallable)
	void AddDiceToScheme(EDiceType dType);
	UFUNCTION(BlueprintCallable)
	void RemoveDiceFromScheme(EDiceType dType);
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
	TSubclassOf<ADice> GetDiceClass(EDiceType dType)
	{
		switch (dType)
		{
		case EDiceType::D6 :
			return D6BP;
		case EDiceType::D20 :
			return D20BP;
		}
		return TSubclassOf<ADice>();
	}
};
