#pragma once
#include <GameEngineCore\GameEngineActor.h>

// Ό³Έν :
class Attack_Spew : public ContentActor
{
public:
	// constrcuter destructer
	Attack_Spew();
	~Attack_Spew();

	// delete Function
	Attack_Spew(const Attack_Spew& _Other) = delete;
	Attack_Spew(Attack_Spew&& _Other) noexcept = delete;
	Attack_Spew& operator=(const Attack_Spew& _Other) = delete;
	Attack_Spew& operator=(Attack_Spew&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	void EndCheck();

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
	std::shared_ptr<class GameEngineCollision> AttackCollision = nullptr;

private:

};

