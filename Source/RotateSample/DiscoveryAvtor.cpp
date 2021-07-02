// Fill out your copyright notice in the Description page of Project Settings.


#include "DiscoveryAvtor.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"

// Sets default values
ADiscoveryAvtor::ADiscoveryAvtor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// if actor was "clicked"; must be placed in "On click function" that will be called from parent actor or independetly
	//PrimaryActorTick.SetTickFunctionEnable(true);
}

// Called when the game starts or when spawned
void ADiscoveryAvtor::BeginPlay()
{
	Super::BeginPlay();

	// Add discovery to Parent actor if needed
	if (m_ParentActor)
	{
		EAttachmentRule locationAttachment = EAttachmentRule::SnapToTarget;
		EAttachmentRule rotationAttachment = EAttachmentRule::SnapToTarget;
		EAttachmentRule scaleAttachment = EAttachmentRule::SnapToTarget;
		bool bInWeldSimulatedBodies = true;

		FAttachmentTransformRules attachmentRules =
		{
			locationAttachment,
			rotationAttachment,
			scaleAttachment,
			bInWeldSimulatedBodies
		};


		AttachToActor(m_ParentActor, attachmentRules);
	}
	
}

// Called every frame
void ADiscoveryAvtor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Check if camera direction == -normal with some offset
	APlayerController* playerController = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (playerController)
	{
		// Get vector facing the direction of Actor from quaternion 
		const FVector& rotation = GetActorRotation().Vector();
		// Normalize it 
		m_Normal = rotation.GetSafeNormal();

		// Get forward vector from player camera
		const FVector& forward = playerController->PlayerCameraManager->GetActorForwardVector();

		// Calculate dor product between camera forward vector and direction of the discovery; Convert to degrees 
		const float dotDegrees = Dot3(forward, m_Normal) * 360.0f;
		
		if (dotDegrees > m_Offset)
		{
			if (GEngine)
			{
				// Discovery is found 
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("dot product in degrees: %f"), dotDegrees));
			}
				
		}
		
	}
	

}

