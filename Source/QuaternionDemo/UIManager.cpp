// Fill out your copyright notice in the Description page of Project Settings.


#include "UIManager.h"

// Initialize static members
AUIManager* AUIManager::instance;

// Sets default values
AUIManager::AUIManager()
{

}

void AUIManager::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	instance = this; 
}

void AUIManager::OpenUI(E_UIType type, bool closeOtherUI = false)
{
	if (!Instance())
		return;
	if (closeOtherUI)
		Instance()->InternalCloseAllUI();
	Instance()->InternalOpenUI(type);
}

void AUIManager::CloseUI(E_UIType type)
{
	if (!Instance())
		return;
	Instance()->InternalCloseUI(type);
}

void AUIManager::CloseAllUI()
{
	if (!Instance())
		return;
	Instance()->InternalCloseAllUI();
}

void AUIManager::InternalCloseAllUI()
{
	for (int i = 0; i < elems.Num(); i++)
	{
		InternalCloseUI(elems[i].type);
	}
}

void AUIManager::InternalOpenUI(E_UIType type)
{
	for (int i = 0; i < elems.Num(); i++)
	{
		if (elems[i].type == type)
		{
			if (!elems[i].widget)
			{
				UE_LOG(LogTemp, Warning, TEXT("WIDGET NOT SELECTED FOR THIS TYPE IN EDITOR"));
				return;
			}
			if (!elems[i].widgetInstance)
			{
				elems[i].widgetInstance = CreateWidget<UUserWidget>(GetWorld(), elems[i].widget);
				elems[i].widgetInstance->AddToViewport();
			}
			elems[i].widgetInstance->SetVisibility(ESlateVisibility::Visible);
		}
	}
}

void AUIManager::InternalCloseUI(E_UIType type)
{
	for (int i = 0; i < elems.Num(); i++)
	{
		if (elems[i].type == type)
		{ 
			if (!elems[i].widgetInstance)
			{
				UE_LOG(LogTemp, Warning, TEXT("WIDGET HAS NOT BEEN INITIALIZED YET"));
				return;
			}
			elems[i].widgetInstance->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

AUIManager* AUIManager::Instance()
{
	if (instance)
	{
		return instance;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("INSTANCE OF UI MANAGER IS NOT SET"));
		return nullptr;
	}
}


