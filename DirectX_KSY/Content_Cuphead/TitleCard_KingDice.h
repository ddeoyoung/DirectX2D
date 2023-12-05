#pragma once

// Ό³Έν :
class TitleCard_KingDice : public ContentActor
{
public:
	// constrcuter destructer
	TitleCard_KingDice();
	~TitleCard_KingDice();

	// delete Function
	TitleCard_KingDice(const TitleCard_KingDice& _Other) = delete;
	TitleCard_KingDice(TitleCard_KingDice&& _Other) noexcept = delete;
	TitleCard_KingDice& operator=(const TitleCard_KingDice& _Other) = delete;
	TitleCard_KingDice& operator=(TitleCard_KingDice&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;

	float CardScaleRatio = 0.0f;
};

