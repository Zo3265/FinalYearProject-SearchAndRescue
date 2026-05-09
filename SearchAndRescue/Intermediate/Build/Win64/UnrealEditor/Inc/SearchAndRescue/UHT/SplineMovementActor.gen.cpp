// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SearchAndRescue/AI/SplineMovementActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSplineMovementActor() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_ASplineMovementActor();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_ASplineMovementActor_NoRegister();
UPackage* Z_Construct_UPackage__Script_SearchAndRescue();
// End Cross Module References

// Begin Class ASplineMovementActor
void ASplineMovementActor::StaticRegisterNativesASplineMovementActor()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASplineMovementActor);
UClass* Z_Construct_UClass_ASplineMovementActor_NoRegister()
{
	return ASplineMovementActor::StaticClass();
}
struct Z_Construct_UClass_ASplineMovementActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AI/SplineMovementActor.h" },
		{ "ModuleRelativePath", "AI/SplineMovementActor.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASplineMovementActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ASplineMovementActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_SearchAndRescue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASplineMovementActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASplineMovementActor_Statics::ClassParams = {
	&ASplineMovementActor::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASplineMovementActor_Statics::Class_MetaDataParams), Z_Construct_UClass_ASplineMovementActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ASplineMovementActor()
{
	if (!Z_Registration_Info_UClass_ASplineMovementActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASplineMovementActor.OuterSingleton, Z_Construct_UClass_ASplineMovementActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASplineMovementActor.OuterSingleton;
}
template<> SEARCHANDRESCUE_API UClass* StaticClass<ASplineMovementActor>()
{
	return ASplineMovementActor::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ASplineMovementActor);
ASplineMovementActor::~ASplineMovementActor() {}
// End Class ASplineMovementActor

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_SplineMovementActor_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASplineMovementActor, ASplineMovementActor::StaticClass, TEXT("ASplineMovementActor"), &Z_Registration_Info_UClass_ASplineMovementActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASplineMovementActor), 3008332721U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_SplineMovementActor_h_1716464788(TEXT("/Script/SearchAndRescue"),
	Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_SplineMovementActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_SplineMovementActor_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
