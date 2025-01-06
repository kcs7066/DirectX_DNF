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
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	BackGroundRenderer7 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer7->SetSprite("Camp", 0);
	BackGroundRenderer7->SetScale3D({ 560, 187 , 1.0f });
	BackGroundRenderer7->SetWorldLocation({ -520,263,3 });
	BackGroundRenderer7->SetOrder(-100);

	//BackGroundRenderer13 = CreateDefaultSubObject<USpriteRenderer>();
	//BackGroundRenderer13->SetSprite("Camp", 0);
	//BackGroundRenderer13->SetScale3D({ 560, 187 , 1.0f });
	//BackGroundRenderer13->SetWorldLocation({ 40,263,3 });
	//BackGroundRenderer13->SetOrder(-100);

	//BackGroundRenderer5 = CreateDefaultSubObject<USpriteRenderer>();
	//BackGroundRenderer5->SetSprite("Camp", 1);
	//BackGroundRenderer5->SetScale3D({ 1120, 161 , 1.0f });
	//BackGroundRenderer5->SetWorldLocation({ -240,289,2 });
	//BackGroundRenderer5->SetOrder(-100);

	//BackGroundRenderer6 = CreateDefaultSubObject<USpriteRenderer>();
	//BackGroundRenderer6->SetSprite("Camp", 2);
	//BackGroundRenderer6->SetScale3D({ 918, 205 , 1.0f });
	//BackGroundRenderer6->SetWorldLocation({ -300,245,1 });

	BackGroundRenderer0 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer0->SetupAttachment(RootComponent);
	BackGroundRenderer0->SetSprite("Camp", 3);
	BackGroundRenderer0->SetAutoScaleRatio(1.5f);
	BackGroundRenderer0->SetRelativeLocation({-632,-270,1});

	BackGroundRenderer1 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer1->SetupAttachment(RootComponent);
	BackGroundRenderer1->SetSprite("Camp", 4);
	BackGroundRenderer1->SetAutoScaleRatio(1.5f);
	BackGroundRenderer1->SetRelativeLocation({ -296,-270,1 });

	BackGroundRenderer2 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer2->SetupAttachment(RootComponent);
	BackGroundRenderer2->SetSprite("Camp", 5);
	BackGroundRenderer2->SetAutoScaleRatio(1.5f);
	BackGroundRenderer2->SetRelativeLocation({ 40,-270,1 });
	BackGroundRenderer2->SetOrder(-100);

	BackGroundRenderer3 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer3->SetupAttachment(RootComponent);
	BackGroundRenderer3->SetSprite("Camp", 6);
	BackGroundRenderer3->SetAutoScaleRatio(1.5f);
	BackGroundRenderer3->SetRelativeLocation({ 376,-270,1 });

	BackGroundRenderer4 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer4->SetupAttachment(RootComponent);
	BackGroundRenderer4->SetSprite("Camp", 7);
	BackGroundRenderer4->SetAutoScaleRatio(1.5f);
	BackGroundRenderer4->SetRelativeLocation({ 712,-270,1 });


	BackGroundRenderer8 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer8->SetupAttachment(RootComponent);
	BackGroundRenderer8->SetSprite("Camp", 8);
	BackGroundRenderer8->SetAutoScaleRatio(1.5f);
	BackGroundRenderer8->SetRelativeLocation({ -632,-450,1 });

	BackGroundRenderer9 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer9->SetupAttachment(RootComponent);
	BackGroundRenderer9->SetSprite("Camp", 9);
	BackGroundRenderer9->SetAutoScaleRatio(1.5f);
	BackGroundRenderer9->SetRelativeLocation({ -296,-450,1 });

	BackGroundRenderer10 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer10->SetupAttachment(RootComponent);
	BackGroundRenderer10->SetSprite("Camp", 10);
	BackGroundRenderer10->SetAutoScaleRatio(1.5f);
	BackGroundRenderer10->SetRelativeLocation({ 40,-450,1 });

	BackGroundRenderer11 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer11->SetupAttachment(RootComponent);
	BackGroundRenderer11->SetSprite("Camp", 11);
	BackGroundRenderer11->SetAutoScaleRatio(1.5f);
	BackGroundRenderer11->SetRelativeLocation({ 376,-450,1 });

	BackGroundRenderer12 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer12->SetupAttachment(RootComponent);
	BackGroundRenderer12->SetSprite("Camp", 12);
	BackGroundRenderer12->SetAutoScaleRatio(1.5f);
	BackGroundRenderer12->SetRelativeLocation({ 712,-450,1 });

	BackGroundRenderer14 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer14->SetSprite("Camp", 13);
	BackGroundRenderer14->SetAutoScaleRatio(1.5f);
	BackGroundRenderer14->SetWorldLocation({ 106,-7.5f,0 });
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