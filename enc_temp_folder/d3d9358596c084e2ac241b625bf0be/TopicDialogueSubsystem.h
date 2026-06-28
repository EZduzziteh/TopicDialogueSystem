// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TopicDialogueComponent.h"
#include "TopicManagerComponent.h"
#include "TopicDialogueSubsystem.generated.h"

//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDialogueInitiated);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTopicDialogueInitiated, UTopicDialogueComponent*, TopicDialogueComponent);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTopicUnlockedGlobal, FName, TopicName);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTopicDialogueEnded);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTopicDialogueFinished);



DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTopicDialogueLineWasExecuted, UTopicDialogueComponent*, TopicDialogueComponent, FDialogueLineData, DialogueLineData);

/**
 * 
 */
UCLASS()
class TOPICDIALOGUESYSTEM_API UTopicDialogueSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	

private:

	TArray<FDialogueLineData> LinesToExecute;

	int CurrentLineIndex = 0;

public:


	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "_TopicDialogue")
	FOnTopicDialogueFinished OnTopicDialogueFinished;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "_TopicDialogue")
	FOnTopicDialogueInitiated OnTopicDialogueInitiated;


	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "_TopicDialogue")
	FOnTopicUnlockedGlobal OnTopicUnlockedGlobal;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "_TopicDialogue")
	FOnTopicDialogueEnded OnTopicDialogueEnded;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "_TopicDialogue")
	FOnTopicDialogueLineWasExecuted OnTopicDialogueLineWasExecuted;


	UFUNCTION(BlueprintCallable)
	void ExecuteLine(FDialogueLineData Line, UTopicManagerComponent* TopicManager, UTopicDialogueComponent* TopicDialogue);

	UFUNCTION(BlueprintCallable)
	void ExecuteAction(const FDialogueActionData& Action, UTopicManagerComponent* TopicManager, UTopicDialogueComponent* TopicDialogue);
	UFUNCTION(BlueprintCallable)
	FText TranslateSymbols(const FText& InputText, UTopicDialogueComponent* TopicDialogue);
	UFUNCTION(BlueprintCallable)
	FString GetPlayerName();
	

};
