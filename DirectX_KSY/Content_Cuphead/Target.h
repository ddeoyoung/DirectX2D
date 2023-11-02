#pragma once

// Ό³Έν :
class Target : public ContentActor
{
public:
	// constrcuter destructer
	Target();
	~Target();

	// delete Function
	Target(const Target& _Other) = delete;
	Target(Target&& _Other) noexcept = delete;
	Target& operator=(const Target& _Other) = delete;
	Target& operator=(Target&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> TargetRenderer = nullptr;
	std::shared_ptr<class GameEngineSpriteRenderer> TopperRenderer = nullptr;
	std::shared_ptr<class GameEngineCollision> TargetCollision = nullptr;
};

