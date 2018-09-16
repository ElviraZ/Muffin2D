// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/GameCamera.h"
#include "Camera/CameraComponent.h"
#include "Kismet//GameplayStatics.h"
#include "Muffin.h"

// Sets default values
AGameCamera::AGameCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CameraCop = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraCop"));
	CameraCop->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AGameCamera::BeginPlay()
{
	Super::BeginPlay();
	muffin=Cast<AMuffin>(UGameplayStatics::GetPlayerPawn(this, 0));



	PC = UGameplayStatics::GetPlayerController(this, 0);
	PC->SetViewTargetWithBlend(this, 0);
}

// Called every frame
void AGameCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveCamera();
}

void AGameCamera::MoveCamera()
{
FVector  targetPos=FVector(GetActorLocation().X, GetActorLocation().Y, (muffin->GetActorLocation().Z)+150.0f);
this->SetActorLocation( targetPos);
}

