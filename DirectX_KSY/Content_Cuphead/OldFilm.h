#pragma once
#include <GameEngineCore/GameEngineRenderTarget.h>

// Ό³Έν :
class OldFilm : public Effect
{
public:
	// constrcuter destructer
	OldFilm();
	~OldFilm();

	// delete Function
	OldFilm(const OldFilm& _Other) = delete;
	OldFilm(OldFilm&& _Other) noexcept = delete;
	OldFilm& operator=(const OldFilm& _Other) = delete;
	OldFilm& operator=(OldFilm&& _Other) noexcept = delete;

protected:

private:
	void Start() override;
	void EffectProcess(float _DeltaTime) override;

	int CurIndex = 0;
	float Time = 0.0f;
	std::shared_ptr<GameEngineSprite> FilmSprite;
};

