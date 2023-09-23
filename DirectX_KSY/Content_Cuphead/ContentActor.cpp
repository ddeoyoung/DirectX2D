#include "PreCompile.h"
#include "ContentActor.h"

ContentActor::ContentActor()
{
}

ContentActor::~ContentActor()
{
}

void ContentActor::SpriteInit(const std::string_view& Texture,  const float4 Position, float ScaleRatio, int Order)
{
	if (nullptr == StaticRenderer)
	{
		StaticRenderer = CreateComponent<GameEngineSpriteRenderer>(Order);
	}
	StaticRenderer->SetSprite(Texture);
	StaticRenderer->SetAutoScaleRatio(ScaleRatio);

	Transform.SetLocalPosition(Position);
}
