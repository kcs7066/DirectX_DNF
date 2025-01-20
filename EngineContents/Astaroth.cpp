#include "PreCompile.h"
#include "Astaroth.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/CameraActor.h>
#include <EngineCore/TimeEventComponent.h>
#include "MyRenderer.h"

AAstaroth::AAstaroth()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	AstarothRenderer = CreateDefaultSubObject<USpriteRenderer>();

	AstarothRenderer->CreateAnimation("astaroth_Idle", "astaroth", 0, 285, 0.1f);
	{
		USpriteRenderer::FrameAnimation* Animation = AstarothRenderer->FindAnimation("astaroth_Idle");


		AstarothRenderer->ChangeAnimation("astaroth_Idle");
		AstarothRenderer->SetAutoScaleRatio(1.5f);
		AstarothRenderer->SetWorldLocation({ 500, -200,-10 });
		AstarothRenderer->SetupAttachment(RootComponent);
	}
}
AAstaroth::~AAstaroth()
{
}

void AAstaroth::BeginPlay()
{
	AActor::BeginPlay();
}

void AAstaroth::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}