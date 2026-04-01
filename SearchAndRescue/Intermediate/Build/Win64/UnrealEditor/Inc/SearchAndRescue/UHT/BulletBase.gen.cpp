// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SearchAndRescue/Weapons/BulletBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBulletBase() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_ABulletBase();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_ABulletBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_SearchAndRescue();
// End Cross Module References

// Begin Class ABulletBase
void ABulletBase::StaticRegisterNativesABulletBase()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABulletBase);
UClass* Z_Construct_UClass_ABulletBase_NoRegister()
{
	return ABulletBase::StaticClass();
}
struct Z_Construct_UClass_ABulletBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Weapons/BulletBase.h" },
		{ "ModuleRelativePath", "Weapons/BulletBase.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABulletBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ABulletBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_SearchAndRescue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABulletBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABulletBase_Statics::ClassParams = {
	&ABulletBase::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABulletBase_Statics::Class_MetaDataParams), Z_Construct_UClass_ABulletBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABulletBase()
{
	if (!Z_Registration_Info_UClass_ABulletBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABulletBase.OuterSingleton, Z_Construct_UClass_ABulletBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABulletBase.OuterSingleton;
}
template<> SEARCHANDRESCUE_API UClass* StaticClass<ABulletBase>()
{
	return ABulletBase::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABulletBase);
ABulletBase::~ABulletBase() {}
// End Class ABulletBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_Weapons_BulletBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABulletBase, ABulletBase::StaticClass, TEXT("ABulletBase"), &Z_Registration_Info_UClass_ABulletBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABulletBase), 2890946408U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_Weapons_BulletBase_h_3598762941(TEXT("/Script/SearchAndRescue"),
	Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_Weapons_BulletBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_Weapons_BulletBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
