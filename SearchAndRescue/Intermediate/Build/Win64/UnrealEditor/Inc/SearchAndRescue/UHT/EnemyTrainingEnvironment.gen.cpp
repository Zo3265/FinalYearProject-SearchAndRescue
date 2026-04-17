// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SearchAndRescue/AI/MLAI/EnemyTrainingEnvironment.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemyTrainingEnvironment() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_USplineComponent_NoRegister();
LEARNINGAGENTSTRAINING_API UClass* Z_Construct_UClass_ULearningAgentsTrainingEnvironment();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_UEnemyTrainingEnvironment();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_UEnemyTrainingEnvironment_NoRegister();
UPackage* Z_Construct_UPackage__Script_SearchAndRescue();
// End Cross Module References

// Begin Class UEnemyTrainingEnvironment
void UEnemyTrainingEnvironment::StaticRegisterNativesUEnemyTrainingEnvironment()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UEnemyTrainingEnvironment);
UClass* Z_Construct_UClass_UEnemyTrainingEnvironment_NoRegister()
{
	return UEnemyTrainingEnvironment::StaticClass();
}
struct Z_Construct_UClass_UEnemyTrainingEnvironment_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AI/MLAI/EnemyTrainingEnvironment.h" },
		{ "ModuleRelativePath", "AI/MLAI/EnemyTrainingEnvironment.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TrainingEnvSplineComponent_MetaData[] = {
		{ "Category", "Spline" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "AI/MLAI/EnemyTrainingEnvironment.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TrainingEnvSplineComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEnemyTrainingEnvironment>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEnemyTrainingEnvironment_Statics::NewProp_TrainingEnvSplineComponent = { "TrainingEnvSplineComponent", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEnemyTrainingEnvironment, TrainingEnvSplineComponent), Z_Construct_UClass_USplineComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TrainingEnvSplineComponent_MetaData), NewProp_TrainingEnvSplineComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEnemyTrainingEnvironment_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyTrainingEnvironment_Statics::NewProp_TrainingEnvSplineComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyTrainingEnvironment_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEnemyTrainingEnvironment_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ULearningAgentsTrainingEnvironment,
	(UObject* (*)())Z_Construct_UPackage__Script_SearchAndRescue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyTrainingEnvironment_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEnemyTrainingEnvironment_Statics::ClassParams = {
	&UEnemyTrainingEnvironment::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UEnemyTrainingEnvironment_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyTrainingEnvironment_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyTrainingEnvironment_Statics::Class_MetaDataParams), Z_Construct_UClass_UEnemyTrainingEnvironment_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEnemyTrainingEnvironment()
{
	if (!Z_Registration_Info_UClass_UEnemyTrainingEnvironment.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEnemyTrainingEnvironment.OuterSingleton, Z_Construct_UClass_UEnemyTrainingEnvironment_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEnemyTrainingEnvironment.OuterSingleton;
}
template<> SEARCHANDRESCUE_API UClass* StaticClass<UEnemyTrainingEnvironment>()
{
	return UEnemyTrainingEnvironment::StaticClass();
}
UEnemyTrainingEnvironment::UEnemyTrainingEnvironment() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEnemyTrainingEnvironment);
UEnemyTrainingEnvironment::~UEnemyTrainingEnvironment() {}
// End Class UEnemyTrainingEnvironment

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyTrainingEnvironment_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEnemyTrainingEnvironment, UEnemyTrainingEnvironment::StaticClass, TEXT("UEnemyTrainingEnvironment"), &Z_Registration_Info_UClass_UEnemyTrainingEnvironment, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEnemyTrainingEnvironment), 1489027283U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyTrainingEnvironment_h_2653134221(TEXT("/Script/SearchAndRescue"),
	Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyTrainingEnvironment_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyTrainingEnvironment_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
