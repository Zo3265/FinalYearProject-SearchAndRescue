// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SearchAndRescue/AI/MLAI/EnemyManager.h"
#include "LearningAgents/Public/LearningAgentsCritic.h"
#include "LearningAgents/Public/LearningAgentsPolicy.h"
#include "LearningAgentsTraining/Public/LearningAgentsPPOTrainer.h"
#include "LearningAgentsTraining/Public/LearningAgentsTrainer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemyManager() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_USplineComponent_NoRegister();
LEARNINGAGENTS_API UClass* Z_Construct_UClass_ULearningAgentsCritic_NoRegister();
LEARNINGAGENTS_API UClass* Z_Construct_UClass_ULearningAgentsNeuralNetwork_NoRegister();
LEARNINGAGENTS_API UClass* Z_Construct_UClass_ULearningAgentsPolicy_NoRegister();
LEARNINGAGENTS_API UScriptStruct* Z_Construct_UScriptStruct_FLearningAgentsCriticSettings();
LEARNINGAGENTS_API UScriptStruct* Z_Construct_UScriptStruct_FLearningAgentsPolicySettings();
LEARNINGAGENTSTRAINING_API UClass* Z_Construct_UClass_ULearningAgentsPPOTrainer_NoRegister();
LEARNINGAGENTSTRAINING_API UScriptStruct* Z_Construct_UScriptStruct_FLearningAgentsPPOTrainingSettings();
LEARNINGAGENTSTRAINING_API UScriptStruct* Z_Construct_UScriptStruct_FLearningAgentsTrainingGameSettings();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AEnemyManager();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AEnemyManager_NoRegister();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_UEnemyInteractor_NoRegister();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_UEnemyTrainingEnvironment_NoRegister();
UPackage* Z_Construct_UPackage__Script_SearchAndRescue();
// End Cross Module References

