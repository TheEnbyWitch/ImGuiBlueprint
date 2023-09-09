// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "imgui.h"
#include "Kismet/KismetMathLibrary.h"
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
		ImGui::TextColored(ImVec4(SRGB.R/255.f, SRGB.G/255.f, SRGB.B/255.f, SRGB.A/255.f), "%s", TCHAR_TO_UTF8(*Text));
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

	UFUNCTION(BlueprintCallable, Category="ImGui|Basic")
	static bool ImGui_Slider(FString Text, float Min, float Max, float& Value)
	{
		static float SliderValue = 0;
		bool Success = ImGui::SliderFloat(TCHAR_TO_UTF8(*Text), &SliderValue, Min, Max);
		Value = SliderValue;
		return Success;
	}

	UFUNCTION(BlueprintCallable, Category="ImGui|Basic")
	static bool ImGui_VSlider(FString Text, float Min, float Max, FVector2D Size, float& Value)
	{
		static float SliderValue = 0;
		bool Success = ImGui::VSliderFloat(TCHAR_TO_UTF8(*Text), ImVec2(Size.X, Size.Y), &SliderValue, Min, Max);
		Value = SliderValue;
		return Success;
	}

	//If @Text is empty, it'll display the percentage
	UFUNCTION(BlueprintCallable, Category="ImGui|Basic")
	static void ImGui_ProgressBar(float Progress, float Min, float Max, FVector2D Size, FString Text)
	{
		float NewProgress =	UKismetMathLibrary::MapRangeClamped(Progress, Min, Max, 0, 1);
		if(Text.IsEmpty())
		{
			ImGui::ProgressBar(NewProgress, ImVec2(Size.X, Size.Y));
		}
		else
		{
			ImGui::ProgressBar(NewProgress, ImVec2(Size.X, Size.Y), TCHAR_TO_UTF8(*Text));
		}
	}

	UFUNCTION(BlueprintCallable, Category="ImGui|Basic")
	static void ImGui_PlotLines(FString Text, TArray<float> Floats, FVector2D Size, float Min, float Max)
	{
		//Figure out the average, min and max.
		//We have to pass min and max if we want to pass in custom size.
		float Average = 0;
		for(auto& CurrentFloat : Floats)
		{
			Average += CurrentFloat;
		}
		Average = Average/Floats.Num();
		
		ImGui::PlotLines(TCHAR_TO_UTF8(*Text), Floats.GetData(), Floats.Num(), 0,
			TCHAR_TO_UTF8(*FString::SanitizeFloat(Average)), Min, Max, ImVec2(Size.X, Size.Y));
	}

	UFUNCTION(BlueprintCallable, Category="ImGui|Basic")
	static bool ImGui_Checkbox(FString Text, UPARAM(ref) bool& BoolToUpdate)
	{
		static bool Value;
		bool Pressed =  ImGui::Checkbox(TCHAR_TO_UTF8(*Text), &Value);
		BoolToUpdate = Value;
		return Pressed;
	}

	UFUNCTION(BlueprintCallable, Category="ImGui|Basic")
	static void ImGui_Separator()
	{
		ImGui::Separator();
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
