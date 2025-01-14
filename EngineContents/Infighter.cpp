#include "PreCompile.h"
#include "Infighter.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/CameraActor.h>
#include <EngineCore/TimeEventComponent.h>
#include "MyRenderer.h"

AInfighter::AInfighter()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	InfighterRenderer = CreateDefaultSubObject<USpriteRenderer>();

	InfighterRenderer->CreateAnimation("infighter_IdleCamp", "infighter", 0, 3, 0.5f);
	InfighterRenderer->CreateAnimation("infighter_IdleBattle", "infighter", 4, 7, 0.5f);
	InfighterRenderer->CreateAnimation("infighter_Attack", "infighter", 8, 22, 0.1f);
	InfighterRenderer->CreateAnimation("infighter_Move", "infighter", 65, 72, 0.2f);
	InfighterRenderer->CreateAnimation("infighter_Dash", "infighter", 73, 78, 0.2f);
	InfighterRenderer->CreateAnimation("infighter_Jump", "infighter", 90, 94, 0.2f);
	InfighterRenderer->CreateAnimation("infighter_Ducking", "infighter", 132, 134, 0.2f);
	InfighterRenderer->CreateAnimation("infighter_Sway", "infighter", 135, 137, 0.2f);
	InfighterRenderer->CreateAnimation("infighter_Roll", "infighter", 53, 64, 0.2f);

	InfighterRenderer->SetAutoScaleRatio(1.5f);
	InfighterRenderer->SetRelativeLocation({ 0,0,-200 });
	InfighterRenderer->SetupAttachment(RootComponent);

	//buffRenderer = CreateDefaultSubObject<USpriteRenderer>();
	//buffRenderer->CreateAnimation("infighter_buff", "buff", 0, 18, 0.1f);
	//
	//buffRenderer->SetRelativeLocation({ 0,150,-20 });
	//buffRenderer->SetupAttachment(RootComponent);


 //   neoRenderer = CreateDefaultSubObject<USpriteRenderer>();
	//neoRenderer->CreateAnimation("infighter_neo", "neo", 0, 22, 0.1f);

	//neoRenderer->SetAutoScaleRatio(1.5f);
	//neoRenderer->SetWorldLocation({ 0,0,-30 });
	//neoRenderer->SetupAttachment(RootComponent);

}

AInfighter::~AInfighter()
{
}

void AInfighter::BeginPlay()
{
	AActor::BeginPlay();

	FSM.CreateState(InfighterState::Idle, std::bind(&AInfighter::Idle, this, std::placeholders::_1),
		[this]()
		{
			if (true == IsMonster)
			{
				InfighterRenderer->ChangeAnimation("infighter_IdleBattle");
			}
			else
			{
				InfighterRenderer->ChangeAnimation("infighter_IdleCamp");
			}
		}
	);

	FSM.CreateState(InfighterState::Move, std::bind(&AInfighter::Move, this, std::placeholders::_1),
		[this]()
		{
			if (true == DashValue)
			{
				InfighterRenderer->ChangeAnimation("infighter_Dash");
			}
			else
			{
				InfighterRenderer->ChangeAnimation("infighter_Move");
			}
		}
	);


	FSM.CreateState(InfighterState::Jump, std::bind(&AInfighter::Jump, this, std::placeholders::_1),
		[this]()
		{
			InfighterRenderer->ChangeAnimation("infighter_Jump");
			Delaytime = 1.0f;
		}
	);

	FSM.CreateState(InfighterState::Attack, std::bind(&AInfighter::Attack, this, std::placeholders::_1),
		[this]()
		{
			InfighterRenderer->ChangeAnimation("infighter_Attack");
		}
	);

	FSM.CreateState(InfighterState::Ducking, std::bind(&AInfighter::Ducking, this, std::placeholders::_1),
		[this]()
		{
			InfighterRenderer->ChangeAnimation("infighter_Ducking");
			Delaytime = 0.6f;
		}
	);

	FSM.CreateState(InfighterState::Sway, std::bind(&AInfighter::Sway, this, std::placeholders::_1),
		[this]()
		{
			InfighterRenderer->ChangeAnimation("infighter_Sway");
			Delaytime = 0.6f;
		}
	);

	FSM.ChangeState(InfighterState::Idle);
}

