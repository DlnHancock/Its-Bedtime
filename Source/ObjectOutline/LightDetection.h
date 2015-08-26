// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "LightDetection.generated.h"

UCLASS()
class OBJECTOUTLINE_API ALightDetection : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALightDetection();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = :"Light Calculation")
	bool GetLightingCondition();
	//void HandleLightDetection();

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ObjectInLight)
	bool bIsInLight;
	
};
