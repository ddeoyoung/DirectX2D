#pragma once
#include <GameEngineCore\GameEngineActor.h>

// Ό³Έν :
class ContentBackground : public GameEngineActor
{
public:
	// constrcuter destructer
	ContentBackground();
	~ContentBackground();

	// delete Function
	ContentBackground(const ContentBackground& _Other) = delete;
	ContentBackground(ContentBackground&& _Other) noexcept = delete;
	ContentBackground& operator=(const ContentBackground& _Other) = delete;
	ContentBackground& operator=(ContentBackground&& _Other) noexcept = delete;

	void BackgroundInit(std::string_view _SpriteName);
	void PixelBackgroundInit(std::string_view _SpriteName);

	GameEngineColor GetColor(float4 _Pos, GameEngineColor _DefaultColor);

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::string Background = "";
	std::string PixelBackground = "";
	std::shared_ptr<GameEngineSpriteRenderer> Renderer = nullptr;

	std::shared_ptr<GameEngineTexture> Texture = nullptr;
	std::shared_ptr<GameEngineTexture> PixelTexture = nullptr;
};

