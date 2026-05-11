// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SearchAndRescue/Weapons/ExplosiveGrenade.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeExplosiveGrenade() {}

// Begin Cross Module References
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AExplosiveGrenade();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AExplosiveGrenade_NoRegister();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AGrenadeBase();
UPackage* Z_Construct_UPackage__Script_SearchAndRescue();
// End Cross Module References

// Begin Class AExplosiveGrenade
void AExplosiveGrenade::StaticRegisterNativesAExplosiveGrenade()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AExplosiveGrenade);
UClass* Z_Construct_UClass_AExplosiveGrenade_NoRegister()
{
	return AExplosiveGrenade::StaticClass();
}
struct Z_Construct_UClass_AExplosiveGrenade_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Weapons/ExplosiveGrenade.h" },
		{ "ModuleRelativePath", "Weapons/ExplosiveGrenade.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AExplosiveGrenade>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AExplosiveGrenade_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGrenadeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SearchAndRescue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AExplosiveGrenade_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AExplosiveGrenade_Statics::ClassParams = {
	&AExplosiveGrenade::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AExplosiveGrenade_Statics::Class_MetaDataParams), Z_Construct_UClass_AExplosiveGrenade_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AExplosiveGrenade()
{
	if (!Z_Registration_Info_UClass_AExplosiveGrenade.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AExplosiveGrenade.OuterSingleton, Z_Construct_UClass_AExplosiveGrenade_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AExplosiveGrenade.OuterSingleton;
}
template<> SEARCHANDRESCUE_API UClass* StaticClass<AExplosiveGrenade>()
{
	return AExplosiveGrenade::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AExplosiveGrenade);
AExplosiveGrenade::~AExplosiveGrenade() {}
// End Class AExplosiveGrenade

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_Weapons_ExplosiveGrenade_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AExplosiveGrenade, AExplosiveGrenade::StaticClass, TEXT("AExplosiveGrenade"), &Z_Registration_Info_UClass_AExplosiveGrenade, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AExplosiveGrenade), 1730990054U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_Weapons_ExplosiveGrenade_h_3819027261(TEXT("/Script/SearchAndRescue"),
	Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_Weapons_ExplosiveGrenade_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_Weapons_ExplosiveGrenade_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
