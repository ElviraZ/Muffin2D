// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Cloud.generated.h"



class UBoxComponent;
class UStaticMeshComponent;
class  AMuffin;
UCLASS()
class MUFFIN2D_API ACloud : public AActor
{
	GENERATED_BODY()
	
public:	
	ACloud();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor)   override;
public:

	UPROPERTY(EditAnywhere,Category="Collision")
	UBoxComponent* boxCollision;
	UPROPERTY(EditAnywhere, Category = "Show")
	UStaticMeshComponent* cloudMeshComponent;
	
	UPROPERTY(EditAnywhere,Category="Show")
		TArray<UTexture*> textures;

	UMaterialInstanceDynamic* matInstance;
	UMaterialInterface* matInterface;

	AMuffin* muffin;

public: 
	void  SetRandomCloudTexture();
};
