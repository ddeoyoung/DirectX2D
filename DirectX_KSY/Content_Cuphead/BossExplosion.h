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

	void EndCheck();

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
};

