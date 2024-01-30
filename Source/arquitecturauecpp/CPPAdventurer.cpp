// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPAdventurer.h"

#include "GameFramework/FloatingPawnMovement.h" 

#include "GameFramework/SpringArmComponent.h" 



#include "Engine/LocalPlayer.h" 

#include "EnhancedInputSubsystems.h" 
#include "Components/SphereComponent.h"


#include "Camera/CameraComponent.h"

// Sets default values
ACPPAdventurer::ACPPAdventurer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	auto shape = CreateDefaultSubobject<USphereComponent>(TEXT("esfera"));
	RootComponent = shape;
	shape->InitSphereRadius(50.0f);
	shape->SetCollisionProfileName(TEXT("Pawn"));


	auto move = CreateDefaultSubobject<UFloatingPawnMovement>(
		TEXT("Movement component"));
	move->MaxSpeed = 1200.0f;

	auto arm =
		CreateDefaultSubobject<USpringArmComponent>(
			TEXT("SpringArm"));
	arm->SetupAttachment(RootComponent);

	auto _camera = CreateDefaultSubobject<UCameraComponent>(
		TEXT("CameraPlayer"));
	_camera->SetupAttachment(arm);



	_move = CreateDefaultSubobject<UInputAction>(TEXT("MoveAction"));
	_rotate = CreateDefaultSubobject<UInputAction>(TEXT("RotateAction"));
	
	_input_mapping_context = CreateDefaultSubobject<UInputMappingContext>(TEXT("NormalMapping"));	
}

// Called when the game starts or when spawned
void ACPPAdventurer::BeginPlay()
{
	Super::BeginPlay();
	

}

// Called every frame
void ACPPAdventurer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPPAdventurer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	auto controller = Cast<APlayerController>(GetController());
	if (auto system = controller->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>()) {
		if (_input_mapping_context) {
			// el "1" es la prioridad del mapeo, cuanto más alta, más prioritario
			system->AddMappingContext(_input_mapping_context, 1);

			_move->bConsumeInput = true;
			_move->ValueType = EInputActionValueType::Axis1D;


			_rotate->bConsumeInput = true;
			_rotate->ValueType = EInputActionValueType::Axis1D;

			_input_mapping_context->MapKey(_move, EKeys::W);

			auto & mapping = _input_mapping_context->MapKey(_move, EKeys::S);
			mapping.Modifiers.Add(NewObject<UInputModifierNegate>(this));

			_input_mapping_context->MapKey(_rotate, EKeys::D);
			auto& mapping_rotate = _input_mapping_context->MapKey(_rotate, EKeys::A);
			mapping_rotate.Modifiers.Add(NewObject<UInputModifierNegate>(this));

		}
	}

	auto eic = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	eic->BindAction(_move, ETriggerEvent::Triggered, this, &ACPPAdventurer::Move);
	eic->BindAction(_rotate, ETriggerEvent::Triggered, this, &ACPPAdventurer::Rotate);

}

void ACPPAdventurer::Move(const FInputActionValue& v) {	
	FVector forward = GetWorld()->
		GetFirstPlayerController()->
		PlayerCameraManager->
		GetCameraRotation().Vector();
	AddMovementInput(forward, v.GetMagnitude());
}

void ACPPAdventurer::Rotate(const FInputActionValue& v) {
	SetActorRotation(GetActorRotation() + FRotator(0.0f, v.GetMagnitude() * 0.5f , 0.0f));
}

int ACPPAdventurer::PuntosActuales() const {
	int p = 0;
	for (auto c : puntos) {
		p += c;
	}
	return p;
}

