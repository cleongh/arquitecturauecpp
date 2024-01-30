// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorFuncionLlamable.h"

// Sets default values
AActorFuncionLlamable::AActorFuncionLlamable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActorFuncionLlamable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorFuncionLlamable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AActorFuncionLlamable::SaySomething(const FText& text)
{
	FString str = text.ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s"), *str)
}
