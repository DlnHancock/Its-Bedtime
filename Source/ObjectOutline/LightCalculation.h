// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "LightCalculation.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OBJECTOUTLINE_API ULightCalculation : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULightCalculation();

	// Called when the game starts
	virtual void InitializeComponent() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

		
	UFUNCTION(BlueprintPure, Category = Light)
	bool GetLightingCondition(UCapsuleComponent * capsule);
	//void HandleLightDetection();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Light)
	bool mIsInLight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Light)
	float mAverageLight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Light)
	int32 mLightsFound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Light)
	float mTotalLight;
};
