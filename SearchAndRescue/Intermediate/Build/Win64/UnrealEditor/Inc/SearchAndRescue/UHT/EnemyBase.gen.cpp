// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SearchAndRescue/AI/BTAI/EnemyBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemyBase() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UAnimInstance_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AEnemyBase();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AEnemyBase_NoRegister();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AExplosiveGrenade_NoRegister();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_ASplineController_NoRegister();
UPackage* Z_Construct_UPackage__Script_SearchAndRescue();
// End Cross Module References

// Begin Class AEnemyBase Function OnGrenadeRelease
struct Z_Construct_UFunction_AEnemyBase_OnGrenadeRelease_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "AI/BTAI/EnemyBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemyBase_OnGrenadeRelease_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemyBase, nullptr, "OnGrenadeRelease", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemyBase_OnGrenadeRelease_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEnemyBase_OnGrenadeRelease_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AEnemyBase_OnGrenadeRelease()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEnemyBase_OnGrenadeRelease_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEnemyBase::execOnGrenadeRelease)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnGrenadeRelease();
	P_NATIVE_END;
}
// End Class AEnemyBase Function OnGrenadeRelease

// Begin Class AEnemyBase Function OnGrenadeThrowFinished
struct Z_Construct_UFunction_AEnemyBase_OnGrenadeThrowFinished_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "AI/BTAI/EnemyBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemyBase_OnGrenadeThrowFinished_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemyBase, nullptr, "OnGrenadeThrowFinished", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemyBase_OnGrenadeThrowFinished_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEnemyBase_OnGrenadeThrowFinished_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AEnemyBase_OnGrenadeThrowFinished()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEnemyBase_OnGrenadeThrowFinished_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEnemyBase::execOnGrenadeThrowFinished)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnGrenadeThrowFinished();
	P_NATIVE_END;
}
// End Class AEnemyBase Function OnGrenadeThrowFinished

// Begin Class AEnemyBase
void AEnemyBase::StaticRegisterNativesAEnemyBase()
{
	UClass* Class = AEnemyBase::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnGrenadeRelease", &AEnemyBase::execOnGrenadeRelease },
		{ "OnGrenadeThrowFinished", &AEnemyBase::execOnGrenadeThrowFinished },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEnemyBase);
