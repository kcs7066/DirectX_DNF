#include "PreCompile.h"
#include "CampGameMode.h"
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

ACampGameMode::ACampGameMode()
{
	BackGroundRenderer0 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer0->SetSprite("Camp", 0);
	BackGroundRenderer0->SetScale3D({100, 100, 1.0f });
	BackGroundRenderer0->SetWorldLocation({0,0,0});

	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });

	UEngineGUI::CreateGUIWindow<TestWindow>("TestWindow");
}

ACampGameMode::~ACampGameMode()
{
}

void ACampGameMode::Tick(float _DeltaTime)
{

	AActor::Tick(_DeltaTime);

}