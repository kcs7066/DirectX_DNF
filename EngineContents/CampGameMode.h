#pragma once
#include <EngineCore/Actor.h>

class ACampGameMode : public AActor
{
public:
	ACampGameMode();
	~ACampGameMode();

	ACampGameMode(const ACampGameMode& _Other) = delete;
	ACampGameMode(ACampGameMode&& _Other) noexcept = delete;
	ACampGameMode& operator=(const ACampGameMode& _Other) = delete;
	ACampGameMode& operator=(ACampGameMode&& _Other) noexcept = delete;

	void Tick(float _DeltaTime);

protected:

private:
	std::shared_ptr<class ATestImage> TestImage;

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
};

