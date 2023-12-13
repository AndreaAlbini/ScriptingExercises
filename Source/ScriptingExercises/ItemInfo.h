#pragma once

#include "CoreMinimal.h"
#include "ItemInfo.generated.h"

USTRUCT(BlueprintType)
struct FCCItemInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item Info")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item Info")
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item Info")
	int32 Cost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item Info")
	float ItemScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item Info")
	UStaticMesh* ItemMesh;
};
