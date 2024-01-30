// Fill out your copyright notice in the Description page of Project Settings.


#include "SubidorCelda.h"

// Sets default values for this component's properties
USubidorCelda::USubidorCelda()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USubidorCelda::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	auto* pawn = GetWorld()->
		GetFirstPlayerController()->
		GetPawn();

	// puede devolver `nullptr` si el casting falla
	_adventurer = Cast<ACPPAdventurer>(pawn);
}


// Called every frame
void USubidorCelda::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	if (_adventurer->PuntosActuales() >= _puntos_para_abrir) {

		auto l = GetOwner()->GetActorLocation();
		l.Z = _height;
		GetOwner()->SetActorLocation(l);
	}
}

