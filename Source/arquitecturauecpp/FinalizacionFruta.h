// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPAdventurer.h"

#include "Components/ActorComponent.h"
#include "FinalizacionFruta.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARQUITECTURAUECPP_API UFinalizacionFruta : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFinalizacionFruta();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	ACPPAdventurer *_adventurer;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
