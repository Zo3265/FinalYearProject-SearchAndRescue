// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SearchAndRescue/AI/BTAI/HostageAIController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHostageAIController() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_AAIController();
AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTree_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AHostageAIController();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AHostageAIController_NoRegister();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AHostageChar_NoRegister();
UPackage* Z_Construct_UPackage__Script_SearchAndRescue();
// End Cross Module References

// Begin Class AHostageAIController
void AHostageAIController::StaticRegisterNativesAHostageAIController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AHostageAIController);
UClass* Z_Construct_UClass_AHostageAIController_NoRegister()
{
	return AHostageAIController::StaticClass();
}
struct Z_Construct_UClass_AHostageAIController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "AI/BTAI/HostageAIController.h" },
		{ "ModuleRelativePath", "AI/BTAI/HostageAIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hostage_MetaData[] = {
		{ "ModuleRelativePath", "AI/BTAI/HostageAIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerPawn_MetaData[] = {
		{ "ModuleRelativePath", "AI/BTAI/HostageAIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AIBehavior_MetaData[] = {
		{ "Category", "HostageAIController" },
		{ "ModuleRelativePath", "AI/BTAI/HostageAIController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Hostage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerPawn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AIBehavior;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHostageAIController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHostageAIController_Statics::NewProp_Hostage = { "Hostage", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHostageAIController, Hostage), Z_Construct_UClass_AHostageChar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hostage_MetaData), NewProp_Hostage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHostageAIController_Statics::NewProp_PlayerPawn = { "PlayerPawn", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHostageAIController, PlayerPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerPawn_MetaData), NewProp_PlayerPawn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHostageAIController_Statics::NewProp_AIBehavior = { "AIBehavior", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHostageAIController, AIBehavior), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AIBehavior_MetaData), NewProp_AIBehavior_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AHostageAIController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHostageAIController_Statics::NewProp_Hostage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHostageAIController_Statics::NewProp_PlayerPawn,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHostageAIController_Statics::NewProp_AIBehavior,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHostageAIController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AHostageAIController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AAIController,
	(UObject* (*)())Z_Construct_UPackage__Script_SearchAndRescue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHostageAIController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AHostageAIController_Statics::ClassParams = {
	&AHostageAIController::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AHostageAIController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AHostageAIController_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHostageAIController_Statics::Class_MetaDataParams), Z_Construct_UClass_AHostageAIController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AHostageAIController()
{
	if (!Z_Registration_Info_UClass_AHostageAIController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AHostageAIController.OuterSingleton, Z_Construct_UClass_AHostageAIController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AHostageAIController.OuterSingleton;
}
template<> SEARCHANDRESCUE_API UClass* StaticClass<AHostageAIController>()
{
	return AHostageAIController::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AHostageAIController);
AHostageAIController::~AHostageAIController() {}
// End Class AHostageAIController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_HostageAIController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AHostageAIController, AHostageAIController::StaticClass, TEXT("AHostageAIController"), &Z_Registration_Info_UClass_AHostageAIController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AHostageAIController), 2906205245U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_HostageAIController_h_157070757(TEXT("/Script/SearchAndRescue"),
	Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_HostageAIController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_HostageAIController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
