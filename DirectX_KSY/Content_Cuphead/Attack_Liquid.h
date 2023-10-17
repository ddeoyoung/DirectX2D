#pragma once
#include <GameEngineCore\GameEngineActor.h>

// Ό³Έν :
class Attack_Liquid : public ContentActor
{
public:
	// constrcuter destructer
	Attack_Liquid();
	~Attack_Liquid();

	// delete Function
	Attack_Liquid(const Attack_Liquid& _Other) = delete;
	Attack_Liquid(Attack_Liquid&& _Other) noexcept = delete;
	Attack_Liquid& operator=(const Attack_Liquid& _Other) = delete;
	Attack_Liquid& operator=(Attack_Liquid&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
	std::shared_ptr<class GameEngineCollision> AttackCollision = nullptr;

private:

};

