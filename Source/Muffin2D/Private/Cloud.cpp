// Fill out your copyright notice in the Description page of Project Settings.

#include "Cloud.h"
#include "Components//BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Materials/MaterialInterface.h"
#include "Muffin.h"

// Sets default values
ACloud::ACloud()
{
	PrimaryActorTick.bCanEverTick = true;
	boxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	RootComponent = boxCollision;

	cloudMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CloudMeshComponent"));
	cloudMeshComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ACloud::BeginPlay()
{
	Super::BeginPlay();
	SetRandomCloudTexture();
}

// Called every frame
void ACloud::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
/*云彩与玩家的碰撞处理*/
void ACloud::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	muffin = Cast<AMuffin>(OtherActor);
	if (muffin)
	{
		//重新弹起
		muffin->Launch();


		//显示分数


		//销毁自身
		this -> Destroy();

		
	}
}

void ACloud::SetRandomCloudTexture()
{
	matInterface = cloudMeshComponent->GetMaterial(0);
	matInstance = cloudMeshComponent->CreateDynamicMaterialInstance(0, matInterface);
	if (textures.Num() != 0)
	{
		int index = FMath::RandRange(0, textures.Num() - 1);
		matInstance->SetTextureParameterValue(FName(TEXT("Texture")), textures[index]);
		UE_LOG(LogTemp, Warning, TEXT(" %i"), index);
		cloudMeshComponent->SetMaterial(0, matInstance);
	}







}

