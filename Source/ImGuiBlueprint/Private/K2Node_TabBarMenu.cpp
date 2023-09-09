// Fill out your copyright notice in the Description page of Project Settings.


#include "K2Node_TabBarMenu.h"

UK2Node_TabBarMenu* UK2Node_TabBarMenu::ImGui_TabBarMenu(TArray<FString> Tabs)
{
	UK2Node_TabBarMenu* NewAsyncObject = NewObject<UK2Node_TabBarMenu>();
	NewAsyncObject->TabNames = Tabs;
	return NewAsyncObject;
}

void UK2Node_TabBarMenu::Activate()
{
	Super::Activate();
	
	// Passing a bool* to BeginTabItem() is similar to passing one to Begin():
	// the underlying bool will be set to false when the tab is closed.
	if (ImGui::BeginTabBar("MyTabBar"))
	{
		for (int n = 0; n < TabNames.Num(); n++)
		{
			if (ImGui::BeginTabItem(TCHAR_TO_UTF8(*TabNames[n])))
			{
				TabAdded.Broadcast(n);
				ImGui::EndTabItem();
			}
		}
			
		ImGui::EndTabBar();
	}

	Finish.Broadcast();
	RemoveFromRoot();
}
