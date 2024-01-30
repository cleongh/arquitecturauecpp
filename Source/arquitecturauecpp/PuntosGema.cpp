// Fill out your copyright notice in the Description page of Project Settings.


#include "PuntosGema.h"

// Sets default values for this component's properties
UPuntosGema::UPuntosGema()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPuntosGema::BeginPlay()
{
	Super::BeginPlay();

	// ...

	_adventurer = Cast<ACPPAdventurer>(GetWorld()->
		GetFirstPlayerController()->
		GetPawn());
}


// Called every frame
void UPuntosGema::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	if (GetOwner()->IsOverlappingActor(_adventurer)) {
		_adventurer->SumarPunto(_puntos_gema);
		GetOwner()->Destroy();
	}

}

