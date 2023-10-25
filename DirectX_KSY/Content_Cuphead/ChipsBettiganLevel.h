#pragma once
#include "ContentLevel.h"


// Ό³Έν :
class ChipsBettiganLevel : public ContentLevel
{
public:
	// constrcuter destructer
	ChipsBettiganLevel();
	~ChipsBettiganLevel();

	// delete Function
	ChipsBettiganLevel(const ChipsBettiganLevel& _Other) = delete;
	ChipsBettiganLevel(ChipsBettiganLevel&& _Other) noexcept = delete;
	ChipsBettiganLevel& operator=(const ChipsBettiganLevel& _Other) = delete;
	ChipsBettiganLevel& operator=(ChipsBettiganLevel&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> Renderer;

	std::shared_ptr<class BaseCharacter> Player = nullptr;
	std::shared_ptr<class ChipsBettigan> Boss = nullptr;

};

