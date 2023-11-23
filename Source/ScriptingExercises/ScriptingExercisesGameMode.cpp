// Copyright Epic Games, Inc. All Rights Reserved.

#include "ScriptingExercisesGameMode.h"
#include "ScriptingExercisesCharacter.h"
#include "UObject/ConstructorHelpers.h"

AScriptingExercisesGameMode::AScriptingExercisesGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
