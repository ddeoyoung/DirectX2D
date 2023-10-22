#pragma once

// Ό³Έν :
class ParrySpark_Object : public ContentActor
{
public:
	// constrcuter destructer
	ParrySpark_Object();
	~ParrySpark_Object();

	// delete Function
	ParrySpark_Object(const ParrySpark_Object& _Other) = delete;
	ParrySpark_Object(ParrySpark_Object&& _Other) noexcept = delete;
	ParrySpark_Object& operator=(const ParrySpark_Object& _Other) = delete;
	ParrySpark_Object& operator=(ParrySpark_Object&& _Other) noexcept = delete;

	void EndCheck();

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
};