// Begin Class AEnemyManager
void AEnemyManager::StaticRegisterNativesAEnemyManager()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEnemyManager);
UClass* Z_Construct_UClass_AEnemyManager_NoRegister()
{
	return AEnemyManager::StaticClass();
}
struct Z_Construct_UClass_AEnemyManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AI/MLAI/EnemyManager.h" },
		{ "ModuleRelativePath", "AI/MLAI/EnemyManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemyInteractorRef_MetaData[] = {
		{ "ModuleRelativePath", "AI/MLAI/EnemyManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemyPolicy_MetaData[] = {
		{ "ModuleRelativePath", "AI/MLAI/EnemyManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PolicySettings_MetaData[] = {
		{ "ModuleRelativePath", "AI/MLAI/EnemyManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemyCritic_MetaData[] = {
		{ "ModuleRelativePath", "AI/MLAI/EnemyManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CriticSettings_MetaData[] = {
		{ "ModuleRelativePath", "AI/MLAI/EnemyManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemyTrainingEnvRef_MetaData[] = {
		{ "ModuleRelativePath", "AI/MLAI/EnemyManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PPOTrainer_MetaData[] = {
		{ "ModuleRelativePath", "AI/MLAI/EnemyManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PPOTrainerTrainingSettings_MetaData[] = {
		{ "ModuleRelativePath", "AI/MLAI/EnemyManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TrainingGameSettings_MetaData[] = {
		{ "ModuleRelativePath", "AI/MLAI/EnemyManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EncoderNeuralNetworkAsset_MetaData[] = {
		{ "Category", "Neural Network Asset" },
		{ "ModuleRelativePath", "AI/MLAI/EnemyManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PolicyNeuralNetworkAsset_MetaData[] = {
		{ "Category", "Neural Network Asset" },
		{ "ModuleRelativePath", "AI/MLAI/EnemyManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DecoderNeuralNetworkAsset_MetaData[] = {
		{ "Category", "Neural Network Asset" },
		{ "ModuleRelativePath", "AI/MLAI/EnemyManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CriticNetworkAsset_MetaData[] = {
		{ "Category", "Neural Network Asset" },
		{ "ModuleRelativePath", "AI/MLAI/EnemyManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ManagerSpline_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "AI/MLAI/EnemyManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EnemyInteractorRef;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EnemyPolicy;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PolicySettings;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EnemyCritic;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CriticSettings;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EnemyTrainingEnvRef;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PPOTrainer;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PPOTrainerTrainingSettings;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TrainingGameSettings;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EncoderNeuralNetworkAsset;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PolicyNeuralNetworkAsset;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DecoderNeuralNetworkAsset;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CriticNetworkAsset;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ManagerSpline;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemyManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemyManager_Statics::NewProp_EnemyInteractorRef = { "EnemyInteractorRef", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemyManager, EnemyInteractorRef), Z_Construct_UClass_UEnemyInteractor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemyInteractorRef_MetaData), NewProp_EnemyInteractorRef_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemyManager_Statics::NewProp_EnemyPolicy = { "EnemyPolicy", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemyManager, EnemyPolicy), Z_Construct_UClass_ULearningAgentsPolicy_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemyPolicy_MetaData), NewProp_EnemyPolicy_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEnemyManager_Statics::NewProp_PolicySettings = { "PolicySettings", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemyManager, PolicySettings), Z_Construct_UScriptStruct_FLearningAgentsPolicySettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PolicySettings_MetaData), NewProp_PolicySettings_MetaData) }; // 836478240
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemyManager_Statics::NewProp_EnemyCritic = { "EnemyCritic", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemyManager, EnemyCritic), Z_Construct_UClass_ULearningAgentsCritic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemyCritic_MetaData), NewProp_EnemyCritic_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEnemyManager_Statics::NewProp_CriticSettings = { "CriticSettings", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemyManager, CriticSettings), Z_Construct_UScriptStruct_FLearningAgentsCriticSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CriticSettings_MetaData), NewProp_CriticSettings_MetaData) }; // 1735774282
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemyManager_Statics::NewProp_EnemyTrainingEnvRef = { "EnemyTrainingEnvRef", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemyManager, EnemyTrainingEnvRef), Z_Construct_UClass_UEnemyTrainingEnvironment_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemyTrainingEnvRef_MetaData), NewProp_EnemyTrainingEnvRef_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemyManager_Statics::NewProp_PPOTrainer = { "PPOTrainer", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemyManager, PPOTrainer), Z_Construct_UClass_ULearningAgentsPPOTrainer_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PPOTrainer_MetaData), NewProp_PPOTrainer_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEnemyManager_Statics::NewProp_PPOTrainerTrainingSettings = { "PPOTrainerTrainingSettings", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemyManager, PPOTrainerTrainingSettings), Z_Construct_UScriptStruct_FLearningAgentsPPOTrainingSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PPOTrainerTrainingSettings_MetaData), NewProp_PPOTrainerTrainingSettings_MetaData) }; // 2260124407
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEnemyManager_Statics::NewProp_TrainingGameSettings = { "TrainingGameSettings", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemyManager, TrainingGameSettings), Z_Construct_UScriptStruct_FLearningAgentsTrainingGameSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TrainingGameSettings_MetaData), NewProp_TrainingGameSettings_MetaData) }; // 3112686546
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemyManager_Statics::NewProp_EncoderNeuralNetworkAsset = { "EncoderNeuralNetworkAsset", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemyManager, EncoderNeuralNetworkAsset), Z_Construct_UClass_ULearningAgentsNeuralNetwork_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EncoderNeuralNetworkAsset_MetaData), NewProp_EncoderNeuralNetworkAsset_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemyManager_Statics::NewProp_PolicyNeuralNetworkAsset = { "PolicyNeuralNetworkAsset", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemyManager, PolicyNeuralNetworkAsset), Z_Construct_UClass_ULearningAgentsNeuralNetwork_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PolicyNeuralNetworkAsset_MetaData), NewProp_PolicyNeuralNetworkAsset_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemyManager_Statics::NewProp_DecoderNeuralNetworkAsset = { "DecoderNeuralNetworkAsset", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemyManager, DecoderNeuralNetworkAsset), Z_Construct_UClass_ULearningAgentsNeuralNetwork_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DecoderNeuralNetworkAsset_MetaData), NewProp_DecoderNeuralNetworkAsset_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemyManager_Statics::NewProp_CriticNetworkAsset = { "CriticNetworkAsset", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemyManager, CriticNetworkAsset), Z_Construct_UClass_ULearningAgentsNeuralNetwork_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CriticNetworkAsset_MetaData), NewProp_CriticNetworkAsset_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemyManager_Statics::NewProp_ManagerSpline = { "ManagerSpline", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemyManager, ManagerSpline), Z_Construct_UClass_USplineComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ManagerSpline_MetaData), NewProp_ManagerSpline_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEnemyManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyManager_Statics::NewProp_EnemyInteractorRef,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyManager_Statics::NewProp_EnemyPolicy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyManager_Statics::NewProp_PolicySettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyManager_Statics::NewProp_EnemyCritic,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyManager_Statics::NewProp_CriticSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyManager_Statics::NewProp_EnemyTrainingEnvRef,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyManager_Statics::NewProp_PPOTrainer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyManager_Statics::NewProp_PPOTrainerTrainingSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyManager_Statics::NewProp_TrainingGameSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyManager_Statics::NewProp_EncoderNeuralNetworkAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyManager_Statics::NewProp_PolicyNeuralNetworkAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyManager_Statics::NewProp_DecoderNeuralNetworkAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyManager_Statics::NewProp_CriticNetworkAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyManager_Statics::NewProp_ManagerSpline,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyManager_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEnemyManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_SearchAndRescue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEnemyManager_Statics::ClassParams = {
	&AEnemyManager::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AEnemyManager_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyManager_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyManager_Statics::Class_MetaDataParams), Z_Construct_UClass_AEnemyManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEnemyManager()
{
	if (!Z_Registration_Info_UClass_AEnemyManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEnemyManager.OuterSingleton, Z_Construct_UClass_AEnemyManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEnemyManager.OuterSingleton;
}
template<> SEARCHANDRESCUE_API UClass* StaticClass<AEnemyManager>()
{
	return AEnemyManager::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemyManager);
AEnemyManager::~AEnemyManager() {}
// End Class AEnemyManager

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyManager_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEnemyManager, AEnemyManager::StaticClass, TEXT("AEnemyManager"), &Z_Registration_Info_UClass_AEnemyManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEnemyManager), 2557891695U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyManager_h_423857928(TEXT("/Script/SearchAndRescue"),
	Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyManager_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
