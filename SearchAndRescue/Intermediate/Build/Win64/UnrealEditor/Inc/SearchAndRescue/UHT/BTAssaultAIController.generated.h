// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AI/BTAI/AssaultEnemy/BTAssaultAIController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
struct FAIStimulus;
#ifdef SEARCHANDRESCUE_BTAssaultAIController_generated_h
#error "BTAssaultAIController.generated.h already included, missing '#pragma once' in BTAssaultAIController.h"
#endif
#define SEARCHANDRESCUE_BTAssaultAIController_generated_h

#define FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_AssaultEnemy_BTAssaultAIController_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnTargetPerceptionUpdated);


#define FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_AssaultEnemy_BTAssaultAIController_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABTAssaultAIController(); \
	friend struct Z_Construct_UClass_ABTAssaultAIController_Statics; \
public: \
	DECLARE_CLASS(ABTAssaultAIController, ABTEnemyAIControllerBase, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SearchAndRescue"), NO_API) \
	DECLARE_SERIALIZER(ABTAssaultAIController)


#define FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_AssaultEnemy_BTAssaultAIController_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ABTAssaultAIController(ABTAssaultAIController&&); \
	ABTAssaultAIController(const ABTAssaultAIController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABTAssaultAIController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABTAssaultAIController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABTAssaultAIController) \
	NO_API virtual ~ABTAssaultAIController();


#define FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_AssaultEnemy_BTAssaultAIController_h_13_PROLOG
#define FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_AssaultEnemy_BTAssaultAIController_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_AssaultEnemy_BTAssaultAIController_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_AssaultEnemy_BTAssaultAIController_h_16_INCLASS_NO_PURE_DECLS \
	FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_AssaultEnemy_BTAssaultAIController_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SEARCHANDRESCUE_API UClass* StaticClass<class ABTAssaultAIController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_AssaultEnemy_BTAssaultAIController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
