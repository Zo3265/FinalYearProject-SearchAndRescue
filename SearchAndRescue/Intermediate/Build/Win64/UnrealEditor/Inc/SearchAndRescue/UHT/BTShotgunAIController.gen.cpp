// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SearchAndRescue/AI/BTAI/ShotgunEnemy/BTShotgunAIController.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTShotgunAIController() {}

// Begin Cross Module References
AIMODULE_API UScriptStruct* Z_Construct_UScriptStruct_FAIStimulus();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_ABTEnemyAIControllerBase();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_ABTShotgunAIController();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_ABTShotgunAIController_NoRegister();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AShotgunEnemy_NoRegister();
UPackage* Z_Construct_UPackage__Script_SearchAndRescue();
// End Cross Module References

// Begin Class ABTShotgunAIController Function OnTargetPerceptionUpdated
struct Z_Construct_UFunction_ABTShotgunAIController_OnTargetPerceptionUpdated_Statics
{
	struct BTShotgunAIController_eventOnTargetPerceptionUpdated_Parms
	{
		AActor* Actor;
		FAIStimulus Stimulus;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "AI/BTAI/ShotgunEnemy/BTShotgunAIController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Stimulus;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABTShotgunAIController_OnTargetPerceptionUpdated_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BTShotgunAIController_eventOnTargetPerceptionUpdated_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ABTShotgunAIController_OnTargetPerceptionUpdated_Statics::NewProp_Stimulus = { "Stimulus", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BTShotgunAIController_eventOnTargetPerceptionUpdated_Parms, Stimulus), Z_Construct_UScriptStruct_FAIStimulus, METADATA_PARAMS(0, nullptr) }; // 177100813
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABTShotgunAIController_OnTargetPerceptionUpdated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABTShotgunAIController_OnTargetPerceptionUpdated_Statics::NewProp_Actor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABTShotgunAIController_OnTargetPerceptionUpdated_Statics::NewProp_Stimulus,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ABTShotgunAIController_OnTargetPerceptionUpdated_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABTShotgunAIController_OnTargetPerceptionUpdated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABTShotgunAIController, nullptr, "OnTargetPerceptionUpdated", nullptr, nullptr, Z_Construct_UFunction_ABTShotgunAIController_OnTargetPerceptionUpdated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABTShotgunAIController_OnTargetPerceptionUpdated_Statics::PropPointers), sizeof(Z_Construct_UFunction_ABTShotgunAIController_OnTargetPerceptionUpdated_Statics::BTShotgunAIController_eventOnTargetPerceptionUpdated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABTShotgunAIController_OnTargetPerceptionUpdated_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABTShotgunAIController_OnTargetPerceptionUpdated_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ABTShotgunAIController_OnTargetPerceptionUpdated_Statics::BTShotgunAIController_eventOnTargetPerceptionUpdated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ABTShotgunAIController_OnTargetPerceptionUpdated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABTShotgunAIController_OnTargetPerceptionUpdated_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ABTShotgunAIController::execOnTargetPerceptionUpdated)
{
	P_GET_OBJECT(AActor,Z_Param_Actor);
	P_GET_STRUCT(FAIStimulus,Z_Param_Stimulus);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnTargetPerceptionUpdated(Z_Param_Actor,Z_Param_Stimulus);
	P_NATIVE_END;
}
// End Class ABTShotgunAIController Function OnTargetPerceptionUpdated

// Begin Class ABTShotgunAIController
void ABTShotgunAIController::StaticRegisterNativesABTShotgunAIController()
{
	UClass* Class = ABTShotgunAIController::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnTargetPerceptionUpdated", &ABTShotgunAIController::execOnTargetPerceptionUpdated },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABTShotgunAIController);
UClass* Z_Construct_UClass_ABTShotgunAIController_NoRegister()
{
	return ABTShotgunAIController::StaticClass();
}
struct Z_Construct_UClass_ABTShotgunAIController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "AI/BTAI/ShotgunEnemy/BTShotgunAIController.h" },
		{ "ModuleRelativePath", "AI/BTAI/ShotgunEnemy/BTShotgunAIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShotgunEnemy_MetaData[] = {
		{ "ModuleRelativePath", "AI/BTAI/ShotgunEnemy/BTShotgunAIController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ShotgunEnemy;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ABTShotgunAIController_OnTargetPerceptionUpdated, "OnTargetPerceptionUpdated" }, // 520071948
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABTShotgunAIController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABTShotgunAIController_Statics::NewProp_ShotgunEnemy = { "ShotgunEnemy", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABTShotgunAIController, ShotgunEnemy), Z_Construct_UClass_AShotgunEnemy_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShotgunEnemy_MetaData), NewProp_ShotgunEnemy_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABTShotgunAIController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABTShotgunAIController_Statics::NewProp_ShotgunEnemy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABTShotgunAIController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ABTShotgunAIController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABTEnemyAIControllerBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SearchAndRescue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABTShotgunAIController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABTShotgunAIController_Statics::ClassParams = {
	&ABTShotgunAIController::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ABTShotgunAIController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ABTShotgunAIController_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABTShotgunAIController_Statics::Class_MetaDataParams), Z_Construct_UClass_ABTShotgunAIController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABTShotgunAIController()
{
	if (!Z_Registration_Info_UClass_ABTShotgunAIController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABTShotgunAIController.OuterSingleton, Z_Construct_UClass_ABTShotgunAIController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABTShotgunAIController.OuterSingleton;
}
template<> SEARCHANDRESCUE_API UClass* StaticClass<ABTShotgunAIController>()
{
	return ABTShotgunAIController::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABTShotgunAIController);
ABTShotgunAIController::~ABTShotgunAIController() {}
// End Class ABTShotgunAIController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_ShotgunEnemy_BTShotgunAIController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABTShotgunAIController, ABTShotgunAIController::StaticClass, TEXT("ABTShotgunAIController"), &Z_Registration_Info_UClass_ABTShotgunAIController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABTShotgunAIController), 3348483438U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_ShotgunEnemy_BTShotgunAIController_h_2167423969(TEXT("/Script/SearchAndRescue"),
	Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_ShotgunEnemy_BTShotgunAIController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_ShotgunEnemy_BTShotgunAIController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
