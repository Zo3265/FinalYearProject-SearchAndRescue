// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SearchAndRescue/Weapons/AssaultRifle.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAssaultRifle() {}

// Begin Cross Module References
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AAssaultRifle();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AAssaultRifle_NoRegister();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AWeaponBase();
UPackage* Z_Construct_UPackage__Script_SearchAndRescue();
// End Cross Module References

// Begin Class AAssaultRifle
void AAssaultRifle::StaticRegisterNativesAAssaultRifle()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AAssaultRifle);
UClass* Z_Construct_UClass_AAssaultRifle_NoRegister()
{
	return AAssaultRifle::StaticClass();
}
struct Z_Construct_UClass_AAssaultRifle_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Weapons/AssaultRifle.h" },
		{ "ModuleRelativePath", "Weapons/AssaultRifle.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAssaultRifle>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AAssaultRifle_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AWeaponBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SearchAndRescue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAssaultRifle_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AAssaultRifle_Statics::ClassParams = {
	&AAssaultRifle::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAssaultRifle_Statics::Class_MetaDataParams), Z_Construct_UClass_AAssaultRifle_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AAssaultRifle()
{
	if (!Z_Registration_Info_UClass_AAssaultRifle.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAssaultRifle.OuterSingleton, Z_Construct_UClass_AAssaultRifle_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AAssaultRifle.OuterSingleton;
}
template<> SEARCHANDRESCUE_API UClass* StaticClass<AAssaultRifle>()
{
	return AAssaultRifle::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AAssaultRifle);
AAssaultRifle::~AAssaultRifle() {}
// End Class AAssaultRifle

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_Weapons_AssaultRifle_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AAssaultRifle, AAssaultRifle::StaticClass, TEXT("AAssaultRifle"), &Z_Registration_Info_UClass_AAssaultRifle, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAssaultRifle), 3331928390U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_Weapons_AssaultRifle_h_3035847547(TEXT("/Script/SearchAndRescue"),
	Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_Weapons_AssaultRifle_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_Weapons_AssaultRifle_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
