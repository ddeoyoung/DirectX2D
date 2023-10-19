#pragma once

// Ό³Έν :
class Roulette_Spaces : public ContentActor
{
public:
	// constrcuter destructer
	Roulette_Spaces();
	~Roulette_Spaces();

	// delete Function
	Roulette_Spaces(const Roulette_Spaces& _Other) = delete;
	Roulette_Spaces(Roulette_Spaces&& _Other) noexcept = delete;
	Roulette_Spaces& operator=(const Roulette_Spaces& _Other) = delete;
	Roulette_Spaces& operator=(Roulette_Spaces&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
private:

};

