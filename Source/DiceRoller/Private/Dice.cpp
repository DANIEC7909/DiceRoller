// Fill out your copyright notice in the Description page of Project Settings.


#include "Dice.h"

#include "DiceController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "DetectionPoint.h"
#include "Chaos/Utilities.h"
#include "Kismet/GameplayStatics.h"
#include "Logging/StructuredLog.h"

void ADice::AddImpuls()
{
	GetStaticMeshComponent()->AddImpulse(FVector(0, 0, 1000),NAME_None,true);
	GetStaticMeshComponent()->AddTorqueInDegrees(FVector(rand(),rand(),rand())*100000);

}

void ADice::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	for (TObjectPtr<UActorComponent> component : GetComponents())
	{
		if (UDetectionPoint* dp = Cast<UDetectionPoint>(component))
		{
			Components.Add(dp);
		}
	}
}
int32 ADice::EvaluateScore()
{
	float dot = FLT_MAX;
	TWeakObjectPtr<UDetectionPoint> detPoint; 
	for (TWeakObjectPtr<UDetectionPoint> dp : Components)
	{
		if (dp.IsValid())
		{
			float f=FVector::DotProduct(dp->GetUpVector(),FVector::UpVector);
		
			if ( dot>f && (f>DETECTION_TRESHOLD))
			{
				dot = f;
				detPoint = dp;
			}
		//	UE_LOGFMT(LogTemp,Display,"{0}<=|=>{1}",f,dp->GetValue());
		}
	}
		if (detPoint.IsValid())
			UE_LOGFMT(LogTemp,Display,"dot is:{0} dNum is:{1}",dot,detPoint->GetValue());
	return 0;
}

ADice::ADice()
{
	GetStaticMeshComponent()->SetSimulatePhysics(true);
}
void ADice::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ADice::BeginPlay()
{
	Super::BeginPlay();
}


