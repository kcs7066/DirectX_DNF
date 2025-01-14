#include "PreCompile.h"
#include "EllerinonGameMode.h"
#include "Infighter.h"
#include "Grandis.h"
#include "Astaroth.h"

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

AEllerinonGameMode::AEllerinonGameMode()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	BackGroundRenderer0 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer0->SetupAttachment(RootComponent);
	BackGroundRenderer0->SetSprite("Ellerinon", 0);
	BackGroundRenderer0->SetAutoScaleRatio(1.5f);
	BackGroundRenderer0->SetRelativeLocation({ -568,342,0 });
	BackGroundRenderer0->SetOrder(-100);

	BackGroundRenderer6 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer6->SetupAttachment(RootComponent);
	BackGroundRenderer6->SetSprite("Ellerinon", 2);
	BackGroundRenderer6->SetAutoScaleRatio(1.5f);
	BackGroundRenderer6->SetRelativeLocation({ 199,320,0 });
	BackGroundRenderer6->SetOrder(-100);

	BackGroundRenderer5 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer5->SetupAttachment(RootComponent);
	BackGroundRenderer5->SetSprite("Ellerinon", 0);
	BackGroundRenderer5->SetAutoScaleRatio(1.5f);
	BackGroundRenderer5->SetRelativeLocation({ 966,342,0 });
	BackGroundRenderer5->SetOrder(-100);


	BackGroundRenderer1 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer1->SetupAttachment(RootComponent);
	BackGroundRenderer1->SetSprite("Ellerinon", 16);
	BackGroundRenderer1->SetAutoScaleRatio(1.5f);
	BackGroundRenderer1->SetRelativeLocation({ -632,-61,1 });
	BackGroundRenderer1->SetOrder(-100);

	BackGroundRenderer2 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer2->SetupAttachment(RootComponent);
	BackGroundRenderer2->SetSprite("Ellerinon", 17);
	BackGroundRenderer2->SetAutoScaleRatio(1.5f);
	BackGroundRenderer2->SetRelativeLocation({ -296,-61,1 });
	BackGroundRenderer2->SetOrder(-100);

	BackGroundRenderer3 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer3->SetupAttachment(RootComponent);
	BackGroundRenderer3->SetSprite("Ellerinon", 16);
	BackGroundRenderer3->SetAutoScaleRatio(1.5f);
	BackGroundRenderer3->SetRelativeLocation({ 40,-61,1 });
	BackGroundRenderer3->SetOrder(-100);

	BackGroundRenderer4 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer4->SetupAttachment(RootComponent);
	BackGroundRenderer4->SetSprite("Ellerinon", 17);
	BackGroundRenderer4->SetAutoScaleRatio(1.5f);
	BackGroundRenderer4->SetRelativeLocation({ 376,-61,1 });
	BackGroundRenderer4->SetOrder(-100);

	BackGroundRenderer5 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer5->SetupAttachment(RootComponent);
	BackGroundRenderer5->SetSprite("Ellerinon", 16);
	BackGroundRenderer5->SetAutoScaleRatio(1.5f);
	BackGroundRenderer5->SetRelativeLocation({ 712,-61,1 });
	BackGroundRenderer5->SetOrder(-100);

	BackGroundRenderer6 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer6->SetupAttachment(RootComponent);
	BackGroundRenderer6->SetSprite("Ellerinon", 17);
	BackGroundRenderer6->SetAutoScaleRatio(1.5f);
	BackGroundRenderer6->SetRelativeLocation({ 1048,-61,1 });
	BackGroundRenderer6->SetOrder(-100);


	BackGroundRenderer8 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer8->SetupAttachment(RootComponent);
	BackGroundRenderer8->SetSprite("Ellerinon", 18);
	BackGroundRenderer8->SetAutoScaleRatio(1.5f);
	BackGroundRenderer8->SetRelativeLocation({ -632,-360,1 });
	BackGroundRenderer8->SetOrder(-100);

	BackGroundRenderer9 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer9->SetupAttachment(RootComponent);
	BackGroundRenderer9->SetSprite("Ellerinon", 19);
	BackGroundRenderer9->SetAutoScaleRatio(1.5f);
	BackGroundRenderer9->SetRelativeLocation({ -296,-360,1 });
	BackGroundRenderer9->SetOrder(-100);

	BackGroundRenderer10 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer10->SetupAttachment(RootComponent);
	BackGroundRenderer10->SetSprite("Ellerinon", 18);
	BackGroundRenderer10->SetAutoScaleRatio(1.5f);
	BackGroundRenderer10->SetRelativeLocation({ 40,-360,1 });
	BackGroundRenderer10->SetOrder(-100);

	BackGroundRenderer11 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer11->SetupAttachment(RootComponent);
	BackGroundRenderer11->SetSprite("Ellerinon", 19);
	BackGroundRenderer11->SetAutoScaleRatio(1.5f);
	BackGroundRenderer11->SetRelativeLocation({ 376,-360,1 });
	BackGroundRenderer11->SetOrder(-100);

	BackGroundRenderer12 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer12->SetupAttachment(RootComponent);
	BackGroundRenderer12->SetSprite("Ellerinon", 18);
	BackGroundRenderer12->SetAutoScaleRatio(1.5f);
	BackGroundRenderer12->SetRelativeLocation({ 712,-360,1 });
	BackGroundRenderer12->SetOrder(-100);

	BackGroundRenderer13 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer13->SetupAttachment(RootComponent);
	BackGroundRenderer13->SetSprite("Ellerinon", 19);
	BackGroundRenderer13->SetAutoScaleRatio(1.5f);
	BackGroundRenderer13->SetRelativeLocation({ 1048,-360,1 });
	BackGroundRenderer13->SetOrder(-100);

	NewInfighter = GetWorld()->SpawnActor<AInfighter>();

	NewGrandis = GetWorld()->SpawnActor<AGrandis>();
	NewGrandis->GetRenderer()->SetWorldLocation({ 100, 270,-10 });

	NewAstaroth = GetWorld()->SpawnActor<AAstaroth>();
	NewAstaroth->GetRenderer()->SetWorldLocation({ 500, -200,-10 });

	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });


	
}

AEllerinonGameMode::~AEllerinonGameMode()
{
}

void AEllerinonGameMode::BeginPlay()
{

}

void AEllerinonGameMode::Tick(float _DeltaTime)
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
	if (CameraPos.X >416)
	{
		CameraPos.X = 416;
	}
	if (CameraPos.Y < 0)
	{
		CameraPos.Y = 0;
	}
	Camera->SetActorLocation(CameraPos);

}