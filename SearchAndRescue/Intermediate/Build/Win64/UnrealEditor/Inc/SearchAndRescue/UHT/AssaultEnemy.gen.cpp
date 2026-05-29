// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SearchAndRescue/AI/BTAI/AssaultEnemy/AssaultEnemy.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAssaultEnemy() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AAssaultEnemy();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AAssaultEnemy_NoRegister();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AAssaultRifle_NoRegister();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AEnemyBase();
UPackage* Z_Construct_UPackage__Script_SearchAndRescue();
// End Cross Module References

// Begin Class AAssaultEnemy
void AAssaultEnemy::StaticRegisterNativesAAssaultEnemy()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AAssaultEnemy);
UClass* Z_Construct_UClass_AAssaultEnemy_NoRegister()
{
	return AAssaultEnemy::StaticClass();
}
struct Z_Construct_UClass_AAssaultEnemy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "AI/BTAI/AssaultEnemy/AssaultEnemy.h" },
		{ "ModuleRelativePath", "AI/BTAI/AssaultEnemy/AssaultEnemy.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssaultClass_MetaData[] = {
		{ "Category", "Weapons" },
		{ "ModuleRelativePath", "AI/BTAI/AssaultEnemy/AssaultEnemy.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssaultRifle_MetaData[] = {
		{ "ModuleRelativePath", "AI/BTAI/AssaultEnemy/AssaultEnemy.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_AssaultClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AssaultRifle;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAssaultEnemy>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AAssaultEnemy_Statics::NewProp_AssaultClass = { "AssaultClass", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAssaultEnemy, AssaultClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AAssaultRifle_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssaultClass_MetaData), NewProp_AssaultClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAssaultEnemy_Statics::NewProp_AssaultRifle = { "AssaultRifle", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAssaultEnemy, AssaultRifle), Z_Construct_UClass_AAssaultRifle_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssaultRifle_MetaData), NewProp_AssaultRifle_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AAssaultEnemy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAssaultEnemy_Statics::NewProp_AssaultClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAssaultEnemy_Statics::NewProp_AssaultRifle,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAssaultEnemy_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AAssaultEnemy_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AEnemyBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SearchAndRescue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAssaultEnemy_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AAssaultEnemy_Statics::ClassParams = {
	&AAssaultEnemy::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AAssaultEnemy_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AAssaultEnemy_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAssaultEnemy_Statics::Class_MetaDataParams), Z_Construct_UClass_AAssaultEnemy_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AAssaultEnemy()
{
	if (!Z_Registration_Info_UClass_AAssaultEnemy.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAssaultEnemy.OuterSingleton, Z_Construct_UClass_AAssaultEnemy_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AAssaultEnemy.OuterSingleton;
}
template<> SEARCHANDRESCUE_API UClass* StaticClass<AAssaultEnemy>()
{
	return AAssaultEnemy::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AAssaultEnemy);
AAssaultEnemy::~AAssaultEnemy() {}
// End Class AAssaultEnemy

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_AssaultEnemy_AssaultEnemy_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AAssaultEnemy, AAssaultEnemy::StaticClass, TEXT("AAssaultEnemy"), &Z_Registration_Info_UClass_AAssaultEnemy, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAssaultEnemy), 4033839369U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_AssaultEnemy_AssaultEnemy_h_2643046112(TEXT("/Script/SearchAndRescue"),
	Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_AssaultEnemy_AssaultEnemy_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_AssaultEnemy_AssaultEnemy_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
