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

}

void ContentBackground::Update(float _Delta)
{

}

void ContentBackground::BackgroundInit(std::string_view _SpriteName)
{
	Background = _SpriteName;

	if (nullptr == GameEngineSprite::Find(Background))
	{
		MsgBoxAssert(Background + "�� ����� �ε���� �ʾҽ��ϴ�.");
		return;
	}

	Renderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::Background);
	Renderer->SetSprite(Background);
	Texture = GameEngineTexture::Find(Background);

	float4 Scale = Texture->GetScale().Half();
	Scale.Y *= -1.0f;

	Renderer->Transform.SetLocalPosition(Scale);
}

GameEngineColor ContentBackground::GetColor(float4 _Pos, GameEngineColor _DefaultColor)
{
	_Pos.Y *= -1.0f;
	Texture = GameEngineTexture::Find(Background);

	return Texture->GetColor(_Pos, _DefaultColor);
}