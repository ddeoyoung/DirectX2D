#pragma once

// Ό³Έν :
class Roulette_Odds : public ContentActor
{
public:
	// constrcuter destructer
	Roulette_Odds();
	~Roulette_Odds();

	// delete Function
	Roulette_Odds(const Roulette_Odds& _Other) = delete;
	Roulette_Odds(Roulette_Odds&& _Other) noexcept = delete;
	Roulette_Odds& operator=(const Roulette_Odds& _Other) = delete;
	Roulette_Odds& operator=(Roulette_Odds&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
private:

};

