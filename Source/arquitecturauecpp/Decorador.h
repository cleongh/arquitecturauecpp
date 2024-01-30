// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Decorador.generated.h"

UCLASS()
class ARQUITECTURAUECPP_API ADecorador : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADecorador();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
	// Ejemplo de tooltip (menos prioritario)
	UPROPERTY(EditAnywhere, Category = "Estetica",meta=(ToolTip="Tooltip"))
	TSoftObjectPtr<UStaticMesh> _malla_externa;

	UStaticMeshComponent* _malla_component;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
