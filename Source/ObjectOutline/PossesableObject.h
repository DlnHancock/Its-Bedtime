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
	float mWeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = ItemPossession)
	float mMaliceMoveCost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = ItemPossession)
	float mMaliceLevitateCost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,meta=(AllowPrivateAccess = "true"), Category=ItemPossession)
	float mFearCoeficient;					   
	UPROPERTY(EditAnywhere, BlueprintReadWrite,meta=(AllowPrivateAccess = "true"), Category=ItemPossession)
	float mTKSpeed;							  
	UPROPERTY(EditAnywhere, BlueprintReadWrite,meta=(AllowPrivateAccess = "true"), Category=ItemPossession)
	float mLevitationSpeed;					  
	UPROPERTY(EditAnywhere, BlueprintReadWrite,meta=(AllowPrivateAccess = "true"), Category=ItemPossession)
	bool mMovable;							
	UPROPERTY(EditAnywhere, BlueprintReadWrite,meta=(AllowPrivateAccess = "true"), Category=ItemPossession)
	bool mLevitatable;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = ItemPossession)
	FLinearColor mColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,meta=(AllowPrivateAccess = "true"), Category=ItemPossession)
	TArray<FString> mActions;
	
};
