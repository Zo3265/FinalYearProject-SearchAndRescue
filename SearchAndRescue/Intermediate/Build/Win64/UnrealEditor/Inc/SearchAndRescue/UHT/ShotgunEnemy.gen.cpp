// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SearchAndRescue/AI/BTAI/ShotgunEnemy/ShotgunEnemy.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeShotgunEnemy() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AEnemyBase();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AShotgun_NoRegister();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AShotgunEnemy();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AShotgunEnemy_NoRegister();
UPackage* Z_Construct_UPackage__Script_SearchAndRescue();
// End Cross Module References

// Begin Class AShotgunEnemy
void AShotgunEnemy::StaticRegisterNativesAShotgunEnemy()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AShotgunEnemy);
UClass* Z_Construct_UClass_AShotgunEnemy_NoRegister()
{
	return AShotgunEnemy::StaticClass();
}
struct Z_Construct_UClass_AShotgunEnemy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "AI/BTAI/ShotgunEnemy/ShotgunEnemy.h" },
		{ "ModuleRelativePath", "AI/BTAI/ShotgunEnemy/ShotgunEnemy.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShotgunClass_MetaData[] = {
		{ "Category", "Weapons" },
		{ "ModuleRelativePath", "AI/BTAI/ShotgunEnemy/ShotgunEnemy.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Shotgun_MetaData[] = {
		{ "ModuleRelativePath", "AI/BTAI/ShotgunEnemy/ShotgunEnemy.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_ShotgunClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Shotgun;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AShotgunEnemy>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AShotgunEnemy_Statics::NewProp_ShotgunClass = { "ShotgunClass", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShotgunEnemy, ShotgunClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AShotgun_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShotgunClass_MetaData), NewProp_ShotgunClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShotgunEnemy_Statics::NewProp_Shotgun = { "Shotgun", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShotgunEnemy, Shotgun), Z_Construct_UClass_AShotgun_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Shotgun_MetaData), NewProp_Shotgun_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AShotgunEnemy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShotgunEnemy_Statics::NewProp_ShotgunClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShotgunEnemy_Statics::NewProp_Shotgun,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AShotgunEnemy_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AShotgunEnemy_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AEnemyBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SearchAndRescue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AShotgunEnemy_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AShotgunEnemy_Statics::ClassParams = {
	&AShotgunEnemy::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AShotgunEnemy_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AShotgunEnemy_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AShotgunEnemy_Statics::Class_MetaDataParams), Z_Construct_UClass_AShotgunEnemy_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AShotgunEnemy()
{
	if (!Z_Registration_Info_UClass_AShotgunEnemy.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AShotgunEnemy.OuterSingleton, Z_Construct_UClass_AShotgunEnemy_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AShotgunEnemy.OuterSingleton;
}
template<> SEARCHANDRESCUE_API UClass* StaticClass<AShotgunEnemy>()
{
	return AShotgunEnemy::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AShotgunEnemy);
AShotgunEnemy::~AShotgunEnemy() {}
// End Class AShotgunEnemy

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_ShotgunEnemy_ShotgunEnemy_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AShotgunEnemy, AShotgunEnemy::StaticClass, TEXT("AShotgunEnemy"), &Z_Registration_Info_UClass_AShotgunEnemy, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AShotgunEnemy), 2259656284U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_ShotgunEnemy_ShotgunEnemy_h_1905920512(TEXT("/Script/SearchAndRescue"),
	Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_ShotgunEnemy_ShotgunEnemy_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_ShotgunEnemy_ShotgunEnemy_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
