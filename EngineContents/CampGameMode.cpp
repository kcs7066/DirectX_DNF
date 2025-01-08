#include "PreCompile.h"
#include "CampGameMode.h"
#include "Infighter.h"
#include "Lucille.h"

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
	BackGroundRenderer7->SetupAttachment(RootComponent);
	BackGroundRenderer7->SetSprite("Camp", 0);
	BackGroundRenderer7->SetAutoScaleRatio(1.5f);
	BackGroundRenderer7->SetRelativeLocation({ -380,290,3 });
	BackGroundRenderer7->SetOrder(-100);

	BackGroundRenderer13 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer13->SetupAttachment(RootComponent);
	BackGroundRenderer13->SetSprite("Camp", 0);
	BackGroundRenderer13->SetAutoScaleRatio(1.5f);
	BackGroundRenderer13->SetRelativeLocation({ 460,290,3 });
	BackGroundRenderer13->SetOrder(-100);

	BackGroundRenderer5 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer5->SetupAttachment(RootComponent);
	BackGroundRenderer5->SetSprite("Camp", 1);
	BackGroundRenderer5->SetAutoScaleRatio(1.5f);
	BackGroundRenderer5->SetRelativeLocation({ 40,330,2 });
	BackGroundRenderer5->SetOrder(-100);

	BackGroundRenderer6 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer6->SetupAttachment(RootComponent);
	BackGroundRenderer6->SetSprite("Camp", 2);
	BackGroundRenderer6->SetAutoScaleRatio(1.5f);
	BackGroundRenderer6->SetRelativeLocation({ -112,250,4 });
	BackGroundRenderer6->SetOrder(-100);

	BackGroundRenderer0 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer0->SetupAttachment(RootComponent);
	BackGroundRenderer0->SetSprite("Camp", 3);
	BackGroundRenderer0->SetAutoScaleRatio(1.5f);
	BackGroundRenderer0->SetRelativeLocation({ -632,-270,1 });
	BackGroundRenderer0->SetOrder(-100);

	BackGroundRenderer1 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer1->SetupAttachment(RootComponent);
	BackGroundRenderer1->SetSprite("Camp", 4);
	BackGroundRenderer1->SetAutoScaleRatio(1.5f);
	BackGroundRenderer1->SetRelativeLocation({ -296,-270,1 });
	BackGroundRenderer1->SetOrder(-100);

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
	BackGroundRenderer3->SetOrder(-100);

	BackGroundRenderer4 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer4->SetupAttachment(RootComponent);
	BackGroundRenderer4->SetSprite("Camp", 7);
	BackGroundRenderer4->SetAutoScaleRatio(1.5f);
	BackGroundRenderer4->SetRelativeLocation({ 712,-270,1 });
	BackGroundRenderer4->SetOrder(-100);


	BackGroundRenderer8 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer8->SetupAttachment(RootComponent);
	BackGroundRenderer8->SetSprite("Camp", 8);
	BackGroundRenderer8->SetAutoScaleRatio(1.5f);
	BackGroundRenderer8->SetRelativeLocation({ -632,-450,1 });
	BackGroundRenderer8->SetOrder(-100);

	BackGroundRenderer9 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer9->SetupAttachment(RootComponent);
	BackGroundRenderer9->SetSprite("Camp", 9);
	BackGroundRenderer9->SetAutoScaleRatio(1.5f);
	BackGroundRenderer9->SetRelativeLocation({ -296,-450,1 });
	BackGroundRenderer9->SetOrder(-100);

	BackGroundRenderer10 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer10->SetupAttachment(RootComponent);
	BackGroundRenderer10->SetSprite("Camp", 10);
	BackGroundRenderer10->SetAutoScaleRatio(1.5f);
	BackGroundRenderer10->SetRelativeLocation({ 40,-450,1 });
	BackGroundRenderer10->SetOrder(-100);

	BackGroundRenderer11 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer11->SetupAttachment(RootComponent);
	BackGroundRenderer11->SetSprite("Camp", 11);
	BackGroundRenderer11->SetAutoScaleRatio(1.5f);
	BackGroundRenderer11->SetRelativeLocation({ 376,-450,1 });
	BackGroundRenderer11->SetOrder(-100);

	BackGroundRenderer12 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer12->SetupAttachment(RootComponent);
	BackGroundRenderer12->SetSprite("Camp", 12);
	BackGroundRenderer12->SetAutoScaleRatio(1.5f);
	BackGroundRenderer12->SetRelativeLocation({ 712,-450,1 });
	BackGroundRenderer12->SetOrder(-100);

	BackGroundRenderer14 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer14->SetSprite("Camp", 13);
	BackGroundRenderer14->SetAutoScaleRatio(1.5f);
	BackGroundRenderer14->SetWorldLocation({ 106,-7.5f,0 });
	BackGroundRenderer14->SetOrder(-100);

	NewInfighter = GetWorld()->SpawnActor<AInfighter>();
	NewLucille = GetWorld()->SpawnActor<ALucille>();
	NewLucille->GetRenderer()->SetWorldLocation({ 400,-140,-10 });



	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });


	UEngineGUI::CreateGUIWindow<TestWindow>("TestWindow");
}

ACampGameMode::~ACampGameMode()
{
}

void ACampGameMode::BeginPlay()
{

}

void ACampGameMode::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	FVector CameraPos = NewInfighter->GetActorLocation();
	FVector Value = { 0, 0, -1000, 0 };
	CameraPos += Value;
	
	if (CameraPos.X < 0)
	{
		CameraPos.X = 0;
	}
	if (CameraPos.X > 80)
	{
		CameraPos.X = 80;
	}
	if (CameraPos.Y < 0)
	{
		CameraPos.Y = 0;
	}
	Camera->SetActorLocation(CameraPos);
	
}