// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SearchAndRescue/AI/MLAI/Enemies/MLEnemyBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMLEnemyBase() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UAnimInstance_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AExplosiveGrenade_NoRegister();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AMLEnemyBase();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AMLEnemyBase_NoRegister();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AMyActor_NoRegister();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_ASniperRifle_NoRegister();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_ASplineController_NoRegister();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AWeaponBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_SearchAndRescue();
// End Cross Module References

// Begin Class AMLEnemyBase Function getWeapon
struct Z_Construct_UFunction_AMLEnemyBase_getWeapon_Statics
{
	struct MLEnemyBase_eventgetWeapon_Parms
	{
		AWeaponBase* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "AI/MLAI/Enemies/MLEnemyBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMLEnemyBase_getWeapon_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MLEnemyBase_eventgetWeapon_Parms, ReturnValue), Z_Construct_UClass_AWeaponBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMLEnemyBase_getWeapon_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMLEnemyBase_getWeapon_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMLEnemyBase_getWeapon_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMLEnemyBase_getWeapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMLEnemyBase, nullptr, "getWeapon", nullptr, nullptr, Z_Construct_UFunction_AMLEnemyBase_getWeapon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMLEnemyBase_getWeapon_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMLEnemyBase_getWeapon_Statics::MLEnemyBase_eventgetWeapon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMLEnemyBase_getWeapon_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMLEnemyBase_getWeapon_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMLEnemyBase_getWeapon_Statics::MLEnemyBase_eventgetWeapon_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMLEnemyBase_getWeapon()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMLEnemyBase_getWeapon_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMLEnemyBase::execgetWeapon)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AWeaponBase**)Z_Param__Result=P_THIS->getWeapon();
	P_NATIVE_END;
}
// End Class AMLEnemyBase Function getWeapon

// Begin Class AMLEnemyBase Function ResetToRandomPointOnSpline
struct Z_Construct_UFunction_AMLEnemyBase_ResetToRandomPointOnSpline_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "AI/MLAI/Enemies/MLEnemyBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMLEnemyBase_ResetToRandomPointOnSpline_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMLEnemyBase, nullptr, "ResetToRandomPointOnSpline", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMLEnemyBase_ResetToRandomPointOnSpline_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMLEnemyBase_ResetToRandomPointOnSpline_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMLEnemyBase_ResetToRandomPointOnSpline()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMLEnemyBase_ResetToRandomPointOnSpline_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMLEnemyBase::execResetToRandomPointOnSpline)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ResetToRandomPointOnSpline();
	P_NATIVE_END;
}
// End Class AMLEnemyBase Function ResetToRandomPointOnSpline

// Begin Class AMLEnemyBase
void AMLEnemyBase::StaticRegisterNativesAMLEnemyBase()
{
	UClass* Class = AMLEnemyBase::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "getWeapon", &AMLEnemyBase::execgetWeapon },
		{ "ResetToRandomPointOnSpline", &AMLEnemyBase::execResetToRandomPointOnSpline },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMLEnemyBase);