void AInfighter::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (UEngineInput::IsPress('Q'))
	{
		AddActorRotation(FVector{ 360.0f * _DeltaTime,0, 0.0 });
	}

	if (UEngineInput::IsPress('E'))
	{
		//buffRenderer->ChangeAnimation("infighter_buff");
		IsMonster = true;
	}

	if (UEngineInput::IsPress('R'))
	{
		neoRenderer->ChangeAnimation("infighter_neo");
	}
	FSM.Update(_DeltaTime);

}

void AInfighter::Idle(float _DeltaTime)
{
	if (true == UEngineInput::IsPress(VK_LEFT) ||
		true == UEngineInput::IsPress(VK_RIGHT) ||
		true == UEngineInput::IsPress(VK_DOWN) ||
		true == UEngineInput::IsPress(VK_UP))
	{
		DashValue = false;
		Speed = 300;
		FSM.ChangeState(InfighterState::Move);
	}

	if (true == UEngineInput::IsDoubleClick(VK_LEFT, 0.1f) ||
		true == UEngineInput::IsDoubleClick(VK_RIGHT, 0.1f) ||
		true == UEngineInput::IsDoubleClick(VK_DOWN, 0.1f) ||
		true == UEngineInput::IsDoubleClick(VK_UP, 0.1f))
	{
		DashValue = true;
		Speed = 600;
		FSM.ChangeState(InfighterState::Move);
	}

	if (true == UEngineInput::IsPress('Z'))
	{
		DuckingDir = { 1,0 };
		FSM.ChangeState(InfighterState::Ducking);
	}

	if (true == UEngineInput::IsPress('X'))
	{
		FSM.ChangeState(InfighterState::Attack);
	}

	if (true == UEngineInput::IsPress('C'))
	{
		FSM.ChangeState(InfighterState::Jump);
	}
	 
	if (true == UEngineInput::IsPress('A'))
	{
		DuckingDir = { -1,0 };
		FSM.ChangeState(InfighterState::Sway);
	}

}

void AInfighter::Move(float _DeltaTime)
{
	if (UEngineInput::IsPress('C'))
	{
		FSM.ChangeState(InfighterState::Jump);
	}
	if (true == UEngineInput::IsPress('Z') &&
		true == UEngineInput::IsPress(VK_UP) &&
		true == UEngineInput::IsPress(VK_RIGHT))
	{
		DuckingDir = { 1,1 };
		FSM.ChangeState(InfighterState::Ducking);
	}
	else if (true == UEngineInput::IsPress('Z') &&
		true == UEngineInput::IsPress(VK_UP) &&
		true == UEngineInput::IsPress(VK_LEFT))
	{
		DuckingDir = { -1,1 };
		FSM.ChangeState(InfighterState::Ducking);
	}
	else if (true == UEngineInput::IsPress('Z') &&
		true == UEngineInput::IsPress(VK_DOWN) &&
		true == UEngineInput::IsPress(VK_RIGHT))
	{
		DuckingDir = { 1,-1 };
		FSM.ChangeState(InfighterState::Ducking);
	}
	else if (true == UEngineInput::IsPress('Z') &&
		true == UEngineInput::IsPress(VK_DOWN) &&
		true == UEngineInput::IsPress(VK_LEFT))
	{
		DuckingDir = { -1,-1 };
		FSM.ChangeState(InfighterState::Ducking);
	}
	else if (true == UEngineInput::IsPress('Z') &&
		true == UEngineInput::IsPress(VK_RIGHT))
	{
		DuckingDir = { 1,0 };
		FSM.ChangeState(InfighterState::Ducking);
	}
	else if (true == UEngineInput::IsPress('Z') &&
		true == UEngineInput::IsPress(VK_LEFT))
	{
		DuckingDir = { -1,0 };
		FSM.ChangeState(InfighterState::Ducking);
	}

	if (true == UEngineInput::IsPress('A') &&
		true == UEngineInput::IsPress(VK_UP) &&
		true == UEngineInput::IsPress(VK_RIGHT))
	{
		DuckingDir = { -1,1 };
		FSM.ChangeState(InfighterState::Sway);
	}
	else if (true == UEngineInput::IsPress('A') &&
		true == UEngineInput::IsPress(VK_UP) &&
		true == UEngineInput::IsPress(VK_LEFT))
	{
		DuckingDir = { 1,1 };
		FSM.ChangeState(InfighterState::Sway);
	}
	else if (true == UEngineInput::IsPress('A') &&
		true == UEngineInput::IsPress(VK_DOWN) &&
		true == UEngineInput::IsPress(VK_RIGHT))
	{
		DuckingDir = { -1,-1 };
		FSM.ChangeState(InfighterState::Sway);
	}
	else if (true == UEngineInput::IsPress('A') &&
		true == UEngineInput::IsPress(VK_DOWN) &&
		true == UEngineInput::IsPress(VK_LEFT))
	{
		DuckingDir = { 1,-1 };
		FSM.ChangeState(InfighterState::Sway);
	}
	else if (true == UEngineInput::IsPress('A') &&
		true == UEngineInput::IsPress(VK_RIGHT))
	{
		DuckingDir = { -1,0 };
		FSM.ChangeState(InfighterState::Sway);
	}
	else if (true == UEngineInput::IsPress('A') &&
		true == UEngineInput::IsPress(VK_LEFT))
	{
		DuckingDir = { 1,0 };
		FSM.ChangeState(InfighterState::Sway);
	}

	if (UEngineInput::IsPress(VK_LEFT))
	{
		AddRelativeLocation(FVector{ -Speed * _DeltaTime, 0.0f, 0.0f });
	}
	if (UEngineInput::IsPress(VK_RIGHT))
	{
		AddRelativeLocation(FVector{ Speed * _DeltaTime, 0.0f, 0.0f });
	}

	if (UEngineInput::IsPress(VK_UP))
	{
		AddRelativeLocation(FVector{ 0.0f, Speed * _DeltaTime, 0.0f });
	}

	if (UEngineInput::IsPress(VK_DOWN))
	{
		AddRelativeLocation(FVector{ 0.0f, -Speed * _DeltaTime, 0.0f });
	}

	if (true == UEngineInput::IsPress('X'))
	{
		FSM.ChangeState(InfighterState::Attack);
	}

	if (false == UEngineInput::IsPress(VK_LEFT) &&
		false == UEngineInput::IsPress(VK_UP) &&
		false == UEngineInput::IsPress(VK_RIGHT) &&
		false == UEngineInput::IsPress(VK_DOWN))
	{
		Speed = 300;
		FSM.ChangeState(InfighterState::Idle);
	}
}

