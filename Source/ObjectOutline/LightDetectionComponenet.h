// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SceneComponent.h"
#include "LightDetectionComponenet.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OBJECTOUTLINE_API ULightDetectionComponenet : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULightDetectionComponenet();

	// Called when the game starts
	virtual void InitializeComponent() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	UFUNCTION(BlueprintPure, Category = Light)
	bool GetLightingCondition(UCapsuleComponent * capsule);
	//void HandleLightDetection();

	bool mIsInLight;
	
};
