#pragma once
#include "ContentLevel.h"

// Ό³Έν :
class PipandDotLevel : public ContentLevel
{
public:
	// constrcuter destructer
	PipandDotLevel();
	~PipandDotLevel();

	// delete Function
	PipandDotLevel(const PipandDotLevel& _Other) = delete;
	PipandDotLevel(PipandDotLevel&& _Other) noexcept = delete;
	PipandDotLevel& operator=(const PipandDotLevel& _Other) = delete;
	PipandDotLevel& operator=(PipandDotLevel&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;
	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

	void LevelStartTextureLoad();
	void LevelStartTextureSet();

private:
	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer;
	std::shared_ptr<class BaseCharacter> Player = nullptr;
	std::shared_ptr<class MrWheezy> Boss = nullptr;
};

