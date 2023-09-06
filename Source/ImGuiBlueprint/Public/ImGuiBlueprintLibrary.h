// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "imgui.h"
#include "ImGuiBlueprintLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
UCLASS()
class IMGUIBLUEPRINT_API UImGuiBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintCallable, Category="ImGui|Basic", BlueprintInternalUseOnly)
	static bool ImGui_Begin(FText Name)
	{
		return ImGui::Begin(TCHAR_TO_UTF8(*Name.ToString()));
	}

	UFUNCTION(BlueprintCallable, Category="ImGui|Basic", BlueprintInternalUseOnly)
	static void ImGui_End()
	{
		ImGui::End();
	}

	UFUNCTION(BlueprintCallable, Category="ImGui|Basic", meta=(AdvancedDisplay=1))
	static void ImGui_Text(FText Text, FLinearColor Color = FLinearColor(1.0f,1.0f,1.0f))
	{
		const FColor SRGB = Color.ToFColorSRGB();
		ImGui::TextColored(ImVec4(SRGB.R/255.f, SRGB.G/255.f, SRGB.B/255.f, SRGB.A/255.f), "%s", TCHAR_TO_UTF8(*Text.ToString()));
	}

	UFUNCTION(BlueprintCallable, Category="ImGui|Basic", meta=(AdvancedDisplay=1), BlueprintInternalUseOnly)
	static bool ImGui_Button(FText Name, FVector2D Size)
	{
		return ImGui::Button(TCHAR_TO_UTF8(*Name.ToString()), ImVec2(static_cast<float>(Size.X), static_cast<float>(Size.Y)));
	}

	UFUNCTION(BlueprintCallable, Category="ImGui|Basic", meta=(AdvancedDisplay="OffsetFromStartX,Spacing"))
	static void ImGui_SameLine(float OffsetFromStartX, float Spacing = -1)
	{
		ImGui::SameLine(OffsetFromStartX, Spacing);
	}

	// Widgets: Menus

	//
	UFUNCTION(BlueprintCallable, Category="ImGui|Menus", BlueprintInternalUseOnly)
	static bool ImGui_BeginMainMenuBar()
	{
		return ImGui::BeginMainMenuBar();
	}
	
	// Only call this if BeginMainMenuBar is true!
	UFUNCTION(BlueprintCallable, Category="ImGui|Menus", BlueprintInternalUseOnly)
	static void ImGui_EndMainMenuBar()
	{
		ImGui::EndMainMenuBar();
	}

	//
	UFUNCTION(BlueprintCallable, Category="ImGui|Menus", meta=(AdvancedDisplay=1), BlueprintInternalUseOnly)
	static bool ImGui_BeginMenu(FText Label, bool Enabled = true)
	{
		return ImGui::BeginMenu(TCHAR_TO_UTF8(*Label.ToString()), Enabled);
	}

	// Only call this if BeginMenu is true!
	UFUNCTION(BlueprintCallable, Category="ImGui|Menus", BlueprintInternalUseOnly)
	static void ImGui_EndMenu()
	{
		return ImGui::EndMenu();
	}

	// NOTE: Shortcuts are not processed by Dear ImGui automatically
	UFUNCTION(BlueprintCallable, Category="ImGui|Menus")
	static bool ImGui_MenuItem(FText Label, FString Shortcut, bool Selected = false, bool Enabled = true)
	{
		return ImGui::MenuItem(TCHAR_TO_UTF8(*Label.ToString()), TCHAR_TO_UTF8(*Shortcut), Selected, Enabled);
	}
};
