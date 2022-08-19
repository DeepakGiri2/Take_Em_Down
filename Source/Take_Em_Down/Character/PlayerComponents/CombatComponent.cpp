// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatComponent.h"
#include "Take_Em_Down/Weapons/Weapon.h"
#include "Take_Em_Down/Character/PlayerCharacter.h"
#include "Engine/SkeletalMeshSocket.h"
// Sets default values for this component's properties
UCombatComponent::UCombatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UCombatComponent::EquipWeapon(TObjectPtr<AWeapon> WeaponToEquip)
{
	if (!Character|| !WeaponToEquip) return;
	EquipedWeapon = WeaponToEquip;
	EquipedWeapon->SetWeaponState(EWeaponState::EWS_Equiped);
	const USkeletalMeshSocket* RightHandSocket = Character->GetMesh()->GetSocketByName(FName("RightHandSocket"));
	if (RightHandSocket)
	{
		RightHandSocket->AttachActor(EquipedWeapon, Character->GetMesh());
	}
	EquipedWeapon->SetOwner(Character);
	EquipedWeapon->ShowPickUpWidget(false);
}


// Called every frame
void UCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

