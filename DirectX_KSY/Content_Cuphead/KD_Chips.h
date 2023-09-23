#pragma once
#include <GameEngineCore\GameEngineActor.h>

// Ό³Έν :
class KD_Chips : public GameEngineActor
{
public:
	// constrcuter destructer
	KD_Chips();
	~KD_Chips();

	// delete Function
	KD_Chips(const KD_Chips& _Other) = delete;
	KD_Chips(KD_Chips&& _Other) noexcept = delete;
	KD_Chips& operator=(const KD_Chips& _Other) = delete;
	KD_Chips& operator=(KD_Chips&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> Renderer;
};

