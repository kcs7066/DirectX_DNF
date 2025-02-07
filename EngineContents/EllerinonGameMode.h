#pragma once
#include <EnginePlatform/EngineSound.h>

class AEllerinonGameMode : public AGameMode
{
public:
	AEllerinonGameMode();
	~AEllerinonGameMode();

	AEllerinonGameMode(const AEllerinonGameMode& _Other) = delete;
	AEllerinonGameMode(AEllerinonGameMode&& _Other) noexcept = delete;
	AEllerinonGameMode& operator=(const AEllerinonGameMode& _Other) = delete;
	AEllerinonGameMode& operator=(AEllerinonGameMode&& _Other) noexcept = delete;

	void BeginPlay();
	void Tick(float _DeltaTime);

	std::shared_ptr<class AAstaroth> NewAstaroth;

protected:

	void LevelChangeStart() override;

private:
	std::shared_ptr<class AInfighter> NewInfighter;
	std::shared_ptr<class AGrandis> NewGrandis;

	std::shared_ptr<class USpriteRenderer> BackGroundRenderer0;
	std::shared_ptr<class USpriteRenderer> BackGroundRenderer1;
	std::shared_ptr<class USpriteRenderer> BackGroundRenderer2;
	std::shared_ptr<class USpriteRenderer> BackGroundRenderer3;
	std::shared_ptr<class USpriteRenderer> BackGroundRenderer4;

	std::shared_ptr<class USpriteRenderer> BackGroundRenderer5;
	std::shared_ptr<class USpriteRenderer> BackGroundRenderer6;
	std::shared_ptr<class USpriteRenderer> BackGroundRenderer7;
	std::shared_ptr<class USpriteRenderer> BackGroundRenderer13;

	std::shared_ptr<class USpriteRenderer> BackGroundRenderer8;
	std::shared_ptr<class USpriteRenderer> BackGroundRenderer9;
	std::shared_ptr<class USpriteRenderer> BackGroundRenderer10;
	std::shared_ptr<class USpriteRenderer> BackGroundRenderer11;
	std::shared_ptr<class USpriteRenderer> BackGroundRenderer12;

	std::shared_ptr<class USpriteRenderer> BackGroundRenderer14;

	float PlayTime = 0.0f;

	USoundPlayer BGMPlayer;

};

