// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class SCRIPTINGEXERCISES_API ADoor : public AActor
{
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere,Category="Door")
	USceneComponent* DefaultRoot;

	UPROPERTY(VisibleAnywhere,Category="Door")
	UStaticMeshComponent* DoorMesh;
public:
	UPROPERTY(EditAnywhere)
	int CoinsToOpenDoor;
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OpenDoorCoins();

	UFUNCTION(BlueprintCallable)
	void UpdateDoor(float TimelineValue);

};
