// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SearchAndRescue/AI/BTAI/SniperShootBTTaskNode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSniperShootBTTaskNode() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UBTTaskNode();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_USniperShootBTTaskNode();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_USniperShootBTTaskNode_NoRegister();
UPackage* Z_Construct_UPackage__Script_SearchAndRescue();
// End Cross Module References

// Begin Class USniperShootBTTaskNode
void USniperShootBTTaskNode::StaticRegisterNativesUSniperShootBTTaskNode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USniperShootBTTaskNode);
UClass* Z_Construct_UClass_USniperShootBTTaskNode_NoRegister()
{
	return USniperShootBTTaskNode::StaticClass();
}
struct Z_Construct_UClass_USniperShootBTTaskNode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AI/BTAI/SniperShootBTTaskNode.h" },
		{ "ModuleRelativePath", "AI/BTAI/SniperShootBTTaskNode.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USniperShootBTTaskNode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_USniperShootBTTaskNode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBTTaskNode,
	(UObject* (*)())Z_Construct_UPackage__Script_SearchAndRescue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USniperShootBTTaskNode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USniperShootBTTaskNode_Statics::ClassParams = {
	&USniperShootBTTaskNode::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USniperShootBTTaskNode_Statics::Class_MetaDataParams), Z_Construct_UClass_USniperShootBTTaskNode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_USniperShootBTTaskNode()
{
	if (!Z_Registration_Info_UClass_USniperShootBTTaskNode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USniperShootBTTaskNode.OuterSingleton, Z_Construct_UClass_USniperShootBTTaskNode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USniperShootBTTaskNode.OuterSingleton;
}
template<> SEARCHANDRESCUE_API UClass* StaticClass<USniperShootBTTaskNode>()
{
	return USniperShootBTTaskNode::StaticClass();
}
USniperShootBTTaskNode::USniperShootBTTaskNode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(USniperShootBTTaskNode);
USniperShootBTTaskNode::~USniperShootBTTaskNode() {}
// End Class USniperShootBTTaskNode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_SniperShootBTTaskNode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USniperShootBTTaskNode, USniperShootBTTaskNode::StaticClass, TEXT("USniperShootBTTaskNode"), &Z_Registration_Info_UClass_USniperShootBTTaskNode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USniperShootBTTaskNode), 1295189280U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_SniperShootBTTaskNode_h_2849476506(TEXT("/Script/SearchAndRescue"),
	Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_SniperShootBTTaskNode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_SniperShootBTTaskNode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
