// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CloudSpawner.generated.h"


class UBoxComponent;

class USceneComponent;
UCLASS()
class MUFFIN2D_API ACloudSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	ACloudSpawner();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere,Category="Component")
		UBoxComponent* spawnArea;
	UPROPERTY(EditAnywhere, Category = "Component")
		UBoxComponent* triggerArea;
	
	USceneComponent* defaultRootComponet;
};
