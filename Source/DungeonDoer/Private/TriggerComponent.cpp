// Fill out your copyright notice in the Description page of Project Settings.

#include "TriggerComponent.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"


// Sets default values for this component's properties
UTriggerComponent::UTriggerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
// Try using delegates/event-based coding. OnComponentOverlapBegin/End
// This way I don't need to put this in tick.
void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (AActor* UnlockActor = GetUnlockActor())
    {
        if (UPrimitiveComponent* UnlockComponent = Cast<UPrimitiveComponent>(UnlockActor->GetRootComponent()))
        {
            UnlockComponent->SetSimulatePhysics(false);
        }
        UnlockActor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);

        for (UMover* Mover : Movers)
        {
            Mover->SetShouldMove(true);
            Mover->SetShouldRotate(true);
            IsCurrentlyTriggered = true;
        }
        
    }
    else
    {
        for (UMover* Mover : Movers)
            {
                Mover->SetShouldMove(false);
                Mover->SetShouldRotate(false);
                IsCurrentlyTriggered = false;
            }
    }
}


AActor* UTriggerComponent::GetUnlockActor() const
{
    TArray<AActor*> Actors;
    GetOverlappingActors(Actors);

    for (AActor* Actor : Actors)
    {
        // If actor has UnlockTag and is not Grabbed or is the key (which activates instantly)
        if(Actor->ActorHasTag(UnlockTag) && (!Actor->ActorHasTag("Grabbed") || Actor->ActorHasTag("Unlock_Key")))
        {
            return Actor;
        }
    }

    return nullptr;
}

void UTriggerComponent::SetMover(UMover* NewMover)
{
    Movers.Add(NewMover);
}

bool UTriggerComponent::GetTrigger()
{
    return IsCurrentlyTriggered;
}