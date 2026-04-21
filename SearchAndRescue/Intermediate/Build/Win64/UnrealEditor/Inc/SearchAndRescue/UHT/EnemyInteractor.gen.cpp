// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SearchAndRescue/AI/MLAI/EnemyInteractor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemyInteractor() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_USplineComponent_NoRegister();
LEARNINGAGENTS_API UClass* Z_Construct_UClass_ULearningAgentsInteractor();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_UEnemyInteractor();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_UEnemyInteractor_NoRegister();
UPackage* Z_Construct_UPackage__Script_SearchAndRescue();
// End Cross Module References

// Begin Class UEnemyInteractor
void UEnemyInteractor::StaticRegisterNativesUEnemyInteractor()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UEnemyInteractor);
UClass* Z_Construct_UClass_UEnemyInteractor_NoRegister()
{
	return UEnemyInteractor::StaticClass();
}
struct Z_Construct_UClass_UEnemyInteractor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AI/MLAI/EnemyInteractor.h" },
		{ "ModuleRelativePath", "AI/MLAI/EnemyInteractor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractorSplineComponent_MetaData[] = {
		{ "Category", "Spline" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "AI/MLAI/EnemyInteractor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InteractorSplineComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEnemyInteractor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEnemyInteractor_Statics::NewProp_InteractorSplineComponent = { "InteractorSplineComponent", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEnemyInteractor, InteractorSplineComponent), Z_Construct_UClass_USplineComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractorSplineComponent_MetaData), NewProp_InteractorSplineComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEnemyInteractor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyInteractor_Statics::NewProp_InteractorSplineComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyInteractor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEnemyInteractor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ULearningAgentsInteractor,
	(UObject* (*)())Z_Construct_UPackage__Script_SearchAndRescue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyInteractor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEnemyInteractor_Statics::ClassParams = {
	&UEnemyInteractor::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UEnemyInteractor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyInteractor_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyInteractor_Statics::Class_MetaDataParams), Z_Construct_UClass_UEnemyInteractor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEnemyInteractor()
{
	if (!Z_Registration_Info_UClass_UEnemyInteractor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEnemyInteractor.OuterSingleton, Z_Construct_UClass_UEnemyInteractor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEnemyInteractor.OuterSingleton;
}
template<> SEARCHANDRESCUE_API UClass* StaticClass<UEnemyInteractor>()
{
	return UEnemyInteractor::StaticClass();
}
UEnemyInteractor::UEnemyInteractor() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEnemyInteractor);
UEnemyInteractor::~UEnemyInteractor() {}
// End Class UEnemyInteractor

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyInteractor_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEnemyInteractor, UEnemyInteractor::StaticClass, TEXT("UEnemyInteractor"), &Z_Registration_Info_UClass_UEnemyInteractor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEnemyInteractor), 89743593U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyInteractor_h_3780552843(TEXT("/Script/SearchAndRescue"),
	Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyInteractor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyInteractor_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