void AInfighter::Jump(float _DeltaTime)
{
	Delaytime -= _DeltaTime;
	if (0.5f < Delaytime)
	{
		AddRelativeLocation(FVector{ 0.0f, Speed * _DeltaTime, 0.0f });
	}
	else
	{
		AddRelativeLocation(FVector{ 0.0f , -Speed * _DeltaTime, 0.0f });
	}

	if (UEngineInput::IsPress(VK_LEFT))
	{
		AddRelativeLocation(FVector{ -Speed * _DeltaTime, 0.0f, 0.0f });
	}
	if (UEngineInput::IsPress(VK_RIGHT))
	{
		AddRelativeLocation(FVector{ Speed * _DeltaTime, 0.0f, 0.0f });
	}

	if (UEngineInput::IsPress(VK_UP))
	{
		AddRelativeLocation(FVector{ 0.0f, Speed * _DeltaTime, 0.0f });
	}

	if (UEngineInput::IsPress(VK_DOWN))
	{
		AddRelativeLocation(FVector{ 0.0f, -Speed * _DeltaTime, 0.0f });
	}

	if (0.0f > Delaytime)
	{
		FSM.ChangeState(InfighterState::Idle);
	}
}

void AInfighter::Attack(float _DeltaTime)
{
	if (false == UEngineInput::IsPress('X'))
	{
		FSM.ChangeState(InfighterState::Idle);
	}
}

void AInfighter::Skill(float _DeltaTime)
{
}

void AInfighter::Ducking(float _DeltaTime)
{
	Delaytime -= _DeltaTime;

	AddRelativeLocation(FVector{ DuckingDir.X * Speed * _DeltaTime, DuckingDir.Y * Speed * _DeltaTime, 0.0f });

	if (UEngineInput::IsPress('C')||
		0.0f > Delaytime)
	{
		FSM.ChangeState(InfighterState::Idle);
	}

}
void AInfighter::Sway(float _DeltaTime)
{
	Delaytime -= _DeltaTime;

	AddRelativeLocation(FVector{ DuckingDir.X * Speed * _DeltaTime, DuckingDir.Y * Speed * _DeltaTime, 0.0f });

	if (UEngineInput::IsPress('C') ||
		0.0f > Delaytime)
	{
		FSM.ChangeState(InfighterState::Idle);
	}
}
void AInfighter::Roll(float _DeltaTime)
{

}