UClass* Z_Construct_UClass_AEnemyBase_NoRegister()
{
	return AEnemyBase::StaticClass();
}
struct Z_Construct_UClass_AEnemyBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "AI/BTAI/EnemyBase.h" },
		{ "ModuleRelativePath", "AI/BTAI/EnemyBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_splineController_MetaData[] = {
		{ "Category", "Path" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Spline that we set for a specific enemy to follow.\n" },
#endif
		{ "ModuleRelativePath", "AI/BTAI/EnemyBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Spline that we set for a specific enemy to follow." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SphereStore_MetaData[] = {
		{ "ModuleRelativePath", "AI/BTAI/EnemyBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_fHealth_MetaData[] = {
		{ "Category", "Base Variables" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Stores the sphere of the enemey.\n" },
#endif
		{ "ModuleRelativePath", "AI/BTAI/EnemyBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stores the sphere of the enemey." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_fDefaultSpeed_MetaData[] = {
		{ "Category", "Base Variables" },
		{ "ModuleRelativePath", "AI/BTAI/EnemyBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FiringAnimation_MetaData[] = {
		{ "Category", "Animation Montages" },
		{ "ModuleRelativePath", "AI/BTAI/EnemyBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReloadAnimation_MetaData[] = {
		{ "Category", "Animation Montages" },
		{ "ModuleRelativePath", "AI/BTAI/EnemyBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeathAnimation_MetaData[] = {
		{ "Category", "Animation Montages" },
		{ "ModuleRelativePath", "AI/BTAI/EnemyBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GrenadeThrowAnimation_MetaData[] = {
		{ "Category", "Animation Montages" },
		{ "ModuleRelativePath", "AI/BTAI/EnemyBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExplosiveGrenadeClass_MetaData[] = {
		{ "Category", "Grenades" },
		{ "ModuleRelativePath", "AI/BTAI/EnemyBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExplosiveGrenade_MetaData[] = {
		{ "ModuleRelativePath", "AI/BTAI/EnemyBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_iExplosiveGrenadeAmount_MetaData[] = {
		{ "Category", "Grenades" },
		{ "ModuleRelativePath", "AI/BTAI/EnemyBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_iFlashGrenadeAmount_MetaData[] = {
		{ "Category", "Grenades" },
		{ "ModuleRelativePath", "AI/BTAI/EnemyBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnimInstance_MetaData[] = {
		{ "ModuleRelativePath", "AI/BTAI/EnemyBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_splineController;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SphereStore;
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
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AnimInstance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AEnemyBase_OnGrenadeRelease, "OnGrenadeRelease" }, // 1342661997
		{ &Z_Construct_UFunction_AEnemyBase_OnGrenadeThrowFinished, "OnGrenadeThrowFinished" }, // 2944269651
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemyBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemyBase_Statics::NewProp_splineController = { "splineController", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemyBase, splineController), Z_Construct_UClass_ASplineController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_splineController_MetaData), NewProp_splineController_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemyBase_Statics::NewProp_SphereStore = { "SphereStore", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemyBase, SphereStore), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SphereStore_MetaData), NewProp_SphereStore_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEnemyBase_Statics::NewProp_fHealth = { "fHealth", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemyBase, fHealth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_fHealth_MetaData), NewProp_fHealth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEnemyBase_Statics::NewProp_fDefaultSpeed = { "fDefaultSpeed", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemyBase, fDefaultSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_fDefaultSpeed_MetaData), NewProp_fDefaultSpeed_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemyBase_Statics::NewProp_FiringAnimation = { "FiringAnimation", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemyBase, FiringAnimation), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FiringAnimation_MetaData), NewProp_FiringAnimation_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemyBase_Statics::NewProp_ReloadAnimation = { "ReloadAnimation", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemyBase, ReloadAnimation), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReloadAnimation_MetaData), NewProp_ReloadAnimation_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemyBase_Statics::NewProp_DeathAnimation = { "DeathAnimation", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemyBase, DeathAnimation), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeathAnimation_MetaData), NewProp_DeathAnimation_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemyBase_Statics::NewProp_GrenadeThrowAnimation = { "GrenadeThrowAnimation", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemyBase, GrenadeThrowAnimation), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GrenadeThrowAnimation_MetaData), NewProp_GrenadeThrowAnimation_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AEnemyBase_Statics::NewProp_ExplosiveGrenadeClass = { "ExplosiveGrenadeClass", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemyBase, ExplosiveGrenadeClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AExplosiveGrenade_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExplosiveGrenadeClass_MetaData), NewProp_ExplosiveGrenadeClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemyBase_Statics::NewProp_ExplosiveGrenade = { "ExplosiveGrenade", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemyBase, ExplosiveGrenade), Z_Construct_UClass_AExplosiveGrenade_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExplosiveGrenade_MetaData), NewProp_ExplosiveGrenade_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AEnemyBase_Statics::NewProp_iExplosiveGrenadeAmount = { "iExplosiveGrenadeAmount", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemyBase, iExplosiveGrenadeAmount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_iExplosiveGrenadeAmount_MetaData), NewProp_iExplosiveGrenadeAmount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AEnemyBase_Statics::NewProp_iFlashGrenadeAmount = { "iFlashGrenadeAmount", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemyBase, iFlashGrenadeAmount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_iFlashGrenadeAmount_MetaData), NewProp_iFlashGrenadeAmount_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemyBase_Statics::NewProp_AnimInstance = { "AnimInstance", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemyBase, AnimInstance), Z_Construct_UClass_UAnimInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnimInstance_MetaData), NewProp_AnimInstance_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEnemyBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyBase_Statics::NewProp_splineController,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyBase_Statics::NewProp_SphereStore,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyBase_Statics::NewProp_fHealth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyBase_Statics::NewProp_fDefaultSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyBase_Statics::NewProp_FiringAnimation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyBase_Statics::NewProp_ReloadAnimation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyBase_Statics::NewProp_DeathAnimation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyBase_Statics::NewProp_GrenadeThrowAnimation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyBase_Statics::NewProp_ExplosiveGrenadeClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyBase_Statics::NewProp_ExplosiveGrenade,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyBase_Statics::NewProp_iExplosiveGrenadeAmount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyBase_Statics::NewProp_iFlashGrenadeAmount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyBase_Statics::NewProp_AnimInstance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyBase_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEnemyBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_SearchAndRescue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEnemyBase_Statics::ClassParams = {
	&AEnemyBase::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AEnemyBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyBase_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyBase_Statics::Class_MetaDataParams), Z_Construct_UClass_AEnemyBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEnemyBase()
{
	if (!Z_Registration_Info_UClass_AEnemyBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEnemyBase.OuterSingleton, Z_Construct_UClass_AEnemyBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEnemyBase.OuterSingleton;
}
template<> SEARCHANDRESCUE_API UClass* StaticClass<AEnemyBase>()
{
	return AEnemyBase::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemyBase);
AEnemyBase::~AEnemyBase() {}
// End Class AEnemyBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_EnemyBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEnemyBase, AEnemyBase::StaticClass, TEXT("AEnemyBase"), &Z_Registration_Info_UClass_AEnemyBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEnemyBase), 1069313035U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_EnemyBase_h_2265850057(TEXT("/Script/SearchAndRescue"),
	Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_EnemyBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_EnemyBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
