// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin.h"

#include "ScriptingExercisesCharacter.h"
#include "Components/BoxComponent.h"

// Sets default values
ACoin::ACoin()
{
	DefaultRoot = CreateDefaultSubobject<USceneComponent>("Default Root");
	RootComponent = DefaultRoot;

	CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>("Coin Mesh");
	CoinMesh->SetupAttachment(DefaultRoot);
	CoinMesh->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	CoinMesh->OnComponentBeginOverlap.AddDynamic(this, &ACoin::ACoin::OnCoinBeginOverlap);

	//BoxCollision = CreateDefaultSubobject<UBoxComponent>("Box Collision");
	//BoxCollision->SetupAttachment(DefaultRoot);
	//BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ACoin::OnCoinBeginOverlap);
	
	CoinValue=0;
	
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACoin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACoin::OnCoinBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AScriptingExercisesCharacter* PlayerCharacter = Cast<AScriptingExercisesCharacter>(OtherActor);
	if(PlayerCharacter)
	{
		PlayerCharacter->CollectCoin(CoinValue);
		Destroy();
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("It's not the player"));
	}
}

