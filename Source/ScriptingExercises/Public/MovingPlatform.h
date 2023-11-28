// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "MovingPlatform.generated.h"

UCLASS()
class SCRIPTINGEXERCISES_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, Category = "Moving Platform")
	USceneComponent* DefaultRoot;

	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	USceneComponent* PointA;
	
	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	USceneComponent* PointB;

	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	UStaticMeshComponent* PlatformMesh;
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
