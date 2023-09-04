#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// ���� :
class OverWorldLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	OverWorldLevel();
	~OverWorldLevel();

	// delete Function
	OverWorldLevel(const OverWorldLevel& _Other) = delete;
	OverWorldLevel(OverWorldLevel&& _Other) noexcept = delete;
	OverWorldLevel& operator=(const OverWorldLevel& _Other) = delete;
	OverWorldLevel& operator=(OverWorldLevel&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

private:

};

