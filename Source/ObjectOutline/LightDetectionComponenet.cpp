// Fill out your copyright notice in the Description page of Project Settings.

#include "ObjectOutline.h"
#include "LightDetectionComponenet.h"


// Sets default values for this component's properties
ULightDetectionComponenet::ULightDetectionComponenet()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsInitializeComponent = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULightDetectionComponenet::InitializeComponent()
{
	Super::InitializeComponent();

	// ...
	
}


// Called every frame
void ULightDetectionComponenet::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}



bool ULightDetectionComponenet::GetLightingCondition(UCapsuleComponent * capsule)
{
	// Define a variable for the final result to be stored in,
	bool bLit = false;

	float averageLight = 0;
	int32 lightsFound = 0;

	// Loop through all lights,
	for (TObjectIterator<ULightComponent> Itr; Itr; ++Itr)
	{
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
		// If a line trace test from the light's position to the character's position does not hit any actor
		if (GetOwner()->GetWorld()->LineTraceTest(Itr->GetComponentLocation(), GetOwner()->GetActorLocation(), ECC_Visibility, FCollisionQueryParams(NAME_None, true, Itr->GetOwner())))
			continue;

		lightsFound += 1;

		switch (Itr->GetLightType())
		{
			case ELightComponentType::LightType_Directional:
			{
				UDirectionalLightComponent* directionalLight = Cast<UDirectionalLightComponent>(*Itr);

				averageLight += directionalLight->Intensity ;

				break;
			}

			case ELightComponentType::LightType_Point:
			{
				UPointLightComponent* pointLight = Cast<UPointLightComponent>(*Itr);

				float wattage = pointLight->Intensity ;
				float distance = FVector::Dist(GetOwner()->GetActorLocation(), Itr->GetComponentLocation()) / 100;
				float surfaceArea = 4 * PI * FMath::Square(distance);
				float light = FMath::Clamp<float>(wattage / surfaceArea, 0, 1);

				averageLight += light;

				break;
			}

			case ELightComponentType::LightType_Spot:
			{
				USpotLightComponent* spotLight = Cast<USpotLightComponent>(*Itr);

				float wattage = spotLight->Intensity;
				float distance = FVector::Dist(GetOwner()->GetActorLocation(), Itr->GetComponentLocation()) / 1000;
				float slantLength = FMath::Sqrt(FMath::Square(spotLight->AttenuationRadius) + FMath::Square(spotLight->AttenuationRadius));
				float surfaceArea = (PI * FMath::Square(distance)) + (PI * distance * slantLength);
				float light = FMath::Clamp<float>(wattage / surfaceArea, 0, 1);
				averageLight += light;
				break;
			}
		}
		// Draw a Debug Line to show how the light is hitting the character
		DrawDebugLine(GetOwner()->GetWorld(), Itr->GetComponentLocation(), GetOwner()->GetActorLocation(), FColor::Yellow);
		bLit = true;
	}

	// Average,
	averageLight /= lightsFound;

	// Round average light to nearest tenth,
	if (averageLight != 0.0f)
	{
		averageLight = FMath::FloorToFloat(averageLight * 100 + 0.5f) / 100;
	}
	GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::White, FString::SanitizeFloat(averageLight));

	// Return final result.
	return bLit;
}