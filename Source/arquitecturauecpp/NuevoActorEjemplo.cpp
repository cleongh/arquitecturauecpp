// Fill out your copyright notice in the Description page of Project Settings.


#include "NuevoActorEjemplo.h"

// Sets default values
ANuevoActorEjemplo::ANuevoActorEjemplo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_esfera = CreateDefaultSubobject<USphereComponent>(TEXT("esfera"));
	RootComponent = _esfera;
	_esfera->InitSphereRadius(50.0f);
	_esfera->SetCollisionProfileName(TEXT("Pawn"));

	UStaticMeshComponent* malla_esfera =
		CreateDefaultSubobject<UStaticMeshComponent>(
			TEXT("malla_esfera"));
	malla_esfera->SetupAttachment(RootComponent);
	/*
	* Starter content
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		SphereVisualAsset(
			TEXT("/Game/StarterContent/Shapes/Shape_Sphere"));*/

	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		SphereVisualAsset(
			TEXT("/Engine/BasicShapes/Sphere"));
	malla_esfera->SetStaticMesh(SphereVisualAsset.Object);



}

// Called when the game starts or when spawned
void ANuevoActorEjemplo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANuevoActorEjemplo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FTransform spawnedTransform = GetTransform();
	spawnedTransform.AddToTranslation(FVector{ 100.f, 0.f, 0.f });
	AActor * nuevo = GetWorld()->SpawnActor<AActor>(AActor::StaticClass(),
		spawnedTransform);

	_spawned.Add(nuevo);


	if ((_counterDelete -= DeltaTime) <= 0.0f) {
		_counterDelete = CD;
		for (auto& a : _spawned) {
			a->Destroy();
		}
		_spawned.Empty();
	}
}

