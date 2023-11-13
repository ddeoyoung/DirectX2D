#pragma once
#include "ContentLevel.h"

enum class TipsyActorOrder
{
	Foreground = 20,
	Blend,
};

// Ό³Έν :
class TipsyTroopLevel : public ContentLevel
{
public:
	// constrcuter destructer
	TipsyTroopLevel();
	~TipsyTroopLevel();

	// delete Function
	TipsyTroopLevel(const TipsyTroopLevel& _Other) = delete;
	TipsyTroopLevel(TipsyTroopLevel&& _Other) noexcept = delete;
	TipsyTroopLevel& operator=(const TipsyTroopLevel& _Other) = delete;
	TipsyTroopLevel& operator=(TipsyTroopLevel&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

	void LevelStartTextureLoad();

private:
	std::shared_ptr<class GameEngineSpriteRenderer> Renderer;
	std::shared_ptr<class Martini> BossMartini = nullptr;
	std::shared_ptr<class Rum> BossRum = nullptr;
	std::shared_ptr<class Scotch> BossScotch = nullptr;
	std::shared_ptr<class FightText> Ready = nullptr;
	std::shared_ptr<class FightText> KnockOut = nullptr;

	bool IsStageClear = false;
};

