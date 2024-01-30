// Fill out your copyright notice in the Description page of Project Settings.


#include "FinalizacionFruta.h"
#include "Kismet/GameplayStatics.h" 


// Sets default values for this component's properties
UFinalizacionFruta::UFinalizacionFruta()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFinalizacionFruta::BeginPlay()
{
	Super::BeginPlay();

	// ...
	_adventurer = Cast<ACPPAdventurer>(GetWorld()->
		GetFirstPlayerController()->
		GetPawn());
	
}


// Called every frame
void UFinalizacionFruta::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	if (GetOwner()->IsOverlappingActor(_adventurer)) {		
		UGameplayStatics::OpenLevel(this, TEXT("Fin"));
	}
}

