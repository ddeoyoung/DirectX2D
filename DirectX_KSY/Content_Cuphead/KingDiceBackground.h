#pragma once
#include <GameEngineCore\GameEngineActor.h>

// Ό³Έν :
class KingDiceBackground : public GameEngineActor
{
public:
	// constrcuter destructer
	KingDiceBackground();
	~KingDiceBackground();

	// delete Function
	KingDiceBackground(const KingDiceBackground& _Other) = delete;
	KingDiceBackground(KingDiceBackground&& _Other) noexcept = delete;
	KingDiceBackground& operator=(const KingDiceBackground& _Other) = delete;
	KingDiceBackground& operator=(KingDiceBackground&& _Other) noexcept = delete;

protected:
	void Start() override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> Renderer;
};

