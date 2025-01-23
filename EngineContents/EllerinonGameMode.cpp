#include "PreCompile.h"
#include "EllerinonGameMode.h"
#include "ContentsEditorGUI.h"
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
		
		if (true == ImGui::Button("FreeCameraOn"))
		{
			GetWorld()->GetMainCamera()->FreeCameraSwitch();
		}

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
	BackGroundRenderer0->SetWorldLocation({ -568,342,50 });

	BackGroundRenderer6 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer6->SetupAttachment(RootComponent);
	BackGroundRenderer6->SetSprite("Ellerinon", 2);
	BackGroundRenderer6->SetAutoScaleRatio(1.5f);
	BackGroundRenderer6->SetWorldLocation({ 199,320,50 });

	BackGroundRenderer5 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer5->SetupAttachment(RootComponent);
	BackGroundRenderer5->SetSprite("Ellerinon", 0);
	BackGroundRenderer5->SetAutoScaleRatio(1.5f);
	BackGroundRenderer5->SetWorldLocation({ 966,342,50 });


	BackGroundRenderer1 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer1->SetupAttachment(RootComponent);
	BackGroundRenderer1->SetSprite("Ellerinon", 16);
	BackGroundRenderer1->SetAutoScaleRatio(1.5f);
	BackGroundRenderer1->SetWorldLocation({ -632,-61,100 });

	BackGroundRenderer2 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer2->SetupAttachment(RootComponent);
	BackGroundRenderer2->SetSprite("Ellerinon", 17);
	BackGroundRenderer2->SetAutoScaleRatio(1.5f);
	BackGroundRenderer2->SetWorldLocation({ -296,-61,100 });

	BackGroundRenderer3 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer3->SetupAttachment(RootComponent);
	BackGroundRenderer3->SetSprite("Ellerinon", 16);
	BackGroundRenderer3->SetAutoScaleRatio(1.5f);
	BackGroundRenderer3->SetWorldLocation({ 40,-61,100 });

	BackGroundRenderer4 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer4->SetupAttachment(RootComponent);
	BackGroundRenderer4->SetSprite("Ellerinon", 17);
	BackGroundRenderer4->SetAutoScaleRatio(1.5f);
	BackGroundRenderer4->SetWorldLocation({ 376,-61,100 });

	BackGroundRenderer5 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer5->SetupAttachment(RootComponent);
	BackGroundRenderer5->SetSprite("Ellerinon", 16);
	BackGroundRenderer5->SetAutoScaleRatio(1.5f);
	BackGroundRenderer5->SetWorldLocation({ 712,-61,100 });

	BackGroundRenderer6 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer6->SetupAttachment(RootComponent);
	BackGroundRenderer6->SetSprite("Ellerinon", 17);
	BackGroundRenderer6->SetAutoScaleRatio(1.5f);
	BackGroundRenderer6->SetWorldLocation({ 1048,-61,100 });


	BackGroundRenderer8 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer8->SetupAttachment(RootComponent);
	BackGroundRenderer8->SetSprite("Ellerinon", 18);
	BackGroundRenderer8->SetAutoScaleRatio(1.5f);
	BackGroundRenderer8->SetWorldLocation({ -632,-360,100 });

	BackGroundRenderer9 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer9->SetupAttachment(RootComponent);
	BackGroundRenderer9->SetSprite("Ellerinon", 19);
	BackGroundRenderer9->SetAutoScaleRatio(1.5f);
	BackGroundRenderer9->SetWorldLocation({ -296,-360,100 });

	BackGroundRenderer10 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer10->SetupAttachment(RootComponent);
	BackGroundRenderer10->SetSprite("Ellerinon", 18);
	BackGroundRenderer10->SetAutoScaleRatio(1.5f);
	BackGroundRenderer10->SetWorldLocation({ 40,-360,100 });

	BackGroundRenderer11 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer11->SetupAttachment(RootComponent);
	BackGroundRenderer11->SetSprite("Ellerinon", 19);
	BackGroundRenderer11->SetAutoScaleRatio(1.5f);
	BackGroundRenderer11->SetWorldLocation({ 376,-360,100 });

	BackGroundRenderer12 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer12->SetupAttachment(RootComponent);
	BackGroundRenderer12->SetSprite("Ellerinon", 18);
	BackGroundRenderer12->SetAutoScaleRatio(1.5f);
	BackGroundRenderer12->SetWorldLocation({ 712,-360,100 });

	BackGroundRenderer13 = CreateDefaultSubObject<USpriteRenderer>();
	BackGroundRenderer13->SetupAttachment(RootComponent);
	BackGroundRenderer13->SetSprite("Ellerinon", 19);
	BackGroundRenderer13->SetAutoScaleRatio(1.5f);
	BackGroundRenderer13->SetWorldLocation({ 1048,-360,100 });
	

	NewGrandis = GetWorld()->SpawnActor<AGrandis>();

	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });


	
}

AEllerinonGameMode::~AEllerinonGameMode()
{
}

void AEllerinonGameMode::BeginPlay()
{
	AActor::BeginPlay();
}

void AEllerinonGameMode::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	PlayTime += _DeltaTime;
	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	FVector CameraPos = GetWorld()->GetMainPawn<AInfighter>()->GetActorLocation();
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

void AEllerinonGameMode::LevelChangeStart()
{
	UEngineGUI::AllWindowOff();

	{
		std::shared_ptr<UContentsEditorGUI> Window = UEngineGUI::FindGUIWindow<UContentsEditorGUI>("ContentsEditorGUI");

		if (nullptr == Window)
		{
			Window = UEngineGUI::CreateGUIWindow<UContentsEditorGUI>("ContentsEditorGUI");
		}

		Window->SetActive(true);
	}

	{
		std::shared_ptr<TestWindow> Window = UEngineGUI::FindGUIWindow<TestWindow>("TestWindow");

		if (nullptr == Window)
		{
			Window = UEngineGUI::CreateGUIWindow<TestWindow>("TestWindow");
		}

		Window->SetActive(true);
	}

	BGMPlayer = UEngineSound::Play("ozma_ellerinon.ogg");
}