// Fill out your copyright notice in the Description page of Project Settings.

#include "CloudSpawner.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"


// Sets default values
ACloudSpawner::ACloudSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	spawnArea = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnArea"));
	triggerArea = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerArea"));
	defaultRootComponet = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultRootComponet"));
	RootComponent = defaultRootComponet;
	spawnArea->SetupAttachment(defaultRootComponet);
	triggerArea->SetupAttachment(defaultRootComponet);
}

// Called when the game starts or when spawned
void ACloudSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACloudSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

