// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Weapons/BulletBase.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef SEARCHANDRESCUE_BulletBase_generated_h
#error "BulletBase.generated.h already included, missing '#pragma once' in BulletBase.h"
#endif
#define SEARCHANDRESCUE_BulletBase_generated_h

#define FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_Weapons_BulletBase_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnOverLapBegin);


#define FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_Weapons_BulletBase_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABulletBase(); \
	friend struct Z_Construct_UClass_ABulletBase_Statics; \
public: \
	DECLARE_CLASS(ABulletBase, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SearchAndRescue"), NO_API) \
	DECLARE_SERIALIZER(ABulletBase)


#define FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_Weapons_BulletBase_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ABulletBase(ABulletBase&&); \
	ABulletBase(const ABulletBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABulletBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABulletBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABulletBase) \
	NO_API virtual ~ABulletBase();


#define FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_Weapons_BulletBase_h_10_PROLOG
#define FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_Weapons_BulletBase_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_Weapons_BulletBase_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_Weapons_BulletBase_h_13_INCLASS_NO_PURE_DECLS \
	FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_Weapons_BulletBase_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SEARCHANDRESCUE_API UClass* StaticClass<class ABulletBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_Weapons_BulletBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
