// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScriptingExercises/ItemInfo.h"
#include "Shop.generated.h"

class UBoxComponent;


UCLASS()
class AShop : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category="Shop")
	USceneComponent* DefaultRoot;

	UPROPERTY(VisibleAnywhere, Category="Shop")
	UBoxComponent* BoxCollision;
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Shop")
	int32 CurrentObjectCost;

public:
	UFUNCTION()
	void EnablePlayerInput(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                       int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void DisablePlayerInput(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	                        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION(BlueprintImplementableEvent)
	void OnObjectCollected();
	// Sets default values for this actor's properties
	AShop();

protected:
	UFUNCTION()
	void OnCoinEnoughLogger(int32 TotalCoins);

	UFUNCTION(BlueprintCallable)
	void ShopObject(int32 TotalCoins);
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Shop")
	TArray<FCCItemInfo> Items;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Shop")
	int32 ItemIndex;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="Shop")
	float CurrentItemScale;
	
	UFUNCTION(BlueprintCallable)
	void ChangeItemUp();

	UFUNCTION(BlueprintCallable)
	void ChangeItemDown();
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnChangeItem();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
