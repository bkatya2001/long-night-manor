// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "RotateSampleHUD.generated.h"

UCLASS()
class ARotateSampleHUD : public AHUD
{
	GENERATED_BODY()

public:
	ARotateSampleHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

