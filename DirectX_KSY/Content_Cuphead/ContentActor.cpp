#include "PreCompile.h"
#include "ContentActor.h"

ContentActor::ContentActor()
{
}

ContentActor::~ContentActor()
{
}

void ContentActor::Start()
{
	GameEngineInput::AddInputObject(this);
}

void ContentActor::Update(float _Delta)
{

}

void ContentActor::SpriteInit(const std::string_view& _Texture,  const float4 _Position, int _Order, float _ScaleRatio)
{
	if (nullptr == StaticRenderer)
	{
		StaticRenderer = CreateComponent<GameEngineSpriteRenderer>(_Order);
	}
	StaticRenderer->SetSprite(_Texture);
	StaticRenderer->SetAutoScaleRatio(_ScaleRatio);

	Transform.SetLocalPosition(_Position);
}

void ContentActor::AnimationInit()
{
	if (nullptr == StaticRenderer)
	{
		StaticRenderer = CreateComponent<GameEngineSpriteRenderer>();
	}
}