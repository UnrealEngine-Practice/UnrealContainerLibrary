// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCONTAINER_API UMyGameInstance final : public UGameInstance
{
	GENERATED_BODY()
public:
	virtual void Init() override;
};
