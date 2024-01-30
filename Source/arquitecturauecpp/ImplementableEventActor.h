// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ImplementableEventActor.generated.h"

UCLASS()
class ARQUITECTURAUECPP_API AImplementableEventActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AImplementableEventActor();

protected:

	UFUNCTION(BlueprintImplementableEvent)
	void EventoBP();

	UFUNCTION(BlueprintNativeEvent)
	void EventoBP2();


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
