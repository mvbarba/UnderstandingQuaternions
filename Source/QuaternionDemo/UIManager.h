// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "UIManager.generated.h"

UENUM(Meta = (Bitflags))
enum class E_UIType : uint8
{
	MainMenu UMETA(DisplayName = "MainMenu"),
	QuaternionUI UMETA(DisplayName = "QuaternionUI"),
	EulerUI UMETA(DisplayName = "EulerUI"),
	AboutUI UMETA(DisplayName = "AboutUI"),
};

USTRUCT(BlueprintType)
struct FUIElement
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	E_UIType type;

	UPROPERTY(EditAnywhere)
	AActor* actor;
};

UCLASS()
class QUATERNIONDEMO_API AUIManager : public AActor 
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUIManager();

	UPROPERTY(EditAnywhere)
	TArray<FUIElement> elems;

};
