// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DiscoveryAvtor.generated.h"

UCLASS()
class ROTATESAMPLE_API ADiscoveryAvtor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADiscoveryAvtor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Normalized discovery normal
	// Must be normalized
	UPROPERTY(EditAnywhere, Category = "Normal")
		FVector m_Normal = { 0.0f, 0.0f, 0.0f };

	// Offset where player can "find" the discovery (in degrees)
	// Must be between 0 and 360 
	UPROPERTY(EditAnywhere, Category = "Offset")
		float m_Offset = {180.0f};

	UPROPERTY(EditAnywhere, Category = "Parent actor")
		AActor* m_ParentActor = { nullptr };

};
