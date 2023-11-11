#pragma once

// Ό³Έν :
class HPCard : public ContentActor
{
public:
	// constrcuter destructer
	HPCard();
	~HPCard();

	// delete Function
	HPCard(const HPCard& _Other) = delete;
	HPCard(HPCard&& _Other) noexcept = delete;
	HPCard& operator=(const HPCard& _Other) = delete;
	HPCard& operator=(HPCard&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
private:

};

