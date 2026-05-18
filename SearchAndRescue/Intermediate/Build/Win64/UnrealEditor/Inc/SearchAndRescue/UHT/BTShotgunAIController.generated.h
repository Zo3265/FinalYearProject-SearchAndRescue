// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AI/BTAI/ShotgunEnemy/BTShotgunAIController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
struct FAIStimulus;
#ifdef SEARCHANDRESCUE_BTShotgunAIController_generated_h
#error "BTShotgunAIController.generated.h already included, missing '#pragma once' in BTShotgunAIController.h"
#endif
#define SEARCHANDRESCUE_BTShotgunAIController_generated_h

#define FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_ShotgunEnemy_BTShotgunAIController_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnTargetPerceptionUpdated);


#define FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_ShotgunEnemy_BTShotgunAIController_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABTShotgunAIController(); \
	friend struct Z_Construct_UClass_ABTShotgunAIController_Statics; \
public: \
	DECLARE_CLASS(ABTShotgunAIController, ABTEnemyAIControllerBase, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SearchAndRescue"), NO_API) \
	DECLARE_SERIALIZER(ABTShotgunAIController)


#define FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_ShotgunEnemy_BTShotgunAIController_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ABTShotgunAIController(ABTShotgunAIController&&); \
	ABTShotgunAIController(const ABTShotgunAIController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABTShotgunAIController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABTShotgunAIController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABTShotgunAIController) \
	NO_API virtual ~ABTShotgunAIController();


#define FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_ShotgunEnemy_BTShotgunAIController_h_14_PROLOG
#define FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_ShotgunEnemy_BTShotgunAIController_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_ShotgunEnemy_BTShotgunAIController_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_ShotgunEnemy_BTShotgunAIController_h_17_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_ShotgunEnemy_BTShotgunAIController_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SEARCHANDRESCUE_API UClass* StaticClass<class ABTShotgunAIController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_ShotgunEnemy_BTShotgunAIController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
