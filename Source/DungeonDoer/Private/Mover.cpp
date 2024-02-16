// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover.h"

#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();

	StartingLocation = GetOwner()->GetActorLocation();
	StartingRotation = GetOwner()->GetActorRotation();
}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector TargetLocation = StartingLocation;
	FRotator TargetRotation = StartingRotation;

	if(ShouldMove)
	{
		TargetLocation = StartingLocation + MoveOffset;
		TargetRotation = StartingRotation + RotationOffset;
	}
	FVector CurrentLocation = GetOwner()->GetActorLocation();
	float MoveSpeed = MoveOffset.Length() / MoveTime;
	FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, MoveSpeed);
	GetOwner()->SetActorLocation(NewLocation);

	FRotator CurrentRotation = GetOwner()->GetActorRotation();
	float RotationSpeed = StartingRotation.GetManhattanDistance(TargetRotation) / RotationTime;
	FRotator NewRotation = FMath::RInterpTo(CurrentRotation, TargetRotation, DeltaTime, RotationSpeed);
	GetOwner()->SetActorRotation(NewRotation);

	// else
	// {
	// 	FVector CurrentLocation = GetOwner()->GetActorLocation();
	// 	FVector TargetLocation = StartingLocation;
	// 	float MoveSpeed = FVector::Distance(CurrentLocation,TargetLocation) / MoveTime;

	// 	FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, MoveSpeed);
	// 	GetOwner()->SetActorLocation(NewLocation);

	// 	FRotator CurrentRotation = GetOwner()->GetActorRotation();
	// 	FRotator TargetRotation = StartingRotation;

	// 	float RotationSpeed = StartingRotation.GetManhattanDistance(TargetRotation) / RotationTime;
	// 	FRotator NewRotation = FMath::RInterpTo(CurrentRotation, TargetRotation, DeltaTime, RotationSpeed);
	// 	GetOwner()->SetActorRotation(NewRotation);
	// }
}

void UMover::SetShouldMove(bool NewShouldMove)
{
    ShouldMove = NewShouldMove;
}

void UMover::SetShouldRotate(bool NewShouldRotate)
{
    ShouldRotate = NewShouldRotate;
}