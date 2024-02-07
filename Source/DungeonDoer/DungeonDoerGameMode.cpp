// Copyright Epic Games, Inc. All Rights Reserved.

#include "DungeonDoerGameMode.h"
#include "DungeonDoerCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADungeonDoerGameMode::ADungeonDoerGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
