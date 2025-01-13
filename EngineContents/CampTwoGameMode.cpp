#include "PreCompile.h"
#include "CampTwoGameMode.h"
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

ACampTwoGameMode::ACampTwoGameMode()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	BackGroundRenderer7 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer7->SetupAttachment(RootComponent);
	BackGroundRenderer7->SetSprite("CampTwo", 11);
	BackGroundRenderer7->SetAutoScaleRatio(1.7f);
	BackGroundRenderer7->SetRelativeLocation({ 40,300,3 });
	BackGroundRenderer7->SetOrder(-100);

	BackGroundRenderer5 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer5->SetupAttachment(RootComponent);
	BackGroundRenderer5->SetSprite("CampTwo", 12);
	BackGroundRenderer5->SetAutoScaleRatio(1.5f);
	BackGroundRenderer5->SetRelativeLocation({ 4,305,2 });
	BackGroundRenderer5->SetOrder(-100);

	//BackGroundRenderer6 = CreateDefaultSubObject<USpriteRenderer>();
	//BackGroundRenderer6->SetupAttachment(RootComponent);
	//BackGroundRenderer6->SetSprite("CampTwo", 2);
	//BackGroundRenderer6->SetAutoScaleRatio(1.5f);
	//BackGroundRenderer6->SetRelativeLocation({ -112,250,4 });
	//BackGroundRenderer6->SetOrder(-100);

	BackGroundRenderer0 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer0->SetupAttachment(RootComponent);
	BackGroundRenderer0->SetSprite("CampTwo", 0);
	BackGroundRenderer0->SetAutoScaleRatio(1.5f);
	BackGroundRenderer0->SetRelativeLocation({ -632,180,1 });
	BackGroundRenderer0->SetOrder(-100);

	BackGroundRenderer1 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer1->SetupAttachment(RootComponent);
	BackGroundRenderer1->SetSprite("CampTwo", 1);
	BackGroundRenderer1->SetAutoScaleRatio(1.5f);
	BackGroundRenderer1->SetRelativeLocation({ -296,-95,1 });
	BackGroundRenderer1->SetOrder(-100);

	BackGroundRenderer2 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer2->SetupAttachment(RootComponent);
	BackGroundRenderer2->SetSprite("CampTwo", 2);
	BackGroundRenderer2->SetAutoScaleRatio(1.5f);
	BackGroundRenderer2->SetRelativeLocation({ 40,-144,1 });
	BackGroundRenderer2->SetOrder(-100);

	BackGroundRenderer3 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer3->SetupAttachment(RootComponent);
	BackGroundRenderer3->SetSprite("CampTwo", 3);
	BackGroundRenderer3->SetAutoScaleRatio(1.5f);
	BackGroundRenderer3->SetRelativeLocation({ 376,-113,1 });
	BackGroundRenderer3->SetOrder(-100);

	BackGroundRenderer4 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer4->SetupAttachment(RootComponent);
	BackGroundRenderer4->SetSprite("CampTwo", 4);
	BackGroundRenderer4->SetAutoScaleRatio(1.5f);
	BackGroundRenderer4->SetRelativeLocation({ 712,-32,1 });
	BackGroundRenderer4->SetOrder(-100);


	BackGroundRenderer8 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer8->SetupAttachment(RootComponent);
	BackGroundRenderer8->SetSprite("CampTwo", 5);
	BackGroundRenderer8->SetAutoScaleRatio(1.5f);
	BackGroundRenderer8->SetRelativeLocation({ -632,-360,1 });
	BackGroundRenderer8->SetOrder(-100);

	BackGroundRenderer9 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer9->SetupAttachment(RootComponent);
	BackGroundRenderer9->SetSprite("CampTwo", 6);
	BackGroundRenderer9->SetAutoScaleRatio(1.5f);
	BackGroundRenderer9->SetRelativeLocation({ -296,-360,1 });
	BackGroundRenderer9->SetOrder(-100);

	BackGroundRenderer10 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer10->SetupAttachment(RootComponent);
	BackGroundRenderer10->SetSprite("CampTwo", 7);
	BackGroundRenderer10->SetAutoScaleRatio(1.5f);
	BackGroundRenderer10->SetRelativeLocation({ 40,-360,1 });
	BackGroundRenderer10->SetOrder(-100);

	BackGroundRenderer11 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer11->SetupAttachment(RootComponent);
	BackGroundRenderer11->SetSprite("CampTwo", 8);
	BackGroundRenderer11->SetAutoScaleRatio(1.5f);
	BackGroundRenderer11->SetRelativeLocation({ 376,-360,1 });
	BackGroundRenderer11->SetOrder(-100);

	BackGroundRenderer12 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer12->SetupAttachment(RootComponent);
	BackGroundRenderer12->SetSprite("CampTwo", 9);
	BackGroundRenderer12->SetAutoScaleRatio(1.5f);
	BackGroundRenderer12->SetRelativeLocation({ 712,-360,1 });
	BackGroundRenderer12->SetOrder(-100);

	BackGroundRenderer14 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer14->SetupAttachment(RootComponent);
	BackGroundRenderer14->SetSprite("CampTwo", 10);
	BackGroundRenderer14->SetAutoScaleRatio(1.5f);
	BackGroundRenderer14->SetRelativeLocation({ 785,-300,0 });
	BackGroundRenderer14->SetOrder(-100);

	NewInfighter = GetWorld()->SpawnActor<AInfighter>();
	NewLucille = GetWorld()->SpawnActor<ALucille>();
	NewLucille->GetRenderer()->SetWorldLocation({ -350, 20,-10 });


	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });

}

ACampTwoGameMode::~ACampTwoGameMode()
{
}

void ACampTwoGameMode::BeginPlay()
{

}

void ACampTwoGameMode::Tick(float _DeltaTime)
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