// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SearchAndRescue/AI/BTAI/HostageChar.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHostageChar() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UAnimInstance_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AHostageChar();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_AHostageChar_NoRegister();
UPackage* Z_Construct_UPackage__Script_SearchAndRescue();
// End Cross Module References

// Begin Class AHostageChar Function getActivated
struct Z_Construct_UFunction_AHostageChar_getActivated_Statics
{
	struct HostageChar_eventgetActivated_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "AI/BTAI/HostageChar.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AHostageChar_getActivated_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((HostageChar_eventgetActivated_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AHostageChar_getActivated_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(HostageChar_eventgetActivated_Parms), &Z_Construct_UFunction_AHostageChar_getActivated_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AHostageChar_getActivated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHostageChar_getActivated_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AHostageChar_getActivated_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AHostageChar_getActivated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHostageChar, nullptr, "getActivated", nullptr, nullptr, Z_Construct_UFunction_AHostageChar_getActivated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AHostageChar_getActivated_Statics::PropPointers), sizeof(Z_Construct_UFunction_AHostageChar_getActivated_Statics::HostageChar_eventgetActivated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AHostageChar_getActivated_Statics::Function_MetaDataParams), Z_Construct_UFunction_AHostageChar_getActivated_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AHostageChar_getActivated_Statics::HostageChar_eventgetActivated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AHostageChar_getActivated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AHostageChar_getActivated_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AHostageChar::execgetActivated)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->getActivated();
	P_NATIVE_END;
}
// End Class AHostageChar Function getActivated

// Begin Class AHostageChar Function setActivated
struct Z_Construct_UFunction_AHostageChar_setActivated_Statics
{
	struct HostageChar_eventsetActivated_Parms
	{
		bool bStore;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "AI/BTAI/HostageChar.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bStore_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStore;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AHostageChar_setActivated_Statics::NewProp_bStore_SetBit(void* Obj)
{
	((HostageChar_eventsetActivated_Parms*)Obj)->bStore = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AHostageChar_setActivated_Statics::NewProp_bStore = { "bStore", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(HostageChar_eventsetActivated_Parms), &Z_Construct_UFunction_AHostageChar_setActivated_Statics::NewProp_bStore_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AHostageChar_setActivated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHostageChar_setActivated_Statics::NewProp_bStore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AHostageChar_setActivated_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AHostageChar_setActivated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHostageChar, nullptr, "setActivated", nullptr, nullptr, Z_Construct_UFunction_AHostageChar_setActivated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AHostageChar_setActivated_Statics::PropPointers), sizeof(Z_Construct_UFunction_AHostageChar_setActivated_Statics::HostageChar_eventsetActivated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AHostageChar_setActivated_Statics::Function_MetaDataParams), Z_Construct_UFunction_AHostageChar_setActivated_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AHostageChar_setActivated_Statics::HostageChar_eventsetActivated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AHostageChar_setActivated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AHostageChar_setActivated_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AHostageChar::execsetActivated)
{
	P_GET_UBOOL(Z_Param_bStore);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->setActivated(Z_Param_bStore);
	P_NATIVE_END;
}
// End Class AHostageChar Function setActivated

// Begin Class AHostageChar
void AHostageChar::StaticRegisterNativesAHostageChar()
{
	UClass* Class = AHostageChar::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "getActivated", &AHostageChar::execgetActivated },
		{ "setActivated", &AHostageChar::execsetActivated },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AHostageChar);
UClass* Z_Construct_UClass_AHostageChar_NoRegister()
{
	return AHostageChar::StaticClass();
}
struct Z_Construct_UClass_AHostageChar_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "AI/BTAI/HostageChar.h" },
		{ "ModuleRelativePath", "AI/BTAI/HostageChar.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_fHealth_MetaData[] = {
		{ "Category", "Base Variables" },
		{ "ModuleRelativePath", "AI/BTAI/HostageChar.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_fDefaultSpeed_MetaData[] = {
		{ "Category", "Base Variables" },
		{ "ModuleRelativePath", "AI/BTAI/HostageChar.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActivationMontage_MetaData[] = {
		{ "Category", "Animation Montages" },
		{ "ModuleRelativePath", "AI/BTAI/HostageChar.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnimInstance_MetaData[] = {
		{ "ModuleRelativePath", "AI/BTAI/HostageChar.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_fHealth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_fDefaultSpeed;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActivationMontage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AnimInstance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AHostageChar_getActivated, "getActivated" }, // 3724341890
		{ &Z_Construct_UFunction_AHostageChar_setActivated, "setActivated" }, // 1002976601
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHostageChar>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AHostageChar_Statics::NewProp_fHealth = { "fHealth", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHostageChar, fHealth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_fHealth_MetaData), NewProp_fHealth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AHostageChar_Statics::NewProp_fDefaultSpeed = { "fDefaultSpeed", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHostageChar, fDefaultSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_fDefaultSpeed_MetaData), NewProp_fDefaultSpeed_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHostageChar_Statics::NewProp_ActivationMontage = { "ActivationMontage", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHostageChar, ActivationMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActivationMontage_MetaData), NewProp_ActivationMontage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHostageChar_Statics::NewProp_AnimInstance = { "AnimInstance", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHostageChar, AnimInstance), Z_Construct_UClass_UAnimInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnimInstance_MetaData), NewProp_AnimInstance_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AHostageChar_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHostageChar_Statics::NewProp_fHealth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHostageChar_Statics::NewProp_fDefaultSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHostageChar_Statics::NewProp_ActivationMontage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHostageChar_Statics::NewProp_AnimInstance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHostageChar_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AHostageChar_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_SearchAndRescue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHostageChar_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AHostageChar_Statics::ClassParams = {
	&AHostageChar::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AHostageChar_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AHostageChar_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHostageChar_Statics::Class_MetaDataParams), Z_Construct_UClass_AHostageChar_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AHostageChar()
{
	if (!Z_Registration_Info_UClass_AHostageChar.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AHostageChar.OuterSingleton, Z_Construct_UClass_AHostageChar_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AHostageChar.OuterSingleton;
}
template<> SEARCHANDRESCUE_API UClass* StaticClass<AHostageChar>()
{
	return AHostageChar::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AHostageChar);
AHostageChar::~AHostageChar() {}
// End Class AHostageChar

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_HostageChar_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AHostageChar, AHostageChar::StaticClass, TEXT("AHostageChar"), &Z_Registration_Info_UClass_AHostageChar, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AHostageChar), 732742219U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_HostageChar_h_1756008932(TEXT("/Script/SearchAndRescue"),
	Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_HostageChar_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_HostageChar_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
