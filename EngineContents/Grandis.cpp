#include "PreCompile.h"
#include "Grandis.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/CameraActor.h>
#include <EngineCore/TimeEventComponent.h>
#include "MyRenderer.h"

AGrandis::AGrandis()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	GrandisRenderer = CreateDefaultSubObject<USpriteRenderer>();

	GrandisRenderer->CreateAnimation("grandis_Idle", "grandis", 5, 8, 0.2f);
	{
		USpriteRenderer::FrameAnimation* Animation = GrandisRenderer->FindAnimation("grandis_Idle");


		GrandisRenderer->ChangeAnimation("grandis_Idle");
		GrandisRenderer->SetAutoScaleRatio(1.5f);
		GrandisRenderer->SetupAttachment(RootComponent);
	}
}
	AGrandis::~AGrandis()
	{
	}

	void AGrandis::BeginPlay()
	{
		AActor::BeginPlay();
	}

	void AGrandis::Tick(float _DeltaTime)
	{
		AActor::Tick(_DeltaTime);
	}