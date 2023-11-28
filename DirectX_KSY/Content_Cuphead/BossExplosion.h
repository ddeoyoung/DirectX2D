#pragma once

// Ό³Έν :
class BossExplosion : public ContentActor
{
public:
	// constrcuter destructer
	BossExplosion();
	~BossExplosion();

	// delete Function
	BossExplosion(const BossExplosion& _Other) = delete;
	BossExplosion(BossExplosion&& _Other) noexcept = delete;
	BossExplosion& operator=(const BossExplosion& _Other) = delete;
	BossExplosion& operator=(BossExplosion&& _Other) noexcept = delete;

	void SetPos(float4 _Pos);

protected:
	void Start() override;
	void Update(float _Delta) override;

	void SetRandom();

private:
	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;

	float4 BossPos = float4::ZERO;
};

