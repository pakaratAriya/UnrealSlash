#pragma once
UENUM(BlueprintType)
enum class EWeaponTypes : uint8 {
	EWT_OneHandedWeapon UMETA(DisplayName = "One-handed Weapon"),
	EWT_TwoHandedWeapon UMETA(DisplayName = "Two-handed Weapon")
};