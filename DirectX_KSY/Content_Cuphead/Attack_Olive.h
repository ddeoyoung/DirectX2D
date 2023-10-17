#pragma once
#include <GameEngineCore\GameEngineActor.h>

// Ό³Έν :
class Attack_Olive : public ContentActor
{
public:
	// constrcuter destructer
	Attack_Olive();
	~Attack_Olive();

	// delete Function
	Attack_Olive(const Attack_Olive& _Other) = delete;
	Attack_Olive(Attack_Olive&& _Other) noexcept = delete;
	Attack_Olive& operator=(const Attack_Olive& _Other) = delete;
	Attack_Olive& operator=(Attack_Olive&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
	std::shared_ptr<class GameEngineCollision> AttackCollision = nullptr;

private:

};

