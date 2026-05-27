// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AI/WinActor.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef SEARCHANDRESCUE_WinActor_generated_h
#error "WinActor.generated.h already included, missing '#pragma once' in WinActor.h"
#endif
#define SEARCHANDRESCUE_WinActor_generated_h

#define FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_WinActor_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnOverLapBegin);


#define FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_WinActor_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAWinActor(); \
	friend struct Z_Construct_UClass_AWinActor_Statics; \
public: \
	DECLARE_CLASS(AWinActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SearchAndRescue"), NO_API) \
	DECLARE_SERIALIZER(AWinActor)


#define FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_WinActor_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AWinActor(AWinActor&&); \
	AWinActor(const AWinActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWinActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWinActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AWinActor) \
	NO_API virtual ~AWinActor();


#define FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_WinActor_h_13_PROLOG
#define FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_WinActor_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_WinActor_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_WinActor_h_16_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_WinActor_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SEARCHANDRESCUE_API UClass* StaticClass<class AWinActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_WinActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
