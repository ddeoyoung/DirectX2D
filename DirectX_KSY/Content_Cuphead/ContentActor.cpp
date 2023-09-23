#include "PreCompile.h"
#include "ContentActor.h"

ContentActor::ContentActor()
{
}

ContentActor::~ContentActor()
{
}

void ContentActor::SpriteInit(const std::string_view& Texture,  const float4 Position, int Order, float ScaleRatio)
{
	if (nullptr == StaticRenderer)
	{
		StaticRenderer = CreateComponent<GameEngineSpriteRenderer>(Order);
	}
	StaticRenderer->SetSprite(Texture);
	StaticRenderer->SetAutoScaleRatio(ScaleRatio);

	Transform.SetLocalPosition(Position);
}

void ContentActor::AnimationInit()
{
	if (nullptr == StaticRenderer)
	{
		StaticRenderer = CreateComponent<GameEngineSpriteRenderer>();
	}
}