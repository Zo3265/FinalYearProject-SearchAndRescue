// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SearchAndRescue/AI/BTAI/ShotgunEnemy/ShotgunShootBTTaskNode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeShotgunShootBTTaskNode() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UBTTaskNode();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_UShotgunShootBTTaskNode();
SEARCHANDRESCUE_API UClass* Z_Construct_UClass_UShotgunShootBTTaskNode_NoRegister();
UPackage* Z_Construct_UPackage__Script_SearchAndRescue();
// End Cross Module References

// Begin Class UShotgunShootBTTaskNode
void UShotgunShootBTTaskNode::StaticRegisterNativesUShotgunShootBTTaskNode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UShotgunShootBTTaskNode);
UClass* Z_Construct_UClass_UShotgunShootBTTaskNode_NoRegister()
{
	return UShotgunShootBTTaskNode::StaticClass();
}
struct Z_Construct_UClass_UShotgunShootBTTaskNode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AI/BTAI/ShotgunEnemy/ShotgunShootBTTaskNode.h" },
		{ "ModuleRelativePath", "AI/BTAI/ShotgunEnemy/ShotgunShootBTTaskNode.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UShotgunShootBTTaskNode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UShotgunShootBTTaskNode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBTTaskNode,
	(UObject* (*)())Z_Construct_UPackage__Script_SearchAndRescue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UShotgunShootBTTaskNode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UShotgunShootBTTaskNode_Statics::ClassParams = {
	&UShotgunShootBTTaskNode::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UShotgunShootBTTaskNode_Statics::Class_MetaDataParams), Z_Construct_UClass_UShotgunShootBTTaskNode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UShotgunShootBTTaskNode()
{
	if (!Z_Registration_Info_UClass_UShotgunShootBTTaskNode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UShotgunShootBTTaskNode.OuterSingleton, Z_Construct_UClass_UShotgunShootBTTaskNode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UShotgunShootBTTaskNode.OuterSingleton;
}
template<> SEARCHANDRESCUE_API UClass* StaticClass<UShotgunShootBTTaskNode>()
{
	return UShotgunShootBTTaskNode::StaticClass();
}
UShotgunShootBTTaskNode::UShotgunShootBTTaskNode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UShotgunShootBTTaskNode);
UShotgunShootBTTaskNode::~UShotgunShootBTTaskNode() {}
// End Class UShotgunShootBTTaskNode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_ShotgunEnemy_ShotgunShootBTTaskNode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UShotgunShootBTTaskNode, UShotgunShootBTTaskNode::StaticClass, TEXT("UShotgunShootBTTaskNode"), &Z_Registration_Info_UClass_UShotgunShootBTTaskNode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UShotgunShootBTTaskNode), 3753731128U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_ShotgunEnemy_ShotgunShootBTTaskNode_h_3115966576(TEXT("/Script/SearchAndRescue"),
	Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_ShotgunEnemy_ShotgunShootBTTaskNode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_FinalYearProject_SearchAndRescue_SearchAndRescue_Source_SearchAndRescue_AI_BTAI_ShotgunEnemy_ShotgunShootBTTaskNode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
