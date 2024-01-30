// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h" 
#include "CPPAdventurer.generated.h"

UCLASS()
class ARQUITECTURAUECPP_API ACPPAdventurer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACPPAdventurer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
	UInputMappingContext* _input_mapping_context;
	UInputAction *_move;
	UInputAction *_rotate;


	void Move(const FInputActionValue& v);

	void Rotate(const FInputActionValue& v);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	TArray<int> puntos;

	inline void SumarPunto(int p) {
		puntos.Add(p);
	}

	int PuntosActuales() const;
};
