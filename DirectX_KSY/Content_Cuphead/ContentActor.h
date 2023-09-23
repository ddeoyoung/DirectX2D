#pragma once
#include <GameEngineCore\GameEngineActor.h>

// Ό³Έν :
class ContentActor : public GameEngineActor
{
public:
	// constrcuter destructer
	ContentActor();
	~ContentActor();

	// delete Function
	ContentActor(const ContentActor& _Other) = delete;
	ContentActor(ContentActor&& _Other) noexcept = delete;
	ContentActor& operator=(const ContentActor& _Other) = delete;
	ContentActor& operator=(ContentActor&& _Other) noexcept = delete;

	void SpriteInit(const std::string_view& Texture,  const float4 Position, float ScaleRatio = 1.0f, int Order = 0);

protected:

private:
	std::shared_ptr<GameEngineSpriteRenderer> StaticRenderer = nullptr;

};

