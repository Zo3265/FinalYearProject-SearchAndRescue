// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SearchAndRescue/Weapons/GrenadeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGrenadeBase() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UProjectileMovementComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AGrenadeBase();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AGrenadeBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_SearchAndRescue();
// End Cross Module References

// Begin Class AGrenadeBase
void AGrenadeBase::StaticRegisterNativesAGrenadeBase()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGrenadeBase);
UClass* Z_Construct_UClass_AGrenadeBase_NoRegister()
{
	return AGrenadeBase::StaticClass();
}
struct Z_Construct_UClass_AGrenadeBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Weapons/GrenadeBase.h" },
		{ "ModuleRelativePath", "Weapons/GrenadeBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[] = {
		{ "Category", "default" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Weapons/GrenadeBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileMovement_MetaData[] = {
		{ "Category", "Movement" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Weapons/GrenadeBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_fDamage_MetaData[] = {
		{ "Category", "Variables" },
		{ "ModuleRelativePath", "Weapons/GrenadeBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_finitSpeed_MetaData[] = {
		{ "Category", "Variables" },
		{ "ModuleRelativePath", "Weapons/GrenadeBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_fFuseTime_MetaData[] = {
		{ "Category", "Variables" },
		{ "ModuleRelativePath", "Weapons/GrenadeBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_iAmount_MetaData[] = {
		{ "Category", "Bullet Variables" },
		{ "ModuleRelativePath", "Weapons/GrenadeBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Mesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ProjectileMovement;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_fDamage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_finitSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_fFuseTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_iAmount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGrenadeBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGrenadeBase_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGrenadeBase, Mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mesh_MetaData), NewProp_Mesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGrenadeBase_Statics::NewProp_ProjectileMovement = { "ProjectileMovement", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGrenadeBase, ProjectileMovement), Z_Construct_UClass_UProjectileMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileMovement_MetaData), NewProp_ProjectileMovement_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGrenadeBase_Statics::NewProp_fDamage = { "fDamage", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGrenadeBase, fDamage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_fDamage_MetaData), NewProp_fDamage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGrenadeBase_Statics::NewProp_finitSpeed = { "finitSpeed", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGrenadeBase, finitSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_finitSpeed_MetaData), NewProp_finitSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGrenadeBase_Statics::NewProp_fFuseTime = { "fFuseTime", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGrenadeBase, fFuseTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_fFuseTime_MetaData), NewProp_fFuseTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGrenadeBase_Statics::NewProp_iAmount = { "iAmount", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGrenadeBase, iAmount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_iAmount_MetaData), NewProp_iAmount_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGrenadeBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGrenadeBase_Statics::NewProp_Mesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGrenadeBase_Statics::NewProp_ProjectileMovement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGrenadeBase_Statics::NewProp_fDamage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGrenadeBase_Statics::NewProp_finitSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGrenadeBase_Statics::NewProp_fFuseTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGrenadeBase_Statics::NewProp_iAmount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGrenadeBase_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AGrenadeBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_SearchAndRescue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGrenadeBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AGrenadeBase_Statics::ClassParams = {
	&AGrenadeBase::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AGrenadeBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AGrenadeBase_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGrenadeBase_Statics::Class_MetaDataParams), Z_Construct_UClass_AGrenadeBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AGrenadeBase()
{
	if (!Z_Registration_Info_UClass_AGrenadeBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGrenadeBase.OuterSingleton, Z_Construct_UClass_AGrenadeBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AGrenadeBase.OuterSingleton;
}
template<> SEARCHANDRESCUE_API UClass* StaticClass<AGrenadeBase>()
{
	return AGrenadeBase::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AGrenadeBase);
AGrenadeBase::~AGrenadeBase() {}
// End Class AGrenadeBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_Weapons_GrenadeBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGrenadeBase, AGrenadeBase::StaticClass, TEXT("AGrenadeBase"), &Z_Registration_Info_UClass_AGrenadeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGrenadeBase), 230811537U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_Weapons_GrenadeBase_h_2945041094(TEXT("/Script/SearchAndRescue"),
	Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_Weapons_GrenadeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_Weapons_GrenadeBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
