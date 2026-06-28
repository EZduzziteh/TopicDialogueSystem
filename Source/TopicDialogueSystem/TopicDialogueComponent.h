// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TopicDialogueSpeakerDataAsset.h"
#include "TopicDialogueComponent.generated.h"





UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOPICDIALOGUESYSTEM_API UTopicDialogueComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTopicDialogueComponent();


	UFUNCTION(BlueprintCallable)
	FString GetCurrentLocationName();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	TArray<FName> GetKnownTopics();

	UFUNCTION(BlueprintCallable)
	FTopicData GetTopicData(FName TopicName);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTopicDialogueSpeakerDataAsset* SpeakerData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (RowType = "TopicData"))
	FDataTableRowHandle Topics;

	/*This is just an example - maybe you would want to return current level, or current cell, or have some more dynamic system for telling where the npc is located*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText CurrentLocationName;

	

	UFUNCTION(BlueprintCallable)
	FDialogueLineData GetGreetLineData(bool knowsSpeaker);

	UFUNCTION(BlueprintCallable)
	FDialogueLineData GetFirstLineData(bool knowsSpeaker);

	UFUNCTION(BlueprintCallable)
	FDialogueLineData GetGoodbyeLineData();

};
