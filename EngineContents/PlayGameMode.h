#pragma once
#include <EngineCore/Actor.h>

class APlayGameMode : public AActor
{
public:

	APlayGameMode();
	~APlayGameMode();


	APlayGameMode(const APlayGameMode& _Other) = delete;
	APlayGameMode(APlayGameMode&& _Other) noexcept = delete;
	APlayGameMode& operator=(const APlayGameMode& _Other) = delete;
	APlayGameMode& operator=(APlayGameMode&& _Other) noexcept = delete;

	void Tick(float _DeltaTime);

protected:

private:

};

