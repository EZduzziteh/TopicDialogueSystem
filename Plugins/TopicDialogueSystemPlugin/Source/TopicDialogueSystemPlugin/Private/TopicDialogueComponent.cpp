// Fill out your copyright notice in the Description page of Project Settings.


#include "TopicDialogueComponent.h"

// Sets default values for this component's properties
UTopicDialogueComponent::UTopicDialogueComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

FString UTopicDialogueComponent::GetCurrentLocationName()
{
	/*Done this way so that you could localize the name, but return it as a string to be used for replacement*/
	
	return CurrentLocationName.ToString();
}


// Called when the game starts
void UTopicDialogueComponent::BeginPlay()
{
	Super::BeginPlay();

	if (SpeakerData != nullptr) {

		if (SpeakerData->TopicDataTable != NULL) {
			Topics.DataTable = SpeakerData->TopicDataTable;
		}
		else {

			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Error: Topic Data Table is not populated on Speaker Data (DataAsset)"));
		}
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Error: Speaker Data (DataAsset) is not populated on Speaker"));
	}
}


// Called every frame
void UTopicDialogueComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

TArray<FName> UTopicDialogueComponent::GetKnownTopics() {
	return Topics.DataTable->GetRowNames();
}


FTopicData UTopicDialogueComponent::GetTopicData(FName TopicName)
{
	const FTopicData* TopicData = Topics.DataTable->FindRow<FTopicData>(TopicName, TEXT(""));

	if (TopicData)
	{
		return *TopicData;
	}

	return FTopicData();
}

FDialogueLineData UTopicDialogueComponent::GetGreetLineData(bool knowsSpeaker)
{
	if (knowsSpeaker) {

		return SpeakerData->Greet_Met;
	}
	
	return SpeakerData->Greet_Unmet;
}

FDialogueLineData UTopicDialogueComponent::GetFirstLineData(bool knowsSpeaker)
{
	if (knowsSpeaker) {

		return SpeakerData->First_Met;
	}

	return SpeakerData->First_Unmet;
}


FDialogueLineData UTopicDialogueComponent::GetGoodbyeLineData()
{

	return SpeakerData->Goodbye;
}


