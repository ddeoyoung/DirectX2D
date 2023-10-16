#pragma once

// Ό³Έν :
class RunDust : public ContentActor
{
public:
	// constrcuter destructer
	RunDust();
	~RunDust();

	// delete Function
	RunDust(const RunDust& _Other) = delete;
	RunDust(RunDust&& _Other) noexcept = delete;
	RunDust& operator=(const RunDust& _Other) = delete;
	RunDust& operator=(RunDust&& _Other) noexcept = delete;

	void EndCheck();

protected:
	void Start() override;
	void Update(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
};

