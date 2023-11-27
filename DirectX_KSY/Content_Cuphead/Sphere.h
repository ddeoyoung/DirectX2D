#pragma once

// Ό³Έν :
class Sphere : public ContentActor
{
public:
	// constrcuter destructer
	Sphere();
	~Sphere();

	// delete Function
	Sphere(const Sphere& _Other) = delete;
	Sphere(Sphere&& _Other) noexcept = delete;
	Sphere& operator=(const Sphere& _Other) = delete;
	Sphere& operator=(Sphere&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
	std::shared_ptr<class GameEngineCollision> ParryCollision = nullptr;

	float CollisionOffTime = 0.0f;
	bool IsParry = false;
};

