// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <vector>
#include "Components/ActorComponent.h"
#include "PossesableObject.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OBJECTOUTLINE_API UPossesableObject : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPossesableObject();

	// Called when the game starts
	virtual void InitializeComponent() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;



public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite,meta=(AllowPrivateAccess = "true"), Category=ItemPossession)
	float Weight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = ItemPossession)
	float MaliceMoveCost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = ItemPossession)
	float MaliceLevitateCost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,meta=(AllowPrivateAccess = "true"), Category=ItemPossession)
	float FearCoeficient;					   
	UPROPERTY(EditAnywhere, BlueprintReadWrite,meta=(AllowPrivateAccess = "true"), Category=ItemPossession)
	float TKSpeed;							  
	UPROPERTY(EditAnywhere, BlueprintReadWrite,meta=(AllowPrivateAccess = "true"), Category=ItemPossession)
	float LevitationSpeed;					  
	UPROPERTY(EditAnywhere, BlueprintReadWrite,meta=(AllowPrivateAccess = "true"), Category=ItemPossession)
	bool Movable;							
	UPROPERTY(EditAnywhere, BlueprintReadWrite,meta=(AllowPrivateAccess = "true"), Category=ItemPossession)
	bool Levitatable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = ItemPossession)
	bool Possessable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = ItemPossession)
	FLinearColor OutlineColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,meta=(AllowPrivateAccess = "true"), Category=ItemPossession)
	TArray<FString> Actions;
	
};
