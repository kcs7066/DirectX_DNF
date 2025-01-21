#include "PreCompile.h"
#include "ContentsCore.h"
#include <EngineCore/Level.h>
#include <EngineCore/EngineTexture.h>
#include <EngineCore/EngineSprite.h>
#include <EngineCore/EngineShader.h>
#include <EngineCore/EngineMaterial.h>
#include "CampGameMode.h"
#include "CampTwoGameMode.h"
#include "EllerinonGameMode.h"
#include <EngineCore/HUD.h>
#include <EngineCore/EngineGUI.h>
#include <EngineCore/EngineGUIWindow.h>
#include "ContentsEditorGUI.h"
#include "Infighter.h"

CreateContentsCoreDefine(UContentsCore);

UContentsCore::UContentsCore()
{
}

UContentsCore::~UContentsCore()
{
}


void UContentsCore::EngineStart(UEngineInitData& _Data)
{

	_Data.WindowPos = { 0, 0 };
	_Data.WindowSize = { 1600, 900 };

	ResSetting();

	//UEngineCore::CreateLevel<ACampGameMode, AInfighter, AHUD>("Camplevel");
	//UEngineCore::CreateLevel<ACampTwoGameMode, AInfighter, AHUD>("CampTwolevel");
	UEngineCore::CreateLevel<AEllerinonGameMode, AInfighter, AHUD>("Ellerinonlevel");
	UEngineCore::OpenLevel("Ellerinonlevel");

	UEngineGUI::AllWindowOff();

	UEngineGUI::CreateGUIWindow<UContentsEditorGUI>("ContentsEditorGUI");
	std::shared_ptr<UContentsEditorGUI> Window = UEngineGUI::FindGUIWindow<UContentsEditorGUI>("ContentsEditorGUI");
	Window->SetActive(true);
}

void UContentsCore::EngineTick(float _DeltaTime)
{

}

void UContentsCore::EngineEnd()
{

}