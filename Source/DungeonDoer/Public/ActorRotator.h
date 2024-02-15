// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActorRotator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUNGEONDOER_API UActorRotator : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActorRotator();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetShouldRotate(bool ShouldRotate);

private:
	UPROPERTY(EditAnywhere)
	FVector RotationOffset;

	UPROPERTY(EditAnywhere)
	float RotationTime = 4;

	UPROPERTY(EditAnywhere)
	bool ShouldRotate = false;

	FVector StartingRotation;
};
