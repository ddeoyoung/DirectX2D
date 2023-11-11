#pragma once

enum class EXState
{
	None,
	Charge,
	Idle,
	Filp,
};

// Ό³Έν :
class EXCard : public ContentActor
{
public:
	// constrcuter destructer
	EXCard();
	~EXCard();

	// delete Function
	EXCard(const EXCard& _Other) = delete;
	EXCard(EXCard&& _Other) noexcept = delete;
	EXCard& operator=(const EXCard& _Other) = delete;
	EXCard& operator=(EXCard&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
private:

};

