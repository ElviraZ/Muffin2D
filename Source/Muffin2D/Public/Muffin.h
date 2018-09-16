// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Muffin.generated.h"

UCLASS()
class MUFFIN2D_API AMuffin : public ACharacter
{
	GENERATED_BODY()

public:
	AMuffin();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


public:

	APlayerController* PC;
	void   MoveTowardsCursor();
	void   LaunchOnAnyKeyPress();
	void  Launch();

public:


	FVector launchVelocity;
};
