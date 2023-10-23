#pragma once

// Ό³Έν :
class HitFX : public ContentActor
{
public:
	// constrcuter destructer
	HitFX();
	~HitFX();

	// delete Function
	HitFX(const HitFX& _Other) = delete;
	HitFX(HitFX&& _Other) noexcept = delete;
	HitFX& operator=(const HitFX& _Other) = delete;
	HitFX& operator=(HitFX&& _Other) noexcept = delete;

	void RandomFX();
	void EndCheck();

protected:
	void Start() override;
	void Update(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
};
