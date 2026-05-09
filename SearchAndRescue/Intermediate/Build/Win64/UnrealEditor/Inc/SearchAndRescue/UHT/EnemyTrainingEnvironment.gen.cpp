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
SEARCHANDRESCUE_API UEnum* Z_Construct_UEnum_SearchAndRescue_EAgentState();
UPackage* Z_Construct_UPackage__Script_SearchAndRescue();
// End Cross Module References

// Begin Enum EAgentState
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EAgentState;
static UEnum* EAgentState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EAgentState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EAgentState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SearchAndRescue_EAgentState, (UObject*)Z_Construct_UPackage__Script_SearchAndRescue(), TEXT("EAgentState"));
	}
	return Z_Registration_Info_UEnum_EAgentState.OuterSingleton;
}
template<> SEARCHANDRESCUE_API UEnum* StaticEnum<EAgentState>()
{
	return EAgentState_StaticEnum();
}
struct Z_Construct_UEnum_SearchAndRescue_EAgentState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "AI/MLAI/EnemyTrainingEnvironment.h" },
		{ "Patrolling.DisplayName", "Patrolling" },
		{ "Patrolling.Name", "EAgentState::Patrolling" },
		{ "SeeingPlayer.DisplayName", "SeePlayer" },
		{ "SeeingPlayer.Name", "EAgentState::SeeingPlayer" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EAgentState::Patrolling", (int64)EAgentState::Patrolling },
		{ "EAgentState::SeeingPlayer", (int64)EAgentState::SeeingPlayer },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SearchAndRescue_EAgentState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_SearchAndRescue,
	nullptr,
	"EAgentState",
	"EAgentState",
	Z_Construct_UEnum_SearchAndRescue_EAgentState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_SearchAndRescue_EAgentState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_SearchAndRescue_EAgentState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_SearchAndRescue_EAgentState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_SearchAndRescue_EAgentState()
{
	if (!Z_Registration_Info_UEnum_EAgentState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EAgentState.InnerSingleton, Z_Construct_UEnum_SearchAndRescue_EAgentState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EAgentState.InnerSingleton;
}
// End Enum EAgentState

// Begin Class UEnemyTrainingEnvironment Function setTrainingEnvSplineComponent
struct Z_Construct_UFunction_UEnemyTrainingEnvironment_setTrainingEnvSplineComponent_Statics
{
	struct EnemyTrainingEnvironment_eventsetTrainingEnvSplineComponent_Parms
	{
		USplineComponent* tempSpline;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Spline" },
		{ "ModuleRelativePath", "AI/MLAI/EnemyTrainingEnvironment.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_tempSpline_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_tempSpline;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEnemyTrainingEnvironment_setTrainingEnvSplineComponent_Statics::NewProp_tempSpline = { "tempSpline", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EnemyTrainingEnvironment_eventsetTrainingEnvSplineComponent_Parms, tempSpline), Z_Construct_UClass_USplineComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_tempSpline_MetaData), NewProp_tempSpline_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEnemyTrainingEnvironment_setTrainingEnvSplineComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEnemyTrainingEnvironment_setTrainingEnvSplineComponent_Statics::NewProp_tempSpline,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEnemyTrainingEnvironment_setTrainingEnvSplineComponent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEnemyTrainingEnvironment_setTrainingEnvSplineComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEnemyTrainingEnvironment, nullptr, "setTrainingEnvSplineComponent", nullptr, nullptr, Z_Construct_UFunction_UEnemyTrainingEnvironment_setTrainingEnvSplineComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEnemyTrainingEnvironment_setTrainingEnvSplineComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEnemyTrainingEnvironment_setTrainingEnvSplineComponent_Statics::EnemyTrainingEnvironment_eventsetTrainingEnvSplineComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEnemyTrainingEnvironment_setTrainingEnvSplineComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEnemyTrainingEnvironment_setTrainingEnvSplineComponent_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UEnemyTrainingEnvironment_setTrainingEnvSplineComponent_Statics::EnemyTrainingEnvironment_eventsetTrainingEnvSplineComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEnemyTrainingEnvironment_setTrainingEnvSplineComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEnemyTrainingEnvironment_setTrainingEnvSplineComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEnemyTrainingEnvironment::execsetTrainingEnvSplineComponent)
{
	P_GET_OBJECT(USplineComponent,Z_Param_tempSpline);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->setTrainingEnvSplineComponent(Z_Param_tempSpline);
	P_NATIVE_END;
}
// End Class UEnemyTrainingEnvironment Function setTrainingEnvSplineComponent

// Begin Class UEnemyTrainingEnvironment
void UEnemyTrainingEnvironment::StaticRegisterNativesUEnemyTrainingEnvironment()
{
	UClass* Class = UEnemyTrainingEnvironment::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "setTrainingEnvSplineComponent", &UEnemyTrainingEnvironment::execsetTrainingEnvSplineComponent },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentState_MetaData[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "AI/MLAI/EnemyTrainingEnvironment.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TrainingEnvSplineComponent;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEnemyTrainingEnvironment_setTrainingEnvSplineComponent, "setTrainingEnvSplineComponent" }, // 2230199519
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEnemyTrainingEnvironment>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEnemyTrainingEnvironment_Statics::NewProp_TrainingEnvSplineComponent = { "TrainingEnvSplineComponent", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEnemyTrainingEnvironment, TrainingEnvSplineComponent), Z_Construct_UClass_USplineComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TrainingEnvSplineComponent_MetaData), NewProp_TrainingEnvSplineComponent_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UEnemyTrainingEnvironment_Statics::NewProp_CurrentState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UEnemyTrainingEnvironment_Statics::NewProp_CurrentState = { "CurrentState", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEnemyTrainingEnvironment, CurrentState), Z_Construct_UEnum_SearchAndRescue_EAgentState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentState_MetaData), NewProp_CurrentState_MetaData) }; // 2315418911
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEnemyTrainingEnvironment_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyTrainingEnvironment_Statics::NewProp_TrainingEnvSplineComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyTrainingEnvironment_Statics::NewProp_CurrentState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyTrainingEnvironment_Statics::NewProp_CurrentState,
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
	FuncInfo,
	Z_Construct_UClass_UEnemyTrainingEnvironment_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
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
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EAgentState_StaticEnum, TEXT("EAgentState"), &Z_Registration_Info_UEnum_EAgentState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2315418911U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEnemyTrainingEnvironment, UEnemyTrainingEnvironment::StaticClass, TEXT("UEnemyTrainingEnvironment"), &Z_Registration_Info_UClass_UEnemyTrainingEnvironment, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEnemyTrainingEnvironment), 3771860860U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyTrainingEnvironment_h_3071842348(TEXT("/Script/SearchAndRescue"),
	Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyTrainingEnvironment_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyTrainingEnvironment_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyTrainingEnvironment_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyTrainingEnvironment_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
