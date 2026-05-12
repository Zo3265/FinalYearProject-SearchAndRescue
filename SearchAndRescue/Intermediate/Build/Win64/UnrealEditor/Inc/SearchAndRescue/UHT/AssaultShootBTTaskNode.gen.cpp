// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SearchAndRescue/AI/BTAI/AssaultEnemy/AssaultShootBTTaskNode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAssaultShootBTTaskNode() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UBTTaskNode();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_UAssaultShootBTTaskNode();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_UAssaultShootBTTaskNode_NoRegister();
UPackage* Z_Construct_UPackage__Script_SearchAndRescue();
// End Cross Module References

// Begin Class UAssaultShootBTTaskNode
void UAssaultShootBTTaskNode::StaticRegisterNativesUAssaultShootBTTaskNode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAssaultShootBTTaskNode);
UClass* Z_Construct_UClass_UAssaultShootBTTaskNode_NoRegister()
{
	return UAssaultShootBTTaskNode::StaticClass();
}
struct Z_Construct_UClass_UAssaultShootBTTaskNode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AI/BTAI/AssaultEnemy/AssaultShootBTTaskNode.h" },
		{ "ModuleRelativePath", "AI/BTAI/AssaultEnemy/AssaultShootBTTaskNode.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAssaultShootBTTaskNode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UAssaultShootBTTaskNode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBTTaskNode,
	(UObject* (*)())Z_Construct_UPackage__Script_SearchAndRescue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAssaultShootBTTaskNode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAssaultShootBTTaskNode_Statics::ClassParams = {
	&UAssaultShootBTTaskNode::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAssaultShootBTTaskNode_Statics::Class_MetaDataParams), Z_Construct_UClass_UAssaultShootBTTaskNode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAssaultShootBTTaskNode()
{
	if (!Z_Registration_Info_UClass_UAssaultShootBTTaskNode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAssaultShootBTTaskNode.OuterSingleton, Z_Construct_UClass_UAssaultShootBTTaskNode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAssaultShootBTTaskNode.OuterSingleton;
}
template<> SEARCHANDRESCUE_API UClass* StaticClass<UAssaultShootBTTaskNode>()
{
	return UAssaultShootBTTaskNode::StaticClass();
}
UAssaultShootBTTaskNode::UAssaultShootBTTaskNode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAssaultShootBTTaskNode);
UAssaultShootBTTaskNode::~UAssaultShootBTTaskNode() {}
// End Class UAssaultShootBTTaskNode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_AssaultEnemy_AssaultShootBTTaskNode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAssaultShootBTTaskNode, UAssaultShootBTTaskNode::StaticClass, TEXT("UAssaultShootBTTaskNode"), &Z_Registration_Info_UClass_UAssaultShootBTTaskNode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAssaultShootBTTaskNode), 168093859U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_AssaultEnemy_AssaultShootBTTaskNode_h_1179165312(TEXT("/Script/SearchAndRescue"),
	Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_AssaultEnemy_AssaultShootBTTaskNode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_AssaultEnemy_AssaultShootBTTaskNode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
