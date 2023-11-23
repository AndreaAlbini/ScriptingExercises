// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorTrigger.generated.h"


class ADoor;
class UBoxComponent;

UCLASS()
class SCRIPTINGEXERCISES_API ADoorTrigger : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere,Category="Door")
	USceneComponent* DefaultRoot;

	UPROPERTY(VisibleAnywhere,Category="Door")
	UBoxComponent* BoxCollision;

	UPROPERTY(EditAnywhere)
	ADoor* Door; 
	
public:	
	// Sets default values for this actor's properties
	ADoorTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void OnDoorTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

};
