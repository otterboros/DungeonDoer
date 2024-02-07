// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"

#include "Engine/World.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UGrabber::Grab()
{
	FVector Start = GetComponentLocation();
	FVector End = Start + MaxGrabberDistance * GetForwardVector();

	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);
	FHitResult HitResult;
	bool HasHit = GetWorld()->SweepSingleByChannel(
		HitResult, 
		Start, 
		End, 
		FQuat::Identity, 
		ECC_GameTraceChannel2, 
		Sphere);

	if(HasHit)
	{
		DrawDebugLine(GetWorld(), Start, End, FColor::Green);
		UE_LOG(LogTemp, Display, TEXT("You have hit %s"), *HitResult.GetActor()->GetActorNameOrLabel());
	}
	else
	{
		DrawDebugLine(GetWorld(), Start, End, FColor::Red);
		UE_LOG(LogTemp, Display, TEXT("Nothing hit."));
	}

}

void UGrabber::Release()
{
	UE_LOG(LogTemp, Display, TEXT("Grab completed."));
}
