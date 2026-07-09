// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TopicManagerComponent.generated.h"



DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTopicLearned);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOPICDIALOGUESYSTEMPLUGIN_API UTopicManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTopicManagerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void UnlockDialogueTopic(FName TopicName);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FName> KnownTopics;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FName> KnownSpeakers;


	UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite)
	FOnTopicLearned OnTopicLearned;

	UFUNCTION(BlueprintCallable) 
	bool KnowsSpeaker(FName SpeakerID);
		
};
