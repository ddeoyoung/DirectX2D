#pragma once

// Ό³Έν :
class Roulette_Cleared : public ContentActor
{
public:
	// constrcuter destructer
	Roulette_Cleared();
	~Roulette_Cleared();

	// delete Function
	Roulette_Cleared(const Roulette_Cleared& _Other) = delete;
	Roulette_Cleared(Roulette_Cleared&& _Other) noexcept = delete;
	Roulette_Cleared& operator=(const Roulette_Cleared& _Other) = delete;
	Roulette_Cleared& operator=(Roulette_Cleared&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
private:

};

