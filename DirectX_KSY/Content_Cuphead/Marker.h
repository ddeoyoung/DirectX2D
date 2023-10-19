#pragma once

enum class MarkerState
{
	None,
	Idle,
	Spin,
};

// Ό³Έν :
class Marker : public ContentActor
{
public:
	// constrcuter destructer
	Marker();
	~Marker();

	// delete Function
	Marker(const Marker& _Other) = delete;
	Marker(Marker&& _Other) noexcept = delete;
	Marker& operator=(const Marker& _Other) = delete;
	Marker& operator=(Marker&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;

private:

};

