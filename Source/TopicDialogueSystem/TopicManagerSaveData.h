// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "TopicManagerSaveData.generated.h"

/**
 * 
 */
UCLASS()
class TOPICDIALOGUESYSTEM_API UTopicManagerSaveData : public USaveGame
{
	GENERATED_BODY()
	

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FName> KnownNPCIDs;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FName> KnownTopicIDs;
};
