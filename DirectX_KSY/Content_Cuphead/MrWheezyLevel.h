#pragma once
#include "ContentLevel.h"

// Ό³Έν :
class MrWheezyLevel : public ContentLevel
{
public:
	// constrcuter destructer
	MrWheezyLevel();
	~MrWheezyLevel();

	// delete Function
	MrWheezyLevel(const MrWheezyLevel& _Other) = delete;
	MrWheezyLevel(MrWheezyLevel&& _Other) noexcept = delete;
	MrWheezyLevel& operator=(const MrWheezyLevel& _Other) = delete;
	MrWheezyLevel& operator=(MrWheezyLevel&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;
	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

	void LevelStartTextureLoad();

private:
	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer;
	std::shared_ptr<class BaseCharacter> Player = nullptr;
	std::shared_ptr<class MrWheezy> Boss = nullptr;
};

