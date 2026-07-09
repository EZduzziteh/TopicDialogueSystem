// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TopicDialogueSpeakerDataAsset.generated.h"


//forward declarations
class UDialogueAction;


USTRUCT(BlueprintType)
struct TOPICDIALOGUESYSTEMPLUGIN_API FDialogueActionData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FName> TopicsToUnlock;


	//NOTE: This is how you could  add items with an inventory system (EZInventory Example)
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//TArray<TObjectPtr<UItemDefinition>> ItemsToGive;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//TArray<TObjectPtr<UItemDefinition>> ItemsToRemove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bRumours = false;

	/*This is for the physical location of the npc, for example the town they are in.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bLocationInformation = false;

	/*This is for nearby services such as vendors*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bNearbyServices = false;

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
	USoundBase* Sound;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float DelayAfterLine;


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FDialogueActionData DialogueActionData;



};
/*
----------------: TopicData--------------------
*/
USTRUCT(BlueprintType)
struct FTopicData : public FTableRowBase {

	GENERATED_BODY()
public:


	/*The ID of the topic (Must be Unique)*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName TopicID;

	/*The Display name for the topic (Does not need to be unique - ensure appropriate ID is set up.)*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText TopicName;

	/*This is a collection of Dialogue Lines*/
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






/**
 * 
 */
UCLASS()
class TOPICDIALOGUESYSTEMPLUGIN_API UTopicDialogueSpeakerDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (RowType = "TopicData"))
	FName DialogueSpeaker_ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (RowType = "TopicData"))
	FText DialogueSpeaker_Name;
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDataTable* TopicDataTable;

	/*These are the unique Dialogue Optiosn with special implementations (separate from the dialogueLines table*/

	/*Response when player initializes dialogue with this npc, and the player does not know them*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FDialogueLineData First_Unmet;

	/*Response when player initializes dialogue with this npc, and the player already knows them.*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FDialogueLineData First_Met;

	/*Response when player greets this npc, and the player does not know them*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FDialogueLineData Greet_Unmet;

	/*Response when player greets this npc, and the player already knows them.*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FDialogueLineData Greet_Met;


	/*Response when player greets this npc, and the player already knows them.*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FDialogueLineData Goodbye;

	/*The remous that the npc knows of, used when player selects 'rumour'*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FRumourData Rumours;


	/*Trade Data - for trading with vendors*/




};
