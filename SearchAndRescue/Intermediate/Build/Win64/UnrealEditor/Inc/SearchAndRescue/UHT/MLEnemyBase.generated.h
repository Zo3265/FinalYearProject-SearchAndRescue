// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AI/MLAI/Enemies/MLEnemyBase.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AWeaponBase;
#ifdef SEARCHANDRESCUE_MLEnemyBase_generated_h
#error "MLEnemyBase.generated.h already included, missing '#pragma once' in MLEnemyBase.h"
#endif
#define SEARCHANDRESCUE_MLEnemyBase_generated_h

#define FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_Enemies_MLEnemyBase_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execgetWeapon); \
	DECLARE_FUNCTION(execResetToRandomPointOnSpline);


#define FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_Enemies_MLEnemyBase_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMLEnemyBase(); \
	friend struct Z_Construct_UClass_AMLEnemyBase_Statics; \
public: \
	DECLARE_CLASS(AMLEnemyBase, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SearchAndRescue"), NO_API) \
	DECLARE_SERIALIZER(AMLEnemyBase)


#define FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_Enemies_MLEnemyBase_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AMLEnemyBase(AMLEnemyBase&&); \
	AMLEnemyBase(const AMLEnemyBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMLEnemyBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMLEnemyBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMLEnemyBase) \
	NO_API virtual ~AMLEnemyBase();


#define FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_Enemies_MLEnemyBase_h_16_PROLOG
#define FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_Enemies_MLEnemyBase_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_Enemies_MLEnemyBase_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_Enemies_MLEnemyBase_h_19_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_Enemies_MLEnemyBase_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SEARCHANDRESCUE_API UClass* StaticClass<class AMLEnemyBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_MLAI_Enemies_MLEnemyBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
