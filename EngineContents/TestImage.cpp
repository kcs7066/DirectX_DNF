#include "PreCompile.h"
#include "TestImage.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/DefaultSceneComponent.h>
#include "MyRenderer.h"

ATestImage::ATestImage()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	TestRenderer = CreateDefaultSubObject<USpriteRenderer>();

	TestRenderer->CreateAnimation("Idle", "Test", 0, 7, 0.2f);
	{
		USpriteRenderer::FrameAnimation* Animation = TestRenderer->FindAnimation("Idle");
		Animation->IsAutoScale = true;
		Animation->AutoScaleRatio = 2.0f;
	}

	TestRenderer->CreateAnimation("Move", "Test", 8, 17, 0.2f);

	{
		USpriteRenderer::FrameAnimation* Animation = TestRenderer->FindAnimation("Move");
		Animation->IsAutoScale = true;
		Animation->AutoScaleRatio = 2.0f;
	}

	TestRenderer->ChangeAnimation("Idle");

	TestRenderer->SetRelativeScale3D({ 50, 50, 1.0f });
	TestRenderer->SetupAttachment(RootComponent);

}

ATestImage::~ATestImage()
{
}

void ATestImage::BeginPlay()
{
	AActor::BeginPlay();
}

void ATestImage::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (UEngineInput::IsPress('A'))
	{
		AddRelativeLocation(FVector{ -100.0f * _DeltaTime, 0.0f, 0.0f });
	}
	if (UEngineInput::IsPress('D'))
	{
		AddRelativeLocation(FVector{ 100.0f * _DeltaTime, 0.0f, 0.0f });
	}

	if (UEngineInput::IsPress('W'))
	{
		AddRelativeLocation(FVector{ 0.0f, 100.0f * _DeltaTime, 0.0f });
	}

	if (UEngineInput::IsPress('S'))
	{
		AddRelativeLocation(FVector{ 0.0f, -100.0f * _DeltaTime, 0.0f });
	}

	if (UEngineInput::IsPress('Q'))
	{
		AddActorRotation(FVector{ 0.0f, 0.0f , 360.0f * _DeltaTime });
	}

	if (UEngineInput::IsPress('E'))
	{
		TestRenderer->ChangeAnimation("Move");
					}

	if (UEngineInput::IsPress('R'))
	{
		TestRenderer->ChangeAnimation("Idle");
			}

	}