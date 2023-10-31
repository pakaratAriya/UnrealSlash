// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "CharacterTypes.h"
#include "SlashCharacter.generated.h"

class UInputAction;
class UInputMappingContext;
class USpringArmComponent;
class UCameraComponent;
class UGroomComponent;
class AItem;
class UAnimMontage;

UCLASS()
class SLASH_API ASlashCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASlashCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:

	void Move(const FInputActionValue& Value);
	void Rotate(const FInputActionValue& Value);
	void PickUp();
	void Attack();


	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category=Input)
		UInputAction* MovementAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
		UInputMappingContext* SlashContext;
	UPROPERTY(EditAnywhere, Category = Input)
		UInputAction* RotationAction;
	UPROPERTY(EditAnywhere, Category = Input)
		UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, Category = Input)
		UInputAction* PickupAction;
	UPROPERTY(EditAnywhere, Category = Input)
		UInputAction* AttackAction;
	
	/*
	Montages
	*/
	UPROPERTY(EditDefaultsOnly, Category = Montages)
	UAnimMontage* AttackMontage;
private:
	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;
	EActionState ActionState = EActionState::EAS_Unoccupied;

	UPROPERTY(VisibleAnywhere)
		USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere)
		UCameraComponent* ViewCamera;
	UPROPERTY(VisibleAnywhere)
		UGroomComponent* Hair;
	UPROPERTY(VisibleAnywhere)
		UGroomComponent* Eyebrows;
	UPROPERTY(VisibleInstanceOnly)
		AItem* OverlappingItem;


	/*
		Play Montages
	*/
	void PlayAttackMontage();

public:
	FORCEINLINE void SetOverlappingItem(AItem* Item) { OverlappingItem = Item; }
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }
};
