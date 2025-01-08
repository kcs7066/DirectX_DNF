#include "PreCompile.h"
#include "Lucille.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/CameraActor.h>
#include <EngineCore/TimeEventComponent.h>
#include "MyRenderer.h"

ALucille::ALucille()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	LucilleRenderer = CreateDefaultSubObject<USpriteRenderer>();

	LucilleRenderer->CreateAnimation("lucille_Idle", "lucille", 0, 20, 0.2f);
	{
		USpriteRenderer::FrameAnimation* Animation = LucilleRenderer->FindAnimation("lucille_Idle");
	}

	LucilleRenderer->ChangeAnimation("lucille_Idle");
	LucilleRenderer->SetAutoScaleRatio(1.5f);
	LucilleRenderer->SetupAttachment(RootComponent);
}

ALucille::~ALucille()
{
}

void ALucille::BeginPlay()
{
	AActor::BeginPlay();
}

void ALucille::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}