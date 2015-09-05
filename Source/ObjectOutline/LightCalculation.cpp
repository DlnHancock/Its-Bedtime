// Fill out your copyright notice in the Description page of Project Settings.

#include "ObjectOutline.h"
#include "LightCalculation.h"


// Sets default values for this component's properties
ULightCalculation::ULightCalculation()
:mLightsFound(0)
, mAverageLight(0.0f)
, mTotalLight(0.0f)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsInitializeComponent = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULightCalculation::InitializeComponent()
{
	Super::InitializeComponent();

	// ...
	
}


// Called every frame
void ULightCalculation::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	
	// ...
}


bool ULightCalculation::GetLightingCondition(UCapsuleComponent * capsule)
{
	// Define a variable for the final result to be stored in,
	bool bLit = false;

	mLightsFound = 0;
	mAverageLight = 0;
	// Loop through all lights,
	for (TObjectIterator<ULightComponent> Itr; Itr; ++Itr)
	{
		ELightComponentType type = Itr->GetLightType();

		if (!IsValid(Itr->GetOwner()))
			continue;
		// If this light is not a default object,
		if (Itr->GetOwner()->HasAnyFlags(RF_ClassDefaultObject))
			continue;
		// If this light is enabled (or visible),
		if (!Itr->IsVisible())
			continue;
		if (!Itr->AffectsPrimitive(capsule))
			continue;

		const FName TraceTag("MyTraceTag");
		FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true);
		RV_TraceParams.bTraceComplex = false;
		RV_TraceParams.bTraceAsyncScene = true;
		RV_TraceParams.bReturnPhysicalMaterial = false;
		RV_TraceParams.AddIgnoredActor(GetOwner());
		RV_TraceParams.TraceTag = TraceTag;
		 //Re-initialize hit info
		 FHitResult RV_Hit(ForceInit);

		// If a line trace test from the light's position to the character's position does not hit any actor
		 
		GetWorld()->LineTraceSingle( RV_Hit,  Itr->GetComponentLocation(),  GetOwner()->GetActorLocation(),  ECC_Visibility, RV_TraceParams);

		if (RV_Hit.bBlockingHit)
			continue;

		mLightsFound += 1;

		switch (Itr->GetLightType())
		{
			case ELightComponentType::LightType_Directional:
			{
				UDirectionalLightComponent* directionalLight = Cast<UDirectionalLightComponent>(*Itr);

				mAverageLight += directionalLight->Intensity ;

				break;
			}

			case ELightComponentType::LightType_Point:
			{
				UPointLightComponent* pointLight = Cast<UPointLightComponent>(*Itr);

				float wattage = pointLight->Intensity ;
				float distance = FVector::Dist(GetOwner()->GetActorLocation(), Itr->GetComponentLocation()) / 100;
				float surfaceArea = 4 * PI * FMath::Square(distance);
				float light = wattage / surfaceArea;

				mAverageLight += light;

				break;
			}

			case ELightComponentType::LightType_Spot:
			{
				USpotLightComponent* spotLight = Cast<USpotLightComponent>(*Itr);

				float wattage = spotLight->Intensity;
				float distance = FVector::Dist(GetOwner()->GetActorLocation(), Itr->GetComponentLocation()) / 1000;
				float slantLength = FMath::Sqrt(FMath::Square(spotLight->AttenuationRadius) + FMath::Square(spotLight->AttenuationRadius));
				float surfaceArea = (PI * FMath::Square(distance)) + (PI * distance * slantLength);
				float light = wattage / surfaceArea;
				mAverageLight += light;
				break;
			}
		}
		// Draw a Debug Line to show how the light is hitting the character
		DrawDebugLine(GetOwner()->GetWorld(), Itr->GetComponentLocation(), GetOwner()->GetActorLocation(), FColor::White, false, -1, 0, 2);
		bLit = true;
	}

	// Average,
	mTotalLight = mAverageLight;
	mAverageLight /= mLightsFound;

	
	GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::White,"numberOfLights: " + FString::SanitizeFloat(mLightsFound) + "totalLight: " + FString::SanitizeFloat(mTotalLight) + " averageLight: " + FString::SanitizeFloat(mAverageLight) );

	// Return final result.
	return bLit;
}