// Fill out your copyright notice in the Description page of Project Settings.

#include "ObjectOutline.h"
#include "LightDetection.h"


// Sets default values
ALightDetection::ALightDetection()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALightDetection::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALightDetection::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

