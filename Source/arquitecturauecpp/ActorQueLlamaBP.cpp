// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorQueLlamaBP.h"
#include "ImprimidorPadreCPP.h"
#include "Misc/OutputDeviceNull.h"

// Sets default values
AActorQueLlamaBP::AActorQueLlamaBP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActorQueLlamaBP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorQueLlamaBP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    auto f = FindComponentByClass<UImprimidorPadreCPP>();
    if (nullptr != f) // comprobad siempre
    {
        FOutputDeviceNull n;
        FString param = "\"hola a todos!\" 6";
        FString cmd =
            FString::Printf(
                TEXT("Saludar %s"),
                *param);

        // Debe imprimir "hola a todos!" y "7" en pantalla
        f->CallFunctionByNameWithArguments(
            *cmd, n, nullptr, true);
    }

}

