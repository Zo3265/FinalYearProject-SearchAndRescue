// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SearchAndRescue/AI/BTAI/SniperEnemy.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSniperEnemy() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AEnemyBase();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_ASniperEnemy();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_ASniperEnemy_NoRegister();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_ASniperRifle_NoRegister();
UPackage* Z_Construct_UPackage__Script_SearchAndRescue();
// End Cross Module References

// Begin Class ASniperEnemy
void ASniperEnemy::StaticRegisterNativesASniperEnemy()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASniperEnemy);
UClass* Z_Construct_UClass_ASniperEnemy_NoRegister()
{
	return ASniperEnemy::StaticClass();
}
struct Z_Construct_UClass_ASniperEnemy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "AI/BTAI/SniperEnemy.h" },
		{ "ModuleRelativePath", "AI/BTAI/SniperEnemy.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SniperClass_MetaData[] = {
		{ "Category", "SniperEnemy" },
		{ "ModuleRelativePath", "AI/BTAI/SniperEnemy.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SniperRifle_MetaData[] = {
		{ "ModuleRelativePath", "AI/BTAI/SniperEnemy.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_SniperClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SniperRifle;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASniperEnemy>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ASniperEnemy_Statics::NewProp_SniperClass = { "SniperClass", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASniperEnemy, SniperClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ASniperRifle_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SniperClass_MetaData), NewProp_SniperClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASniperEnemy_Statics::NewProp_SniperRifle = { "SniperRifle", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASniperEnemy, SniperRifle), Z_Construct_UClass_ASniperRifle_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SniperRifle_MetaData), NewProp_SniperRifle_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASniperEnemy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASniperEnemy_Statics::NewProp_SniperClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASniperEnemy_Statics::NewProp_SniperRifle,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASniperEnemy_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ASniperEnemy_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AEnemyBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SearchAndRescue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASniperEnemy_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASniperEnemy_Statics::ClassParams = {
	&ASniperEnemy::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ASniperEnemy_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ASniperEnemy_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASniperEnemy_Statics::Class_MetaDataParams), Z_Construct_UClass_ASniperEnemy_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ASniperEnemy()
{
	if (!Z_Registration_Info_UClass_ASniperEnemy.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASniperEnemy.OuterSingleton, Z_Construct_UClass_ASniperEnemy_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASniperEnemy.OuterSingleton;
}
template<> SEARCHANDRESCUE_API UClass* StaticClass<ASniperEnemy>()
{
	return ASniperEnemy::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ASniperEnemy);
ASniperEnemy::~ASniperEnemy() {}
// End Class ASniperEnemy

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_SniperEnemy_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASniperEnemy, ASniperEnemy::StaticClass, TEXT("ASniperEnemy"), &Z_Registration_Info_UClass_ASniperEnemy, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASniperEnemy), 292301718U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_SniperEnemy_h_3433367844(TEXT("/Script/SearchAndRescue"),
	Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_SniperEnemy_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_SniperEnemy_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
