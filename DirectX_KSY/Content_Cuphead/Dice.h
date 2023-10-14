#pragma once

// Ό³Έν :
class Dice : ContentActor
{
public:
	// constrcuter destructer
	Dice();
	~Dice();

	// delete Function
	Dice(const Dice& _Other) = delete;
	Dice(Dice&& _Other) noexcept = delete;
	Dice& operator=(const Dice& _Other) = delete;
	Dice& operator=(Dice&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
private:

};

