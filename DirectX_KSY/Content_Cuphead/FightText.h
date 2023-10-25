#pragma once

// Ό³Έν :
class FightText : public ContentActor
{
public:
	// constrcuter destructer
	FightText();
	~FightText();

	// delete Function
	FightText(const FightText& _Other) = delete;
	FightText(FightText&& _Other) noexcept = delete;
	FightText& operator=(const FightText& _Other) = delete;
	FightText& operator=(FightText&& _Other) noexcept = delete;

	void SetFightText(const std::string& _Name);

protected:
	void Start() override;
	void Update(float _Delta) override;

	void EndCheck();

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
private:
	bool IsReady = false;
	float ReadyTimer = 0.0f;
	std::string TextName = "";
};

