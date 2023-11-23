// Fill out your copyright notice in the Description page of Project Settings.

#include "EjemploComponenteActor.h"

// Sets default values for this component's properties
UEjemploComponenteActor::UEjemploComponenteActor() {
  // Set this component to be initialized when the game starts, and to be ticked
  // every frame.  You can turn these features off to improve performance if you
  // don't need them.
  PrimaryComponentTick.bCanEverTick = true;

  // ...
}

// Called when the game starts
void UEjemploComponenteActor::BeginPlay() {
  Super::BeginPlay();

  // ...

  auto nombre = GetOwner()->GetActorLabel();
  FString position = GetOwner()->GetTransform().GetLocation().ToString();
  UE_LOG(LogTemp, Warning, TEXT("Preparado y listo! Soy %s y estoy en %s"),
         *nombre, *position);
}

// Called every frame
void UEjemploComponenteActor::TickComponent(
    float DeltaTime, ELevelTick TickType,
    FActorComponentTickFunction *ThisTickFunction) {
  Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

  // ...
}
