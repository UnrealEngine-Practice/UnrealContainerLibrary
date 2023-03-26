// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Algo/Accumulate.h"

FString MakeRandomName()
{
	const TCHAR FirstName[] = TEXT("김이박최");
	const TCHAR MiddleName[] = TEXT("상해지성");
	const TCHAR LastName[] = TEXT("수은원연");

	TArray<TCHAR> RandName;
	RandName.SetNum(3);

	RandName[0] = FirstName[FMath::RandRange(0, 3)];
	RandName[1] = MiddleName[FMath::RandRange(0, 3)];
	RandName[2] = LastName[FMath::RandRange(0, 3)];

	return (RandName.GetData());
}

void UMyGameInstance::Init()
{
	Super::Init();

	const int32 ArrayNum = 10;
	TArray<int32> Int32Array;

	for (int32 i = 0 ; i <= ArrayNum ; ++i)
	{
		Int32Array.Add(i);
	}

	//TODO : Lambda 함수 사용법
	Int32Array.RemoveAll(
	[](int32 Val)
		{
			return (Val % 2 == 0);  
		}
	);

	Int32Array += {2, 4, 6, 8, 10};

	TArray<int32> Int32ArrayCompare;
	const int32 CArray[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
	Int32ArrayCompare.AddUninitialized(ArrayNum);
	FMemory::Memcpy(Int32ArrayCompare.GetData(), CArray, sizeof(int32) * 10);
	ensure(Int32Array == Int32ArrayCompare);

	int32 Sum = Algo::Accumulate(Int32Array, 0);
	UE_LOG(LogTemp, Log, TEXT("%d"), Sum);

	TSet<int32> Int32Set;
	for (int32 i = 0 ; i <= ArrayNum; i++)
	{
		Int32Set.Add(i);
	}
	Int32Set.Remove(2);
	Int32Set.Remove(4);
	Int32Set.Remove(6);
	Int32Set.Remove(8);
	Int32Set.Remove(10);
	Int32Set.Add(2);
	Int32Set.Add(4);
	Int32Set.Add(6);
	Int32Set.Add(8);
	Int32Set.Add(10);

	const int32 StudentNum = 300;
	for (int32 i = 0 ; i < StudentNum; i++)
	{
		StudentsData.Emplace(MakeRandomName(), i);
	}

	TArray<FString> AllStudentNames;
	Algo::Transform(StudentsData, AllStudentNames,
		[](const FStudentData& Val)
		{
			return Val.Name;
		}
	);
	UE_LOG(LogTemp, Log, TEXT("모든 학생 이름의 수 : %d"), AllStudentNames.Num());

	TSet<FString> AllUniqueStudentNames;
	Algo::Transform(StudentsData, AllUniqueStudentNames,
		[](const FStudentData& Val)
		{
			return Val.Name;
		}
	);
	UE_LOG(LogTemp, Log, TEXT("고유한 학생 이름의 수 : %d"), AllUniqueStudentNames.Num());

	Algo::Transform(StudentsData, StudentsMap,
		[](const FStudentData& Val)
		{
			return TPair<int32, FString>(Val.Order, Val.Name);
		}
	);
	UE_LOG(LogTemp, Log, TEXT("순번에 따른 학생 맵의 요소 수 : %d"), StudentsMap.Num());

	TMap<FString, int32> StudentsMapByName;
	TMultiMap<FString, int32> StudentsMultiMapByName;

	Algo::Transform(StudentsData, StudentsMapByName,
		[](const FStudentData& Val)
		{
			return TPair<FString, int32>(Val.Name, Val.Order);
		}
	);
	UE_LOG(LogTemp, Log, TEXT("이름에 따른 학생 맵의 요소 수 : %d"), StudentsMapByName.Num());

	Algo::Transform(StudentsData, StudentsMultiMapByName,
		[](const FStudentData& Val)
		{
			return TPair<FString, int32>(Val.Name, Val.Order);
		}
	);
	UE_LOG(LogTemp, Log, TEXT("이름에 따른 학생 멀티맵의 요소 수 : %d"), StudentsMultiMapByName.Num());

	const FString NameToFind(TEXT("이해은"));

	TArray<int32> AllOrders;
	StudentsMultiMapByName.MultiFind(NameToFind, AllOrders);
	UE_LOG(LogTemp, Log, TEXT("이름이 이혜은인 학생의 수 : %d"), AllOrders.Num());
}
