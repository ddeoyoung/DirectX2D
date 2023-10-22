#include "PreCompile.h"
#include "ContentActor.h"
#include "ParrySpark_Object.h"

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

void ContentActor::CreateParrySpark()
{
	ParryEffect = GetLevel()->CreateActor<ParrySpark_Object>();
	float4 PlayerPos = Transform.GetLocalPosition();
	float4 Pos = PlayerPos;
	ParryEffect->Transform.SetLocalPosition(Pos);
}