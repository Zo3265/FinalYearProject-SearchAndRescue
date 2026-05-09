// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SearchAndRescue/AI/SplineController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSplineController() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USplineComponent_NoRegister();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_ASplineController();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_ASplineController_NoRegister();
UPackage* Z_Construct_UPackage__Script_SearchAndRescue();
// End Cross Module References

// Begin Class ASplineController
void ASplineController::StaticRegisterNativesASplineController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASplineController);
UClass* Z_Construct_UClass_ASplineController_NoRegister()
{
	return ASplineController::StaticClass();
}
struct Z_Construct_UClass_ASplineController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AI/SplineController.h" },
		{ "ModuleRelativePath", "AI/SplineController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Root_MetaData[] = {
		{ "Category", "SplineController" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "AI/SplineController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Spline_MetaData[] = {
		{ "Category", "SplineController" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "AI/SplineController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalPathTimeController_MetaData[] = {
		{ "Category", "SplineController" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Controls the speed that an actor takes the spline. Lower values = faster. Larger = slower.\n" },
#endif
		{ "ModuleRelativePath", "AI/SplineController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Controls the speed that an actor takes the spline. Lower values = faster. Larger = slower." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Root;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Spline;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TotalPathTimeController;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASplineController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASplineController_Statics::NewProp_Root = { "Root", nullptr, (EPropertyFlags)0x00200800000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASplineController, Root), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Root_MetaData), NewProp_Root_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASplineController_Statics::NewProp_Spline = { "Spline", nullptr, (EPropertyFlags)0x00200800000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASplineController, Spline), Z_Construct_UClass_USplineComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Spline_MetaData), NewProp_Spline_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASplineController_Statics::NewProp_TotalPathTimeController = { "TotalPathTimeController", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASplineController, TotalPathTimeController), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalPathTimeController_MetaData), NewProp_TotalPathTimeController_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASplineController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASplineController_Statics::NewProp_Root,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASplineController_Statics::NewProp_Spline,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASplineController_Statics::NewProp_TotalPathTimeController,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASplineController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ASplineController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_SearchAndRescue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASplineController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASplineController_Statics::ClassParams = {
	&ASplineController::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ASplineController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ASplineController_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASplineController_Statics::Class_MetaDataParams), Z_Construct_UClass_ASplineController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ASplineController()
{
	if (!Z_Registration_Info_UClass_ASplineController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASplineController.OuterSingleton, Z_Construct_UClass_ASplineController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASplineController.OuterSingleton;
}
template<> SEARCHANDRESCUE_API UClass* StaticClass<ASplineController>()
{
	return ASplineController::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ASplineController);
ASplineController::~ASplineController() {}
// End Class ASplineController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_SplineController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASplineController, ASplineController::StaticClass, TEXT("ASplineController"), &Z_Registration_Info_UClass_ASplineController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASplineController), 3507052790U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_SplineController_h_3064835089(TEXT("/Script/SearchAndRescue"),
	Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_SplineController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_SplineController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
