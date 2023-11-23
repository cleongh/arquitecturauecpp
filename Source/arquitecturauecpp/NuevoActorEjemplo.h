// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "NuevoActorEjemplo.generated.h"

UCLASS()
class ARQUITECTURAUECPP_API ANuevoActorEjemplo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANuevoActorEjemplo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	USphereComponent* _esfera;
	TArray<AActor*> _spawned;
	static constexpr float CD = 5.0f;
	float _counterDelete = CD;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
