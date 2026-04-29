// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AI/MLAI/EnemyInteractor.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class USplineComponent;
#ifdef SEARCHANDRESCUE_EnemyInteractor_generated_h
#error "EnemyInteractor.generated.h already included, missing '#pragma once' in EnemyInteractor.h"
#endif
#define SEARCHANDRESCUE_EnemyInteractor_generated_h

#define FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyInteractor_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execsetInteractorSplineComponent);


#define FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyInteractor_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEnemyInteractor(); \
	friend struct Z_Construct_UClass_UEnemyInteractor_Statics; \
public: \
	DECLARE_CLASS(UEnemyInteractor, ULearningAgentsInteractor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SearchAndRescue"), NO_API) \
	DECLARE_SERIALIZER(UEnemyInteractor)


#define FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyInteractor_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEnemyInteractor(); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UEnemyInteractor(UEnemyInteractor&&); \
	UEnemyInteractor(const UEnemyInteractor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEnemyInteractor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEnemyInteractor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UEnemyInteractor) \
	NO_API virtual ~UEnemyInteractor();


#define FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyInteractor_h_13_PROLOG
#define FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyInteractor_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyInteractor_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyInteractor_h_16_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyInteractor_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SEARCHANDRESCUE_API UClass* StaticClass<class UEnemyInteractor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_EnemyInteractor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
