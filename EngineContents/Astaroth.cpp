#include "PreCompile.h"
#include "Astaroth.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/CameraActor.h>
#include <EngineCore/TimeEventComponent.h>
#include "MyRenderer.h"
#include "Infighter.h"

AAstaroth::AAstaroth()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;
	RootComponent->SetWorldLocation({ 600, -60,-10 });

	AstarothRenderer = CreateDefaultSubObject<USpriteRenderer>();

	AstarothRenderer->CreateAnimation("astaroth_Appearance", "astaroth", { 50,51,52,53,54,55,56,57,58,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41 }, 0.2f);

	AstarothRenderer->CreateAnimation("astaroth_Appearance", "astaroth", 50, 58, 0.2f);
	AstarothRenderer->CreateAnimation("astaroth_Idle", "astaroth", 0, 7, 0.2f);
	AstarothRenderer->CreateAnimation("astaroth_RushReady", "astaroth", { 251,252,253,237,238,239,240 }, 0.2f);
	AstarothRenderer->CreateAnimation("astaroth_Rush", "astaroth", 254, 257, 0.2f);

	AstarothRenderer->CreateAnimation("astaroth_Jump", "astaroth", { 18,19,20,21,22,23 }, { 0.1f,0.1f,0.1f,0.7f,0.1f,0.1f });
	AstarothRenderer->CreateAnimation("astaroth_Landing", "astaroth", { 165,166,167,168,169,170,171 }, { 1.03f,0.03f,0.03f,0.03f,0.03f,0.05f,1.0f });

	{
		AstarothRenderer->ChangeAnimation("astaroth_Appearance");
		AstarothRenderer->SetAutoScaleRatio(1.5f);

		AstarothRenderer->SetupAttachment(RootComponent);
	}
}
AAstaroth::~AAstaroth()
{
}

void AAstaroth::BeginPlay()
{
	AActor::BeginPlay();
	FSM.CreateState(AstarothState::Appearance, std::bind(&AAstaroth::Appearance, this, std::placeholders::_1),
		[this]()
		{
			AstarothRenderer->ChangeAnimation("astaroth_Appearance");
		}
	);

	FSM.CreateState(AstarothState::Idle, std::bind(&AAstaroth::Idle, this, std::placeholders::_1),
		[this]()
		{
			AstarothRenderer->ChangeAnimation("astaroth_Idle");
		}
	);

	FSM.CreateState(AstarothState::RushReady, std::bind(&AAstaroth::RushReady, this, std::placeholders::_1),
		[this]()
		{
			AstarothRenderer->ChangeAnimation("astaroth_RushReady");
		}
	);

	FSM.CreateState(AstarothState::Rush, std::bind(&AAstaroth::Rush, this, std::placeholders::_1),
		[this]()
		{
			AstarothRenderer->ChangeAnimation("astaroth_Rush");
		}
	);

	FSM.CreateState(AstarothState::Jump, std::bind(&AAstaroth::Jump, this, std::placeholders::_1),
		[this]()
		{
			AstarothRenderer->ChangeAnimation("astaroth_Jump");
		}
	);

	FSM.CreateState(AstarothState::Landing, std::bind(&AAstaroth::Landing, this, std::placeholders::_1),
		[this]()
		{
			AstarothRenderer->ChangeAnimation("astaroth_Landing");
		}
	);

	RootComponent->SetScale3D({ -1,1 });
	FSM.ChangeState(AstarothState::Idle);
}

void AAstaroth::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	DelayTime -= _DeltaTime;
	FSM.Update(_DeltaTime);
}


void AAstaroth::Appearance(float _DeltaTime)
{

	if (0 > DelayTime)
	{
		FSM.ChangeState(AstarothState::Idle);
		DelayTime = 1.0f;
	}

}

void AAstaroth::Idle(float _DeltaTime)
{

	if (0 > DelayTime)
	{
		int Randomint = Random.RandomInt(1, 2);
		switch (Randomint)
		{
		case 1:
			FSM.ChangeState(AstarothState::RushReady);
			PlayerPos = GetWorld()->GetMainPawn()->GetActorLocation();
			RushDir = PlayerPos - GetActorLocation();
			RushDir.Normalize();
			if (0 > RushDir.X)
			{
				SeeRight = false;
			}
			else
			{
				SeeRight = true;
			}
			DirChange();
			DelayTime = 1.4f;
			break;

		case 2:
			FSM.ChangeState(AstarothState::Jump);
			PlayerPos = GetWorld()->GetMainPawn()->GetActorLocation();
			DelayTime = 1.2f;
			break;

		default:
			break;
		}

	}
}

void AAstaroth::Move(float _DeltaTime)
{

}

//void AAstaroth::RushStart()
//{
//	RushDir = GetWorld()->GetMainPawn()->GetActorLocation() - this->GetActorLocation();
//	RushDir.Normalize();
//	FSM.ChangeState(AstarothState::Rush);
//	DelayTime = 1.4f;
//}

void AAstaroth::RushReady(float _DeltaTime)
{

	if (0.0f > DelayTime)
	{
		FSM.ChangeState(AstarothState::Rush);
		if (0 > RushDir.X)
		{
			AddActorRotation({ 0, 0, 90 });
		}
		else
		{
			AddActorRotation({ 0, 0, -90 });
		}


		DelayTime = 3.0f;
	}
}

void AAstaroth::Rush(float _DeltaTime)
{
	AddActorLocation(RushDir * 2000 * _DeltaTime);
	if (-800 > GetActorLocation().X ||
		1216 < GetActorLocation().X ||
		-450 > GetActorLocation().Y ||
		100 < GetActorLocation().Y ||
		0.0f > DelayTime
		)
	{
		FSM.ChangeState(AstarothState::Idle);
		DelayTime = 1.0f;
		if (0 > RushDir.X)
		{
			AddActorRotation({ 0, 0, -90 });
		}
		else
		{
			AddActorRotation({ 0, 0, 90 });
		}

	}

}

void AAstaroth::Trace(float _DeltaTime)
{

}

void AAstaroth::Jump(float _DeltaTime)
{
	if (0.2f > DelayTime)
	{
		AddActorLocation({ 0,4500 * _DeltaTime,0 });
	}

	if (0.0f > DelayTime)
	{
		FSM.ChangeState(AstarothState::Landing);
		FVector UpValue = { 0, 1000, 0 };
		FVector LandingPos = PlayerPos + UpValue;
		SetActorLocation(LandingPos);
		DelayTime = 2.2f;
	}
}

void AAstaroth::Landing(float _DeltaTime)
{
	if (1.2f > DelayTime)
	{
		if (1.0f < DelayTime)
		{
			AddActorLocation({ 0,-4500 * _DeltaTime,0 });
		}
		else if (0.0f > DelayTime)
		{
			FSM.ChangeState(AstarothState::Idle);
			DelayTime = 1.0f;
		}
	}
}

void AAstaroth::AfterImage(float _DeltaTime)
{

}

void AAstaroth::BorderTime(float _DeltaTime)
{

}

void AAstaroth::Groggy(float _DeltaTime)
{

}

void AAstaroth::Die(float _DeltaTime)
{

}