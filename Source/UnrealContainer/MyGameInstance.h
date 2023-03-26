// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

USTRUCT()
struct FStudentData
{
	GENERATED_BODY();

	FStudentData()  : Name(TEXT("")), Order(-1){}

	FStudentData(FString InName, int32 InOrder) : Name(InName), Order(InOrder) {}

	FString Name;
	int32 Order;
};
/**
 * 
 */
UCLASS()
class UNREALCONTAINER_API UMyGameInstance final : public UGameInstance
{
	GENERATED_BODY()
public:
	virtual void Init() override;
private:
	TArray<FStudentData> StudentsData;
};
