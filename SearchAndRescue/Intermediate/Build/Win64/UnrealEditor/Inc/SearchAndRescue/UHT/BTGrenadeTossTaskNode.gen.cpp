// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SearchAndRescue/AI/BTAI/BTGrenadeTossTaskNode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTGrenadeTossTaskNode() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UBTTaskNode();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_UBTGrenadeTossTaskNode();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_UBTGrenadeTossTaskNode_NoRegister();
UPackage* Z_Construct_UPackage__Script_SearchAndRescue();
// End Cross Module References

// Begin Class UBTGrenadeTossTaskNode
void UBTGrenadeTossTaskNode::StaticRegisterNativesUBTGrenadeTossTaskNode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBTGrenadeTossTaskNode);
UClass* Z_Construct_UClass_UBTGrenadeTossTaskNode_NoRegister()
{
	return UBTGrenadeTossTaskNode::StaticClass();
}
struct Z_Construct_UClass_UBTGrenadeTossTaskNode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AI/BTAI/BTGrenadeTossTaskNode.h" },
		{ "ModuleRelativePath", "AI/BTAI/BTGrenadeTossTaskNode.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTGrenadeTossTaskNode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UBTGrenadeTossTaskNode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBTTaskNode,
	(UObject* (*)())Z_Construct_UPackage__Script_SearchAndRescue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTGrenadeTossTaskNode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTGrenadeTossTaskNode_Statics::ClassParams = {
	&UBTGrenadeTossTaskNode::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTGrenadeTossTaskNode_Statics::Class_MetaDataParams), Z_Construct_UClass_UBTGrenadeTossTaskNode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UBTGrenadeTossTaskNode()
{
	if (!Z_Registration_Info_UClass_UBTGrenadeTossTaskNode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTGrenadeTossTaskNode.OuterSingleton, Z_Construct_UClass_UBTGrenadeTossTaskNode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBTGrenadeTossTaskNode.OuterSingleton;
}
template<> SEARCHANDRESCUE_API UClass* StaticClass<UBTGrenadeTossTaskNode>()
{
	return UBTGrenadeTossTaskNode::StaticClass();
}
UBTGrenadeTossTaskNode::UBTGrenadeTossTaskNode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UBTGrenadeTossTaskNode);
UBTGrenadeTossTaskNode::~UBTGrenadeTossTaskNode() {}
// End Class UBTGrenadeTossTaskNode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_BTGrenadeTossTaskNode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBTGrenadeTossTaskNode, UBTGrenadeTossTaskNode::StaticClass, TEXT("UBTGrenadeTossTaskNode"), &Z_Registration_Info_UClass_UBTGrenadeTossTaskNode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTGrenadeTossTaskNode), 935665748U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_BTGrenadeTossTaskNode_h_4286171263(TEXT("/Script/SearchAndRescue"),
	Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_BTGrenadeTossTaskNode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_zohai_Documents_GitHub_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_BTGrenadeTossTaskNode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
