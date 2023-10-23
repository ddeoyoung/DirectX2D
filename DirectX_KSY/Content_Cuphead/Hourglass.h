#pragma once

// Ό³Έν :
class Hourglass : public ContentActor
{
public:
	// constrcuter destructer
	Hourglass();
	~Hourglass();

	// delete Function
	Hourglass(const Hourglass& _Other) = delete;
	Hourglass(Hourglass&& _Other) noexcept = delete;
	Hourglass& operator=(const Hourglass& _Other) = delete;
	Hourglass& operator=(Hourglass&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;

private:

};

