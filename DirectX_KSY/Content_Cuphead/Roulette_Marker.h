#pragma once

// Ό³Έν :
class Roulette_Marker : public ContentActor
{
public:
	// constrcuter destructer
	Roulette_Marker();
	~Roulette_Marker();

	// delete Function
	Roulette_Marker(const Roulette_Marker& _Other) = delete;
	Roulette_Marker(Roulette_Marker&& _Other) noexcept = delete;
	Roulette_Marker& operator=(const Roulette_Marker& _Other) = delete;
	Roulette_Marker& operator=(Roulette_Marker&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
private:

};

