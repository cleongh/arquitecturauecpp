// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CPPAdventurer.h"
#include "SubidorCelda.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARQUITECTURAUECPP_API USubidorCelda : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USubidorCelda();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	double _height = 90.0f;

	
	ACPPAdventurer *_adventurer;

	UPROPERTY(EditAnywhere)
	int _puntos_para_abrir = 5;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
