// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinLogger.h"

#include "Kismet/GameplayStatics.h"
#include "ScriptingExercises/ScriptingExercisesCharacter.h"

// Sets default values
ACoinLogger::ACoinLogger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACoinLogger::BeginPlay()
{
	Super::BeginPlay();

	AScriptingExercisesCharacter* Player = Cast<AScriptingExercisesCharacter>(UGameplayStatics::GetPlayerCharacter(this,0));

	if(Player)
	{
		
		Player->OnCoinCollected.AddDynamic(this, &ACoinLogger::OnCoinCollectedLogger);
	}
}

// Called every frame
void ACoinLogger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACoinLogger::OnCoinCollectedLogger(int32 CoinCollectedValue)
{
	if(GEngine)
	{
		const FString DebugMessage = "Character has "+ FString::FromInt(CoinCollectedValue) + " coins";
		GEngine->AddOnScreenDebugMessage(2,5,FColor::Purple,DebugMessage);
	}
}

