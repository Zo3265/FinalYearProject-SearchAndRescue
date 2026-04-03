// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SearchAndRescue/AI/BTAI/BTEnemyAIControllerBase.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTEnemyAIControllerBase() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_AAIController();
AIMODULE_API UClass* Z_Construct_UClass_UAIPerceptionComponent_NoRegister();
AIMODULE_API UClass* Z_Construct_UClass_UAISenseConfig_Sight_NoRegister();
AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTree_NoRegister();
AIMODULE_API UScriptStruct* Z_Construct_UScriptStruct_FAIStimulus();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UChildActorComponent_NoRegister();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_ABTEnemyAIControllerBase();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_ABTEnemyAIControllerBase_NoRegister();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AEnemyBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_SearchAndRescue();
// End Cross Module References

// Begin Class ABTEnemyAIControllerBase Function OnTargetPerceptionUpdated
struct Z_Construct_UFunction_ABTEnemyAIControllerBase_OnTargetPerceptionUpdated_Statics
{
	struct BTEnemyAIControllerBase_eventOnTargetPerceptionUpdated_Parms
	{
		AActor* Actor;
		FAIStimulus Stimulus;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "AI/BTAI/BTEnemyAIControllerBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Stimulus;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABTEnemyAIControllerBase_OnTargetPerceptionUpdated_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BTEnemyAIControllerBase_eventOnTargetPerceptionUpdated_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ABTEnemyAIControllerBase_OnTargetPerceptionUpdated_Statics::NewProp_Stimulus = { "Stimulus", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BTEnemyAIControllerBase_eventOnTargetPerceptionUpdated_Parms, Stimulus), Z_Construct_UScriptStruct_FAIStimulus, METADATA_PARAMS(0, nullptr) }; // 177100813
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABTEnemyAIControllerBase_OnTargetPerceptionUpdated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABTEnemyAIControllerBase_OnTargetPerceptionUpdated_Statics::NewProp_Actor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABTEnemyAIControllerBase_OnTargetPerceptionUpdated_Statics::NewProp_Stimulus,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ABTEnemyAIControllerBase_OnTargetPerceptionUpdated_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABTEnemyAIControllerBase_OnTargetPerceptionUpdated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABTEnemyAIControllerBase, nullptr, "OnTargetPerceptionUpdated", nullptr, nullptr, Z_Construct_UFunction_ABTEnemyAIControllerBase_OnTargetPerceptionUpdated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABTEnemyAIControllerBase_OnTargetPerceptionUpdated_Statics::PropPointers), sizeof(Z_Construct_UFunction_ABTEnemyAIControllerBase_OnTargetPerceptionUpdated_Statics::BTEnemyAIControllerBase_eventOnTargetPerceptionUpdated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABTEnemyAIControllerBase_OnTargetPerceptionUpdated_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABTEnemyAIControllerBase_OnTargetPerceptionUpdated_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ABTEnemyAIControllerBase_OnTargetPerceptionUpdated_Statics::BTEnemyAIControllerBase_eventOnTargetPerceptionUpdated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ABTEnemyAIControllerBase_OnTargetPerceptionUpdated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABTEnemyAIControllerBase_OnTargetPerceptionUpdated_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ABTEnemyAIControllerBase::execOnTargetPerceptionUpdated)
{
	P_GET_OBJECT(AActor,Z_Param_Actor);
	P_GET_STRUCT(FAIStimulus,Z_Param_Stimulus);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnTargetPerceptionUpdated(Z_Param_Actor,Z_Param_Stimulus);
	P_NATIVE_END;
}
// End Class ABTEnemyAIControllerBase Function OnTargetPerceptionUpdated

// Begin Class ABTEnemyAIControllerBase
void ABTEnemyAIControllerBase::StaticRegisterNativesABTEnemyAIControllerBase()
{
	UClass* Class = ABTEnemyAIControllerBase::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnTargetPerceptionUpdated", &ABTEnemyAIControllerBase::execOnTargetPerceptionUpdated },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABTEnemyAIControllerBase);
UClass* Z_Construct_UClass_ABTEnemyAIControllerBase_NoRegister()
{
	return ABTEnemyAIControllerBase::StaticClass();
}
struct Z_Construct_UClass_ABTEnemyAIControllerBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "AI/BTAI/BTEnemyAIControllerBase.h" },
		{ "ModuleRelativePath", "AI/BTAI/BTEnemyAIControllerBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ControlledPawn_MetaData[] = {
		{ "ModuleRelativePath", "AI/BTAI/BTEnemyAIControllerBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChildActor_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "AI/BTAI/BTEnemyAIControllerBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SphereStore_MetaData[] = {
		{ "ModuleRelativePath", "AI/BTAI/BTEnemyAIControllerBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Enemy_MetaData[] = {
		{ "ModuleRelativePath", "AI/BTAI/BTEnemyAIControllerBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AIPerception_MetaData[] = {
		{ "Category", "AI Perception" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "AI/BTAI/BTEnemyAIControllerBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SightConfig_MetaData[] = {
		{ "Category", "AI Perception" },
		{ "ModuleRelativePath", "AI/BTAI/BTEnemyAIControllerBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AIBehavior_MetaData[] = {
		{ "Category", "BTEnemyAIControllerBase" },
		{ "ModuleRelativePath", "AI/BTAI/BTEnemyAIControllerBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ControlledPawn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ChildActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SphereStore;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Enemy;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AIPerception;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SightConfig;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AIBehavior;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ABTEnemyAIControllerBase_OnTargetPerceptionUpdated, "OnTargetPerceptionUpdated" }, // 2695662203
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABTEnemyAIControllerBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABTEnemyAIControllerBase_Statics::NewProp_ControlledPawn = { "ControlledPawn", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABTEnemyAIControllerBase, ControlledPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ControlledPawn_MetaData), NewProp_ControlledPawn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABTEnemyAIControllerBase_Statics::NewProp_ChildActor = { "ChildActor", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABTEnemyAIControllerBase, ChildActor), Z_Construct_UClass_UChildActorComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChildActor_MetaData), NewProp_ChildActor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABTEnemyAIControllerBase_Statics::NewProp_SphereStore = { "SphereStore", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABTEnemyAIControllerBase, SphereStore), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SphereStore_MetaData), NewProp_SphereStore_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABTEnemyAIControllerBase_Statics::NewProp_Enemy = { "Enemy", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABTEnemyAIControllerBase, Enemy), Z_Construct_UClass_AEnemyBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Enemy_MetaData), NewProp_Enemy_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABTEnemyAIControllerBase_Statics::NewProp_AIPerception = { "AIPerception", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABTEnemyAIControllerBase, AIPerception), Z_Construct_UClass_UAIPerceptionComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AIPerception_MetaData), NewProp_AIPerception_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABTEnemyAIControllerBase_Statics::NewProp_SightConfig = { "SightConfig", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABTEnemyAIControllerBase, SightConfig), Z_Construct_UClass_UAISenseConfig_Sight_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SightConfig_MetaData), NewProp_SightConfig_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABTEnemyAIControllerBase_Statics::NewProp_AIBehavior = { "AIBehavior", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABTEnemyAIControllerBase, AIBehavior), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AIBehavior_MetaData), NewProp_AIBehavior_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABTEnemyAIControllerBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABTEnemyAIControllerBase_Statics::NewProp_ControlledPawn,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABTEnemyAIControllerBase_Statics::NewProp_ChildActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABTEnemyAIControllerBase_Statics::NewProp_SphereStore,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABTEnemyAIControllerBase_Statics::NewProp_Enemy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABTEnemyAIControllerBase_Statics::NewProp_AIPerception,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABTEnemyAIControllerBase_Statics::NewProp_SightConfig,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABTEnemyAIControllerBase_Statics::NewProp_AIBehavior,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABTEnemyAIControllerBase_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ABTEnemyAIControllerBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AAIController,
	(UObject* (*)())Z_Construct_UPackage__Script_SearchAndRescue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABTEnemyAIControllerBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABTEnemyAIControllerBase_Statics::ClassParams = {
	&ABTEnemyAIControllerBase::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ABTEnemyAIControllerBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ABTEnemyAIControllerBase_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABTEnemyAIControllerBase_Statics::Class_MetaDataParams), Z_Construct_UClass_ABTEnemyAIControllerBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABTEnemyAIControllerBase()
{
	if (!Z_Registration_Info_UClass_ABTEnemyAIControllerBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABTEnemyAIControllerBase.OuterSingleton, Z_Construct_UClass_ABTEnemyAIControllerBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABTEnemyAIControllerBase.OuterSingleton;
}
template<> SEARCHANDRESCUE_API UClass* StaticClass<ABTEnemyAIControllerBase>()
{
	return ABTEnemyAIControllerBase::StaticClass();
}
ABTEnemyAIControllerBase::ABTEnemyAIControllerBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABTEnemyAIControllerBase);
ABTEnemyAIControllerBase::~ABTEnemyAIControllerBase() {}
// End Class ABTEnemyAIControllerBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_BTEnemyAIControllerBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABTEnemyAIControllerBase, ABTEnemyAIControllerBase::StaticClass, TEXT("ABTEnemyAIControllerBase"), &Z_Registration_Info_UClass_ABTEnemyAIControllerBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABTEnemyAIControllerBase), 4004820345U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_BTEnemyAIControllerBase_h_4155859834(TEXT("/Script/SearchAndRescue"),
	Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_BTEnemyAIControllerBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_BTEnemyAIControllerBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
