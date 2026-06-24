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


// Called when the game starts
void UTopicDialogueComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
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

