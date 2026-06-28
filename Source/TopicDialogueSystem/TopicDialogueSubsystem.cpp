// Fill out your copyright notice in the Description page of Project Settings.


#include "TopicDialogueSubsystem.h"

/*Executes Lines, with delays and awaits if required*/
/*
void UTopicDialogueSubsystem::ExecuteLines(
    TArray<FDialogueLineData*>Lines,
    UTopicManagerComponent* TopicManager,
    UTopicDialogueComponent* TopicDialogue)
{

    LinesToExecute = Lines;
    CurrentLineIndex = 0;
    OnTopicDialogueLinesFinishedExecute.Broadcast();
}*/

/*Executes a single dialogue line*/
void UTopicDialogueSubsystem::ExecuteLine(
    FDialogueLineData Line,
    UTopicManagerComponent* TopicManager,
    UTopicDialogueComponent* TopicDialogue)
{
   // LinesToExecute = ;
    //CurrentLineIndex = 0;


    OnTopicDialogueLineWasExecuted.Broadcast(TopicDialogue, Line);
    OnTopicDialogueFinished.Broadcast();
}


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
        if (!TopicManager->KnownSpeakers.Contains(TopicDialogue->SpeakerData->DialogueSpeaker_ID)) {
            TopicManager->KnownSpeakers.AddUnique(TopicDialogue->SpeakerData->DialogueSpeaker_ID);
        }
    }

    if (Action.bEndDialogue)
    {
        OnTopicDialogueEnded.Broadcast();
    }
}

/*This function lets us translate special symbols via lookup for special things included in text, such as <PLAYERNAME> for the player characters name.*/
FText UTopicDialogueSubsystem::TranslateSymbols(const FText& InputText, UTopicDialogueComponent* TopicDialogue)
{
    FString inputString = InputText.ToString();
    const FRegexPattern Pattern(TEXT("<([A-Z0-9_]+)>"));
    FRegexMatcher Matcher(Pattern, inputString);

    while (Matcher.FindNext())
    {
        const FString FullTag = Matcher.GetCaptureGroup(0);   // "<PLAYERNAME>"
        const FString TagName = Matcher.GetCaptureGroup(1);   // "PLAYERNAME"

        FString Replacement;

        if (TagName == TEXT("PLAYERNAME"))
        {
            Replacement = GetPlayerName();
        }
        else if (TagName == TEXT("CURRENTLOCATION"))
        {
            Replacement = TopicDialogue->GetCurrentLocationName();
        }

        if (!Replacement.IsEmpty())
        {
            inputString.ReplaceInline(*FullTag, *Replacement);
        }
    }

    return FText::FromString(inputString);
}

FString UTopicDialogueSubsystem::GetPlayerName() {

    /*This should probably be in something like gamestate - but this is just an example*/
    return TEXT("John Dialogue");
}


