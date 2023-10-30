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

	void SetAttDir(int _AttDir)
	{
		AttDir = _AttDir;
	}

	void SetPos(float4 _Pos)
	{
		Pos = _Pos;
	}

protected:
	void Start() override;
	void Update(float _Delta) override;

	void MoveUpdate(float _Delta);
	void EndCheck(float _Delta);

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
	std::shared_ptr<class GameEngineSpriteRenderer> TrailRenderer = nullptr;
	std::shared_ptr<class GameEngineCollision> AttackCollision = nullptr;

private:
	int AttDir = 0;
	float LiveTime = 6.0f;

	float4 Pos = float4::ZERO;
	float4 Arm = float4::ZERO;
	float Dis = 0.0f;
	float Angle = 0.0f;
};

