// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "GameCamera.generated.h"


class UCameraComponent;
class  AMuffin;
UCLASS()
class MUFFIN2D_API AGameCamera : public AActor
{
	GENERATED_BODY()
	
public:	
	AGameCamera();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
public :
	void   MoveCamera();
	

public:
	UPROPERTY(EditAnywhere)
	UCameraComponent*  CameraCop;
	
	APlayerController* PC;

	AMuffin*  muffin;
};
