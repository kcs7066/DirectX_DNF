#include "PreCompile.h"
#include "PlayGameMode.h"
#include "TestImage.h"
#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineGUIWindow.h>
#include <EngineCore/EngineGUI.h>
#include <EngineCore/imgui.h>

class TestWindow : public UEngineGUIWindow
{
public:
	void OnGUI() override
	{
		ImGui::Button("WindowButton");
		ImGui::SameLine();
		ImGui::Text("test");

	}
};

APlayGameMode::APlayGameMode()
{
	{
		TestImage = GetWorld()->SpawnActor<ATestImage>();
	}

	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });

	UEngineGUI::CreateGUIWindow<TestWindow>("TestWindow");
}

APlayGameMode::~APlayGameMode()
{

}

void APlayGameMode::Tick(float _DeltaTime)
{

	AActor::Tick(_DeltaTime);

}