#pragma once

// Ό³Έν :
class ParrySpark_Character : public ContentActor
{
public:
	// constrcuter destructer
	ParrySpark_Character();
	~ParrySpark_Character();

	// delete Function
	ParrySpark_Character(const ParrySpark_Character& _Other) = delete;
	ParrySpark_Character(ParrySpark_Character&& _Other) noexcept = delete;
	ParrySpark_Character& operator=(const ParrySpark_Character& _Other) = delete;
	ParrySpark_Character& operator=(ParrySpark_Character&& _Other) noexcept = delete;

	void EndCheck();

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
};
