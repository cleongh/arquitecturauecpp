// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AntesTerminar.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAntesTerminar);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARQUITECTURAUECPP_API UAntesTerminar : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAntesTerminar();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	

	UPROPERTY(BlueprintAssignable)
		FAntesTerminar AntesTerminar;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
