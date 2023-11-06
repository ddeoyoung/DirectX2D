#include "PreCompile.h"
#include "ContentBackground.h"

ContentBackground::ContentBackground()
{
}

ContentBackground::~ContentBackground()
{
}

void ContentBackground::Start()
{
	ContentActor::Start();
}

void ContentBackground::Update(float _Delta)
{
	ContentActor::Update(_Delta);
}

void ContentBackground::BackgroundInit(std::string_view _SpriteName)
{
	Background = _SpriteName;

	if (nullptr == GameEngineSprite::Find(Background))
	{
		MsgBoxAssert(Background + "의 배경이 로드되지 않았습니다.");
		return;
	}

	Renderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::Background);
	Renderer->SetSprite(Background);
	Texture = GameEngineTexture::Find(Background);

	float4 Scale = Texture->GetScale().Half();
	Scale.Y *= -1.0f;

	Renderer->Transform.SetLocalPosition(Scale);
}

void ContentBackground::BackgroundInit(std::string_view _SpriteName, float4 _Pos)
{
	Background = _SpriteName;

	if (nullptr == GameEngineSprite::Find(Background))
	{
		MsgBoxAssert(Background + "의 배경이 로드되지 않았습니다.");
		return;
	}

	Renderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::Background);
	Renderer->SetSprite(Background);
	Texture = GameEngineTexture::Find(Background);

	float4 Scale = Texture->GetScale().Half();
	Scale.Y *= -1.0f;
	Scale += _Pos;

	Renderer->Transform.SetLocalPosition(Scale);
}

void ContentBackground::PixelBackgroundInit(std::string_view _SpriteName)
{
	PixelBackground = _SpriteName;

	if (nullptr == GameEngineSprite::Find(PixelBackground))
	{
		MsgBoxAssert(PixelBackground + "의 픽셀배경이 로드되지 않았습니다.");
		return;
	}

	Renderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::Background);
	Renderer->SetSprite(PixelBackground);

	PixelTexture = GameEngineTexture::Find(PixelBackground);
	float4 Scale = PixelTexture->GetScale().Half();
	Scale.Y *= -1.0f;
	Renderer->Transform.SetLocalPosition(Scale);

	Renderer->Off();
}

void ContentBackground::UpperBackgroundInit(std::string_view _SpriteName)
{
	UpperBackground = _SpriteName;

	if (nullptr == GameEngineSprite::Find(UpperBackground))
	{
		MsgBoxAssert(UpperBackground + "의 Upper배경이 로드되지 않았습니다.");
		return;
	}

	Renderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::FrontgroundObject3);
	Renderer->SetSprite(UpperBackground);

	UpperTexture = GameEngineTexture::Find(UpperBackground);

	float4 Scale = UpperTexture->GetScale().Half();
	Scale.Y *= -1.0f;

	Renderer->Transform.SetLocalPosition(Scale);
}

GameEngineColor ContentBackground::GetColor(float4 _Pos, GameEngineColor _DefaultColor)
{
	_Pos.Y *= -1.0f;
	PixelTexture = GameEngineTexture::Find(PixelBackground);

	return PixelTexture->GetColor(_Pos, _DefaultColor);
}