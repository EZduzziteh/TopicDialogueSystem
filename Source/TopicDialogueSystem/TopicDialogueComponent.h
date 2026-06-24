// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TopicDialogueComponent.generated.h"

//forward declarations
class UDialogueAction;


USTRUCT(BlueprintType)
struct FDialogueActionData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FName> TopicsToUnlock;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//TArray<TObjectPtr<UItemDefinition>> ItemsToGive;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//TArray<TObjectPtr<UItemDefinition>> ItemsToRemove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bLearnSpeakerName = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bEndDialogue = false;
};



/*
----------------: DialogueLineData--------------------
*/




USTRUCT(BlueprintType)
struct FDialogueLineData {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText Text;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftClassPtr<USoundBase> Sound;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FDialogueActionData DialogueActionData;

	
	
};
/*
----------------: TopicData--------------------
*/
USTRUCT(BlueprintType)
struct FTopicData : public FTableRowBase{

	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName TopicID;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText TopicName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FDialogueLineData> DialogueLines;
};

/*
----------------: RumourData--------------------
*/
USTRUCT(BlueprintType)
struct FRumourData : public FTableRowBase {

	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName RumourID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FDialogueLineData> DialogueLines;
};






UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOPICDIALOGUESYSTEM_API UTopicDialogueComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTopicDialogueComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	TArray<FName> GetKnownTopics();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (RowType = "TopicData"))
	FName DialogueSpeaker_ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (RowType = "TopicData"))
	FText DialogueSpeaker_Name;


	UFUNCTION(BlueprintCallable)
	FTopicData GetTopicData(FName TopicName);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(RowType="TopicData"))
	FDataTableRowHandle Topics;
		
};
