#pragma once

// Ό³Έν :
class TitleCard_Fader : public ContentActor
{
public:
	// constrcuter destructer
	TitleCard_Fader();
	~TitleCard_Fader();

	// delete Function
	TitleCard_Fader(const TitleCard_Fader& _Other) = delete;
	TitleCard_Fader(TitleCard_Fader&& _Other) noexcept = delete;
	TitleCard_Fader& operator=(const TitleCard_Fader& _Other) = delete;
	TitleCard_Fader& operator=(TitleCard_Fader&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;

};

