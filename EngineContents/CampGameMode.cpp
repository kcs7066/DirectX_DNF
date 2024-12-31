#include "PreCompile.h"
#include "CampGameMode.h"
#include "TestImage.h"

#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineGUIWindow.h>
#include <EngineCore/EngineGUI.h>
#include <EngineCore/imgui.h>
#include <EngineCore/DefaultSceneComponent.h>


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
	BackGroundRenderer7 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer7->SetSprite("Camp", 0);
	BackGroundRenderer7->SetScale3D({ 560, 187 , 1.0f });
	BackGroundRenderer7->SetWorldLocation({ -520,263,1 });
	BackGroundRenderer7->SetOrder(-100);

	BackGroundRenderer13 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer13->SetSprite("Camp", 0);
	BackGroundRenderer13->SetScale3D({ 560, 187 , 1.0f });
	BackGroundRenderer13->SetWorldLocation({ 40,263,1 });
	BackGroundRenderer13->SetOrder(-100);

	BackGroundRenderer5 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer5->SetSprite("Camp", 1);
	BackGroundRenderer5->SetScale3D({ 1120, 161 , 1.0f });
	BackGroundRenderer5->SetWorldLocation({ -240,289,1 });
	BackGroundRenderer5->SetOrder(-100);

	//BackGroundRenderer6 = CreateDefaultSubObject<USpriteRenderer>();
	//BackGroundRenderer6->SetSprite("Camp", 2);
	//BackGroundRenderer6->SetScale3D({ 918, 205 , 1.0f });
	//BackGroundRenderer6->SetWorldLocation({ -300,245,1 });

	BackGroundRenderer0 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer0->SetSprite("Camp", 3);
	BackGroundRenderer0->SetScale3D({224, 600, 1.0f });
	BackGroundRenderer0->SetWorldLocation({-688,-117,1});
	BackGroundRenderer0->SetOrder(-100);

	BackGroundRenderer1 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer1->SetSprite("Camp", 4);
	BackGroundRenderer1->SetScale3D({ 224, 600, 1.0f });
	BackGroundRenderer1->SetWorldLocation({ -464,-117,1 });
	BackGroundRenderer1->SetOrder(-100);

	BackGroundRenderer2 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer2->SetSprite("Camp", 5);
	BackGroundRenderer2->SetScale3D({ 224, 600, 1.0f });
	BackGroundRenderer2->SetWorldLocation({ -240,-117,1 });
	BackGroundRenderer2->SetOrder(-100);

	BackGroundRenderer3 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer3->SetSprite("Camp", 6);
	BackGroundRenderer3->SetScale3D({ 224, 600, 1.0f });
	BackGroundRenderer3->SetWorldLocation({ -16,-117,1 });
	BackGroundRenderer3->SetOrder(-100);

	BackGroundRenderer4 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer4->SetSprite("Camp", 7);
	BackGroundRenderer4->SetScale3D({ 224, 541, 1.0f });
	BackGroundRenderer4->SetWorldLocation({ 208,-117,1 });
	BackGroundRenderer4->SetOrder(-100);

	BackGroundRenderer8 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer8->SetSprite("Camp", 8);
	BackGroundRenderer8->SetScale3D({ 224, 120, 1.0f });
	BackGroundRenderer8->SetWorldLocation({ -688,-237,1 });
	BackGroundRenderer8->SetOrder(-100);

	BackGroundRenderer9 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer9->SetSprite("Camp", 9);
	BackGroundRenderer9->SetScale3D({ 224, 120, 1.0f });
	BackGroundRenderer9->SetWorldLocation({ -464,-237,1 });
	BackGroundRenderer9->SetOrder(-100);

	BackGroundRenderer10 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer10->SetSprite("Camp", 10);
	BackGroundRenderer10->SetScale3D({ 224, 120, 1.0f });
	BackGroundRenderer10->SetWorldLocation({ -240,-237,1 });
	BackGroundRenderer10->SetOrder(-100);

	BackGroundRenderer11 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer11->SetSprite("Camp", 11);
	BackGroundRenderer11->SetScale3D({ 224, 120, 1.0f });
	BackGroundRenderer11->SetWorldLocation({ -16,-237,1 });
	BackGroundRenderer11->SetOrder(-100);

	BackGroundRenderer12 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer12->SetSprite("Camp", 12);
	BackGroundRenderer12->SetScale3D({ 224, 120, 1.0f });
	BackGroundRenderer12->SetWorldLocation({ 208,-237,1 });
	BackGroundRenderer12->SetOrder(-100);

	BackGroundRenderer14 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer14->SetSprite("Camp", 13);
	BackGroundRenderer14->SetScale3D({ 132, 178, 1.0f });
	BackGroundRenderer14->SetWorldLocation({ -196,58,1 });
	BackGroundRenderer14->SetOrder(-100);
	{
		TestImage = GetWorld()->SpawnActor<ATestImage>();
	}

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