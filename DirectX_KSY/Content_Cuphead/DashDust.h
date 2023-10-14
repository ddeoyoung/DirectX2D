#pragma once

// Ό³Έν :
class DashDust : public ContentActor
{
public:
	// constrcuter destructer
	DashDust();
	~DashDust();

	// delete Function
	DashDust(const DashDust& _Other) = delete;
	DashDust(DashDust&& _Other) noexcept = delete;
	DashDust& operator=(const DashDust& _Other) = delete;
	DashDust& operator=(DashDust&& _Other) noexcept = delete;

	void EndCheck();

protected:
	void Start() override;
	void Update(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
};

