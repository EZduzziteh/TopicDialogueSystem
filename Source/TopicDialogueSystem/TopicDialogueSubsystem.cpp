// Fill out your copyright notice in the Description page of Project Settings.


#include "TopicDialogueSubsystem.h"

void UTopicDialogueSubsystem::ExecuteAction(
    const FDialogueActionData& Action,
    UTopicManagerComponent* TopicManager,
    UTopicDialogueComponent* TopicDialogue)
{
    for (const FName& Topic : Action.TopicsToUnlock)
    {
        TopicManager->UnlockDialogueTopic(Topic);
    }

    if (Action.bLearnSpeakerName)
    {
        if (!TopicManager->KnownSpeakers.Contains(TopicDialogue->DialogueSpeaker_ID)) {
            TopicManager->KnownSpeakers.AddUnique(TopicDialogue->DialogueSpeaker_ID);
        }
    }

    if (Action.bEndDialogue)
    {
        OnTopicDialogueEnded.Broadcast();
    }
}