UClass* Z_Construct_UClass_AMLEnemyBase_NoRegister()
{
	return AMLEnemyBase::StaticClass();
}
struct Z_Construct_UClass_AMLEnemyBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "AI/MLAI/Enemies/MLEnemyBase.h" },
		{ "ModuleRelativePath", "AI/MLAI/Enemies/MLEnemyBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_fHealth_MetaData[] = {
		{ "Category", "Base Variables" },
		{ "ModuleRelativePath", "AI/MLAI/Enemies/MLEnemyBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_fDefaultSpeed_MetaData[] = {
		{ "Category", "Base Variables" },
		{ "ModuleRelativePath", "AI/MLAI/Enemies/MLEnemyBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FiringAnimation_MetaData[] = {
		{ "Category", "Animation Montages" },
		{ "ModuleRelativePath", "AI/MLAI/Enemies/MLEnemyBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReloadAnimation_MetaData[] = {
		{ "Category", "Animation Montages" },
		{ "ModuleRelativePath", "AI/MLAI/Enemies/MLEnemyBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeathAnimation_MetaData[] = {
		{ "Category", "Animation Montages" },
		{ "ModuleRelativePath", "AI/MLAI/Enemies/MLEnemyBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GrenadeThrowAnimation_MetaData[] = {
		{ "Category", "Animation Montages" },
		{ "ModuleRelativePath", "AI/MLAI/Enemies/MLEnemyBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExplosiveGrenadeClass_MetaData[] = {
		{ "Category", "Grenades" },
		{ "ModuleRelativePath", "AI/MLAI/Enemies/MLEnemyBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExplosiveGrenade_MetaData[] = {
		{ "ModuleRelativePath", "AI/MLAI/Enemies/MLEnemyBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_iExplosiveGrenadeAmount_MetaData[] = {
		{ "Category", "Grenades" },
		{ "ModuleRelativePath", "AI/MLAI/Enemies/MLEnemyBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_iFlashGrenadeAmount_MetaData[] = {
		{ "Category", "Grenades" },
		{ "ModuleRelativePath", "AI/MLAI/Enemies/MLEnemyBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SplineControllerStore_MetaData[] = {
		{ "ModuleRelativePath", "AI/MLAI/Enemies/MLEnemyBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TrainingTarget_MetaData[] = {
		{ "Category", "MLEnemyBase" },
		{ "ModuleRelativePath", "AI/MLAI/Enemies/MLEnemyBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SniperClass_MetaData[] = {
		{ "Category", "MLEnemyBase" },
		{ "ModuleRelativePath", "AI/MLAI/Enemies/MLEnemyBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SniperRifle_MetaData[] = {
		{ "ModuleRelativePath", "AI/MLAI/Enemies/MLEnemyBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnimInstance_MetaData[] = {
		{ "ModuleRelativePath", "AI/MLAI/Enemies/MLEnemyBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemySpline_MetaData[] = {
		{ "Category", "Spline" },
		{ "ModuleRelativePath", "AI/MLAI/Enemies/MLEnemyBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_fHealth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_fDefaultSpeed;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FiringAnimation;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReloadAnimation;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DeathAnimation;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GrenadeThrowAnimation;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ExplosiveGrenadeClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ExplosiveGrenade;
	static const UECodeGen_Private::FIntPropertyParams NewProp_iExplosiveGrenadeAmount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_iFlashGrenadeAmount;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SplineControllerStore_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SplineControllerStore;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TrainingTarget;
	static const UECodeGen_Private::FClassPropertyParams NewProp_SniperClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SniperRifle;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AnimInstance;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EnemySpline;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AMLEnemyBase_getWeapon, "getWeapon" }, // 2054629662
		{ &Z_Construct_UFunction_AMLEnemyBase_ResetToRandomPointOnSpline, "ResetToRandomPointOnSpline" }, // 3245662645
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMLEnemyBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_fHealth = { "fHealth", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMLEnemyBase, fHealth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_fHealth_MetaData), NewProp_fHealth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_fDefaultSpeed = { "fDefaultSpeed", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMLEnemyBase, fDefaultSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_fDefaultSpeed_MetaData), NewProp_fDefaultSpeed_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_FiringAnimation = { "FiringAnimation", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMLEnemyBase, FiringAnimation), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FiringAnimation_MetaData), NewProp_FiringAnimation_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_ReloadAnimation = { "ReloadAnimation", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMLEnemyBase, ReloadAnimation), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReloadAnimation_MetaData), NewProp_ReloadAnimation_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_DeathAnimation = { "DeathAnimation", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMLEnemyBase, DeathAnimation), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeathAnimation_MetaData), NewProp_DeathAnimation_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_GrenadeThrowAnimation = { "GrenadeThrowAnimation", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMLEnemyBase, GrenadeThrowAnimation), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GrenadeThrowAnimation_MetaData), NewProp_GrenadeThrowAnimation_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_ExplosiveGrenadeClass = { "ExplosiveGrenadeClass", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMLEnemyBase, ExplosiveGrenadeClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AExplosiveGrenade_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExplosiveGrenadeClass_MetaData), NewProp_ExplosiveGrenadeClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_ExplosiveGrenade = { "ExplosiveGrenade", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMLEnemyBase, ExplosiveGrenade), Z_Construct_UClass_AExplosiveGrenade_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExplosiveGrenade_MetaData), NewProp_ExplosiveGrenade_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_iExplosiveGrenadeAmount = { "iExplosiveGrenadeAmount", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMLEnemyBase, iExplosiveGrenadeAmount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_iExplosiveGrenadeAmount_MetaData), NewProp_iExplosiveGrenadeAmount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_iFlashGrenadeAmount = { "iFlashGrenadeAmount", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMLEnemyBase, iFlashGrenadeAmount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_iFlashGrenadeAmount_MetaData), NewProp_iFlashGrenadeAmount_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_SplineControllerStore_Inner = { "SplineControllerStore", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ASplineController_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_SplineControllerStore = { "SplineControllerStore", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMLEnemyBase, SplineControllerStore), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SplineControllerStore_MetaData), NewProp_SplineControllerStore_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_TrainingTarget = { "TrainingTarget", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMLEnemyBase, TrainingTarget), Z_Construct_UClass_AMyActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TrainingTarget_MetaData), NewProp_TrainingTarget_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_SniperClass = { "SniperClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMLEnemyBase, SniperClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ASniperRifle_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SniperClass_MetaData), NewProp_SniperClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_SniperRifle = { "SniperRifle", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMLEnemyBase, SniperRifle), Z_Construct_UClass_ASniperRifle_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SniperRifle_MetaData), NewProp_SniperRifle_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_AnimInstance = { "AnimInstance", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMLEnemyBase, AnimInstance), Z_Construct_UClass_UAnimInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnimInstance_MetaData), NewProp_AnimInstance_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_EnemySpline = { "EnemySpline", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMLEnemyBase, EnemySpline), Z_Construct_UClass_ASplineController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemySpline_MetaData), NewProp_EnemySpline_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMLEnemyBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_fHealth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_fDefaultSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_FiringAnimation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_ReloadAnimation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_DeathAnimation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_GrenadeThrowAnimation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_ExplosiveGrenadeClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_ExplosiveGrenade,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_iExplosiveGrenadeAmount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_iFlashGrenadeAmount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_SplineControllerStore_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_SplineControllerStore,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_TrainingTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_SniperClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_SniperRifle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_AnimInstance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMLEnemyBase_Statics::NewProp_EnemySpline,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMLEnemyBase_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMLEnemyBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_SearchAndRescue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMLEnemyBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMLEnemyBase_Statics::ClassParams = {
	&AMLEnemyBase::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AMLEnemyBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AMLEnemyBase_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMLEnemyBase_Statics::Class_MetaDataParams), Z_Construct_UClass_AMLEnemyBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMLEnemyBase()
{
	if (!Z_Registration_Info_UClass_AMLEnemyBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMLEnemyBase.OuterSingleton, Z_Construct_UClass_AMLEnemyBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMLEnemyBase.OuterSingleton;
}
template<> SEARCHANDRESCUE_API UClass* StaticClass<AMLEnemyBase>()
{
	return AMLEnemyBase::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMLEnemyBase);
AMLEnemyBase::~AMLEnemyBase() {}
// End Class AMLEnemyBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_Enemies_MLEnemyBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMLEnemyBase, AMLEnemyBase::StaticClass, TEXT("AMLEnemyBase"), &Z_Registration_Info_UClass_AMLEnemyBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMLEnemyBase), 1275958357U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_Enemies_MLEnemyBase_h_510931653(TEXT("/Script/SearchAndRescue"),
	Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_Enemies_MLEnemyBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_Enemies_MLEnemyBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
