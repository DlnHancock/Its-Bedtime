// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "LightDetection.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class OBJECTOUTLINE_API ULightDetection : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	ULightDetection();

	// Called when the game starts
	virtual void InitializeComponent() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UFUNCTION(BlueprintCallable, Category = Lighting)
		bool GetLightingCondition(UCapsuleComponent* capsule, float & totalLight);
	//void HandleLightDetection();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ObjectInLight)
		bool bIsInLight;

};