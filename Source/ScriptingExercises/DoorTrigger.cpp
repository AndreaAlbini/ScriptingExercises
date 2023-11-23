// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorTrigger.h"

#include "Door.h"
#include "Components/BoxComponent.h"
#include "ScriptingExercisesCharacter.h"

// Sets default values
ADoorTrigger::ADoorTrigger()
{
	DefaultRoot = CreateDefaultSubobject<USceneComponent>("Default Root");
	RootComponent = DefaultRoot;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>("Box Collision");
	BoxCollision->SetupAttachment(DefaultRoot);
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ADoorTrigger::OnDoorTriggerBeginOverlap);
	
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADoorTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoorTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoorTrigger::OnDoorTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AScriptingExercisesCharacter* PlayerCharacter = Cast<AScriptingExercisesCharacter>(OtherActor);
	
	if(PlayerCharacter && PlayerCharacter->TotalCoins>=Door->CoinsToOpenDoor)
	{
		Door->OpenDoorCoins();
	}
	else
	{
		if(GEngine)
		{
			const FString DebugMessage = "Character needs "+ FString::FromInt(PlayerCharacter->TotalCoins) + " coins";
			GEngine->AddOnScreenDebugMessage(2,5.0,FColor::Purple,DebugMessage);
		}
	}
}

