#pragma once

// Ό³Έν :
class Roulette_HeathUp : public ContentActor
{
public:
	// constrcuter destructer
	Roulette_HeathUp();
	~Roulette_HeathUp();

	// delete Function
	Roulette_HeathUp(const Roulette_HeathUp& _Other) = delete;
	Roulette_HeathUp(Roulette_HeathUp&& _Other) noexcept = delete;
	Roulette_HeathUp& operator=(const Roulette_HeathUp& _Other) = delete;
	Roulette_HeathUp& operator=(Roulette_HeathUp&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
private:

};

