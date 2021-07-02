// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MouseRotatingActor.generated.h"

UCLASS()
class ROTATESAMPLE_API AMouseRotatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMouseRotatingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector m_Scale = { 1.0f, 1.0f, 1.0f };

	FVector2D previousMousePos;
	/*
	UPROPERTY(EditAnywhere, Category = "Movement")
		float PitchScale;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float YawScale;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float RollScale;
	*/

};
