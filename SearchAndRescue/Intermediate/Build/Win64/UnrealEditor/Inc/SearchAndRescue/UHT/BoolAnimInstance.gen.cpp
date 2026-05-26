// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SearchAndRescue/AI/BoolAnimInstance.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBoolAnimInstance() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_UBoolAnimInstance();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_UBoolAnimInstance_NoRegister();
UPackage* Z_Construct_UPackage__Script_SearchAndRescue();
// End Cross Module References

// Begin Class UBoolAnimInstance Function setIsDeadBool
struct Z_Construct_UFunction_UBoolAnimInstance_setIsDeadBool_Statics
{
	struct BoolAnimInstance_eventsetIsDeadBool_Parms
	{
		bool bStore;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Animation Bools" },
		{ "ModuleRelativePath", "AI/BoolAnimInstance.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bStore_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStore;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UBoolAnimInstance_setIsDeadBool_Statics::NewProp_bStore_SetBit(void* Obj)
{
	((BoolAnimInstance_eventsetIsDeadBool_Parms*)Obj)->bStore = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBoolAnimInstance_setIsDeadBool_Statics::NewProp_bStore = { "bStore", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BoolAnimInstance_eventsetIsDeadBool_Parms), &Z_Construct_UFunction_UBoolAnimInstance_setIsDeadBool_Statics::NewProp_bStore_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBoolAnimInstance_setIsDeadBool_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBoolAnimInstance_setIsDeadBool_Statics::NewProp_bStore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBoolAnimInstance_setIsDeadBool_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBoolAnimInstance_setIsDeadBool_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UBoolAnimInstance, nullptr, "setIsDeadBool", nullptr, nullptr, Z_Construct_UFunction_UBoolAnimInstance_setIsDeadBool_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBoolAnimInstance_setIsDeadBool_Statics::PropPointers), sizeof(Z_Construct_UFunction_UBoolAnimInstance_setIsDeadBool_Statics::BoolAnimInstance_eventsetIsDeadBool_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBoolAnimInstance_setIsDeadBool_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBoolAnimInstance_setIsDeadBool_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UBoolAnimInstance_setIsDeadBool_Statics::BoolAnimInstance_eventsetIsDeadBool_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBoolAnimInstance_setIsDeadBool()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBoolAnimInstance_setIsDeadBool_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBoolAnimInstance::execsetIsDeadBool)
{
	P_GET_UBOOL(Z_Param_bStore);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->setIsDeadBool(Z_Param_bStore);
	P_NATIVE_END;
}
// End Class UBoolAnimInstance Function setIsDeadBool

// Begin Class UBoolAnimInstance
void UBoolAnimInstance::StaticRegisterNativesUBoolAnimInstance()
{
	UClass* Class = UBoolAnimInstance::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "setIsDeadBool", &UBoolAnimInstance::execsetIsDeadBool },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBoolAnimInstance);
UClass* Z_Construct_UClass_UBoolAnimInstance_NoRegister()
{
	return UBoolAnimInstance::StaticClass();
}
struct Z_Construct_UClass_UBoolAnimInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "AI/BoolAnimInstance.h" },
		{ "ModuleRelativePath", "AI/BoolAnimInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAnimIsDead_MetaData[] = {
		{ "Category", "Animation Bools" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Expose this boolean to the Animation Blueprint\n" },
#endif
		{ "ModuleRelativePath", "AI/BoolAnimInstance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Expose this boolean to the Animation Blueprint" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_bAnimIsDead_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAnimIsDead;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UBoolAnimInstance_setIsDeadBool, "setIsDeadBool" }, // 686697674
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBoolAnimInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_UBoolAnimInstance_Statics::NewProp_bAnimIsDead_SetBit(void* Obj)
{
	((UBoolAnimInstance*)Obj)->bAnimIsDead = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UBoolAnimInstance_Statics::NewProp_bAnimIsDead = { "bAnimIsDead", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UBoolAnimInstance), &Z_Construct_UClass_UBoolAnimInstance_Statics::NewProp_bAnimIsDead_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAnimIsDead_MetaData), NewProp_bAnimIsDead_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UBoolAnimInstance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBoolAnimInstance_Statics::NewProp_bAnimIsDead,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBoolAnimInstance_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UBoolAnimInstance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAnimInstance,
	(UObject* (*)())Z_Construct_UPackage__Script_SearchAndRescue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBoolAnimInstance_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBoolAnimInstance_Statics::ClassParams = {
	&UBoolAnimInstance::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UBoolAnimInstance_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UBoolAnimInstance_Statics::PropPointers),
	0,
	0x009000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBoolAnimInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UBoolAnimInstance_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UBoolAnimInstance()
{
	if (!Z_Registration_Info_UClass_UBoolAnimInstance.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBoolAnimInstance.OuterSingleton, Z_Construct_UClass_UBoolAnimInstance_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBoolAnimInstance.OuterSingleton;
}
template<> SEARCHANDRESCUE_API UClass* StaticClass<UBoolAnimInstance>()
{
	return UBoolAnimInstance::StaticClass();
}
UBoolAnimInstance::UBoolAnimInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UBoolAnimInstance);
UBoolAnimInstance::~UBoolAnimInstance() {}
// End Class UBoolAnimInstance

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BoolAnimInstance_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBoolAnimInstance, UBoolAnimInstance::StaticClass, TEXT("UBoolAnimInstance"), &Z_Registration_Info_UClass_UBoolAnimInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBoolAnimInstance), 2114795452U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BoolAnimInstance_h_534672870(TEXT("/Script/SearchAndRescue"),
	Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BoolAnimInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BoolAnimInstance_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
