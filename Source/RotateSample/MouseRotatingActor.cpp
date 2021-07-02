// Fill out your copyright notice in the Description page of Project Settings.


#include "MouseRotatingActor.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
AMouseRotatingActor::AMouseRotatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	

}

// Called when the game starts or when spawned
void AMouseRotatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMouseRotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector2D mousePos;

	if (UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetMousePosition(mousePos.X, mousePos.Y))
	{
		const FVector2D mousePosDelta = mousePos - previousMousePos;
		//if (GEngine)
		//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Mouse delta: %f, %f"), mousePosDelta.X, mousePosDelta.Y));

		// Check if mouse moved from previous frame
		FRotator rotation = FRotator(mousePosDelta.Y * m_Scale.Y * DeltaTime, -mousePosDelta.X * m_Scale.X * DeltaTime, 0.0f * m_Scale.Z * DeltaTime);

		FQuat quatRotation = FQuat(rotation);

		//AddActorLocalRotation(quatRotation, false, 0, ETeleportType::None);
		AddActorWorldRotation(quatRotation, false, 0, ETeleportType::None);

		previousMousePos = mousePos;
	}

	

}

