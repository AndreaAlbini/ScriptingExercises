// Fill out your copyright notice in the Description page of Project Settings.


#include "Shop.h"

#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ScriptingExercises/ScriptingExercisesCharacter.h"


// Sets default values
AShop::AShop()
{
	DefaultRoot = CreateDefaultSubobject<USceneComponent>("Default Root");
	RootComponent = DefaultRoot;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>("Box Collision");
	BoxCollision->SetupAttachment(DefaultRoot);
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AShop::EnablePlayerInput);
	BoxCollision->OnComponentEndOverlap.AddDynamic(this, &AShop::DisablePlayerInput);

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}


// Called when the game starts or when spawned
void AShop::BeginPlay()
{
	Super::BeginPlay();

	AScriptingExercisesCharacter* Player = Cast<AScriptingExercisesCharacter>(
		UGameplayStatics::GetPlayerCharacter(this, 0));
	if (Player)
	{
		Player->OnTotalCoinsEnough.AddDynamic(this, &AShop::OnCoinEnoughLogger);
	}
}

void AShop::ChangeItemUp()
{
	ItemIndex++;
	ItemIndex = ItemIndex%Items.Num();
	CurrentObjectCost = Items[ItemIndex].Cost;
	OnChangeItem();
}

void AShop::ChangeItemDown()
{
	ItemIndex--;
	if(ItemIndex<0)
	{
		ItemIndex = Items.Num()-1;
	}
	CurrentObjectCost = Items[ItemIndex].Cost;
	OnChangeItem();
}

// Called every frame
void AShop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AShop::EnablePlayerInput(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                              UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                              const FHitResult& SweepResult)
{
	if (Cast<AScriptingExercisesCharacter>(OtherActor))
	{
		EnableInput(UGameplayStatics::GetPlayerController(this, 0));
	}
}

void AShop::DisablePlayerInput(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (Cast<AScriptingExercisesCharacter>(OtherActor))
	{
		DisableInput(UGameplayStatics::GetPlayerController(this, 0));
	}
}

void AShop::OnCoinEnoughLogger(int32 TotalCoins)
{
	if (TotalCoins >= CurrentObjectCost)
	{
		if (GEngine)
		{
			const FString DebugMessage = "Player has enough coins to buy key";
			GEngine->AddOnScreenDebugMessage(3, 5, FColor::Purple, DebugMessage);
		}
	}
}

void AShop::ShopObject(int32 TotalCoins)
{
	if (TotalCoins >= CurrentObjectCost)
	{
		if (GEngine)
		{
			const FString DebugMessage = "Key bought";
			GEngine->AddOnScreenDebugMessage(4, 5, FColor::Purple, DebugMessage);
		}
		Cast<AScriptingExercisesCharacter>(UGameplayStatics::GetPlayerCharacter(this,0))->RemoveCoin(CurrentObjectCost);
		OnObjectCollected();
	}
}
