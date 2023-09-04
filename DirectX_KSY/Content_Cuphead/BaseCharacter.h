#pragma once
#include <GameEngineCore\GameEngineActor.h>

// Ό³Έν :
class BaseCharacter : public GameEngineActor
{
public:
	// constrcuter destructer
	BaseCharacter();
	~BaseCharacter();

	// delete Function
	BaseCharacter(const BaseCharacter& _Other) = delete;
	BaseCharacter(BaseCharacter&& _Other) noexcept = delete;
	BaseCharacter& operator=(const BaseCharacter& _Other) = delete;
	BaseCharacter& operator=(BaseCharacter&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
};

