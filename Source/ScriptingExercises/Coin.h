// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Coin.generated.h"

class UBoxComponent;

UCLASS()
class SCRIPTINGEXERCISES_API ACoin : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere,Category="Coins Collection")
	USceneComponent* DefaultRoot;

	UPROPERTY(VisibleAnywhere,Category="Coins Collection")
	UStaticMeshComponent* CoinMesh;

	UPROPERTY(VisibleAnywhere,Category="Coins Collection")
	UBoxComponent* BoxCollision;
	
protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Coins Collection")
	int32 CoinValue;
	
	// Sets default values for this actor's properties
	ACoin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable)
	void OnCoinBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

};
