#pragma once

// Ό³Έν :
class Attack_CiggyDemon : public ContentActor
{
public:
	// constrcuter destructer
	Attack_CiggyDemon();
	~Attack_CiggyDemon();

	// delete Function
	Attack_CiggyDemon(const Attack_CiggyDemon& _Other) = delete;
	Attack_CiggyDemon(Attack_CiggyDemon&& _Other) noexcept = delete;
	Attack_CiggyDemon& operator=(const Attack_CiggyDemon& _Other) = delete;
	Attack_CiggyDemon& operator=(Attack_CiggyDemon&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	void SetRandomPos();

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
	std::shared_ptr<class GameEngineSpriteRenderer> FxRenderer = nullptr;
	std::shared_ptr<class GameEngineCollision> AttackCollision = nullptr;

private:

};

