// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AI/MLAI/EnemyTrainingEnvironment.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class USplineComponent;
#ifdef SEARCHANDRESCUE_EnemyTrainingEnvironment_generated_h
#error "EnemyTrainingEnvironment.generated.h already included, missing '#pragma once' in EnemyTrainingEnvironment.h"
#endif
#define SEARCHANDRESCUE_EnemyTrainingEnvironment_generated_h

#define FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyTrainingEnvironment_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execsetTrainingEnvSplineComponent);


#define FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyTrainingEnvironment_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEnemyTrainingEnvironment(); \
	friend struct Z_Construct_UClass_UEnemyTrainingEnvironment_Statics; \
public: \
	DECLARE_CLASS(UEnemyTrainingEnvironment, ULearningAgentsTrainingEnvironment, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SearchAndRescue"), NO_API) \
	DECLARE_SERIALIZER(UEnemyTrainingEnvironment)


#define FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyTrainingEnvironment_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEnemyTrainingEnvironment(); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UEnemyTrainingEnvironment(UEnemyTrainingEnvironment&&); \
	UEnemyTrainingEnvironment(const UEnemyTrainingEnvironment&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEnemyTrainingEnvironment); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEnemyTrainingEnvironment); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UEnemyTrainingEnvironment) \
	NO_API virtual ~UEnemyTrainingEnvironment();


#define FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyTrainingEnvironment_h_15_PROLOG
#define FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyTrainingEnvironment_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyTrainingEnvironment_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyTrainingEnvironment_h_18_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyTrainingEnvironment_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SEARCHANDRESCUE_API UClass* StaticClass<class UEnemyTrainingEnvironment>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyTrainingEnvironment_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
