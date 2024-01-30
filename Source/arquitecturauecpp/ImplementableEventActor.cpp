// Fill out your copyright notice in the Description page of Project Settings.


#include "ImplementableEventActor.h"

// Sets default values
AImplementableEventActor::AImplementableEventActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AImplementableEventActor::BeginPlay()
{
	Super::BeginPlay();

	EventoBP();
	EventoBP2();
	
}

void AImplementableEventActor::EventoBP2_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Implementacion por defecto"));
}

// Called every frame
void AImplementableEventActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

