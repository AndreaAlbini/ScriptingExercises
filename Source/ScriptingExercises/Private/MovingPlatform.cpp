// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	DefaultRoot = CreateDefaultSubobject<USceneComponent>("Default Root");
	RootComponent = DefaultRoot;

	PointA = CreateDefaultSubobject<USceneComponent>("Point A");
	PointA->SetupAttachment(DefaultRoot);

	PointB = CreateDefaultSubobject<USceneComponent>("Point B");
	PointB->SetupAttachment(DefaultRoot);

	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>("Platform Mesh");
	PlatformMesh->SetupAttachment(DefaultRoot);
	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float time = UGameplayStatics::GetTimeSeconds(GetWorld());
	PlatformMesh->SetRelativeLocation(FMath::Lerp(PointA->GetRelativeLocation(),PointB->GetRelativeLocation(),FMath::Sin(time)));
}

