#pragma once

// Ό³Έν :
class Attack_FireBullet : public ContentActor
{
public:
	// constrcuter destructer
	Attack_FireBullet();
	~Attack_FireBullet();

	// delete Function
	Attack_FireBullet(const Attack_FireBullet& _Other) = delete;
	Attack_FireBullet(Attack_FireBullet&& _Other) noexcept = delete;
	Attack_FireBullet& operator=(const Attack_FireBullet& _Other) = delete;
	Attack_FireBullet& operator=(Attack_FireBullet&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
	std::shared_ptr<class GameEngineCollision> AttackCollision = nullptr;

private:

};

