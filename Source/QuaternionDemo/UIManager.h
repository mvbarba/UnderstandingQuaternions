// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "Blueprint/UserWidget.h"
#include "Components/SlateWrapperTypes.h"
#include "UIManager.generated.h"

UENUM()
enum class E_UIType : uint8
{
	xSprite UMETA(DisplayName = "xSprite"),
	ySprite UMETA(DisplayName = "ySprite"),
	zSprite UMETA(DisplayName = "zSprite"),
	FxSprite UMETA(DisplayName = "FxSprite"),
	FySprite UMETA(DisplayName = "FySprite"),
	FzSprite UMETA(DisplayName = "FzSprite"),
	AboutUI UMETA(DisplayName = "AboutUI"),
	MainMenu UMETA(DisplayName = "MainMenu"),
	QuaternionUI UMETA(DisplayName = "QuaternionUI"),
	EulerUI UMETA(DisplayName = "EulerUI"),
};

USTRUCT(BlueprintType)
struct QUATERNIONDEMO_API FUIElement
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere)
	E_UIType type;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> widget;
	UUserWidget* widgetInstance;
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

	UFUNCTION(BlueprintCallable)
	static AUIManager* Instance();
	void InternalOpenUI(E_UIType type);
	void InternalCloseUI(E_UIType type);
	void InternalCloseAllUI();
	UFUNCTION(BlueprintCallable)
	static void OpenUI(E_UIType type, bool closeOtherUI);
	UFUNCTION(BlueprintCallable)
	static void CloseUI(E_UIType type);
	UFUNCTION(BlueprintCallable)
	static void CloseAllUI();

protected:
	// Called when components are done initializing
	virtual void PostInitializeComponents() override;
	
private: 
	static AUIManager* instance;
};
