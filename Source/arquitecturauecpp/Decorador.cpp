// Fill out your copyright notice in the Description page of Project Settings.


#include "Decorador.h"
#include "Components/SphereComponent.h"


// Sets default values
ADecorador::ADecorador()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	auto colision = CreateDefaultSubobject<USphereComponent>(TEXT("esfera"));
	RootComponent = colision;
	colision->InitSphereRadius(50.0f);
	colision->SetCollisionProfileName(TEXT("Pawn"));

	_malla_component =
		CreateDefaultSubobject<UStaticMeshComponent>(
			TEXT("malla"));
	_malla_component->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ADecorador::BeginPlay()
{
	Super::BeginPlay();

	_malla_component->SetStaticMesh(_malla_externa.LoadSynchronous());
	
}

// Called every frame
void ADecorador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

