#pragma once
#include "ContentLevel.h"

// Ό³Έν :
class KingDiceLevel : public ContentLevel
{
public:
	// constrcuter destructer
	KingDiceLevel();
	~KingDiceLevel();

	// delete Function
	KingDiceLevel(const KingDiceLevel& _Other) = delete;
	KingDiceLevel(KingDiceLevel&& _Other) noexcept = delete;
	KingDiceLevel& operator=(const KingDiceLevel& _Other) = delete;
	KingDiceLevel& operator=(KingDiceLevel&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;
private:

};

