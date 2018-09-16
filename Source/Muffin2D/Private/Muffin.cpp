// Fill out your copyright notice in the Description page of Project Settings.

#include "Muffin.h"


// Sets default values
AMuffin::AMuffin()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	launchVelocity = FVector(0, 0, 1500);
}

// Called when the game starts or when spawned
void AMuffin::BeginPlay()
{
	Super::BeginPlay();
	PC = Cast<APlayerController>(GetController());
	PC->bShowMouseCursor = true;
}

// Called every frame
void AMuffin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveTowardsCursor();
}

// Called to bind functionality to input
void AMuffin::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMuffin::LaunchOnAnyKeyPress);
}
/*人物跟上鼠标移动*/
void AMuffin::MoveTowardsCursor()
{
	//获得世界坐标下鼠标的位置和方向
	FVector   mouseLocation, mouseDirection;
	PC->DeprojectMousePositionToWorld(mouseLocation, mouseDirection);
	float  YDirection = FMath::Clamp(mouseLocation.Y - GetActorLocation().Y, -1.0f, 1.0f);
	FVector  Direction = FVector(0, YDirection, 0);
	AddMovementInput(Direction);
}

void AMuffin::LaunchOnAnyKeyPress()
{
	Launch();

}
/*向上跳跃*/
void AMuffin::Launch()
{
	LaunchCharacter(launchVelocity, false, true);
}

