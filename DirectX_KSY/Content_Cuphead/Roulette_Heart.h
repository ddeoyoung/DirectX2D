#pragma once

// Ό³Έν :
class Roulette_Heart : public ContentActor
{
public:
	// constrcuter destructer
	Roulette_Heart();
	~Roulette_Heart();

	// delete Function
	Roulette_Heart(const Roulette_Heart& _Other) = delete;
	Roulette_Heart(Roulette_Heart&& _Other) noexcept = delete;
	Roulette_Heart& operator=(const Roulette_Heart& _Other) = delete;
	Roulette_Heart& operator=(Roulette_Heart&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
private:

};

