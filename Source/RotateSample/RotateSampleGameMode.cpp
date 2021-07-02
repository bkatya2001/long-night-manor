// Copyright Epic Games, Inc. All Rights Reserved.

#include "RotateSampleGameMode.h"
#include "RotateSampleHUD.h"
#include "RotateSampleCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARotateSampleGameMode::ARotateSampleGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ARotateSampleHUD::StaticClass();
}
