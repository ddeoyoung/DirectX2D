#include "PreCompile.h"
#include "TitleBackground.h"

TitleBackground::TitleBackground()
{
}

TitleBackground::~TitleBackground()
{
}

void TitleBackground::Start()
{
	if (nullptr == GameEngineSprite::Find("title_screen_background.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Title\\Background\\title_screen_background.png");

		GameEngineTexture::Load(Dir.GetStringPath());
		GameEngineSprite::CreateSingle("title_screen_background.png");

		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Title\\Background\\PressAnyButton.png");

		GameEngineTexture::Load(Dir.GetStringPath());
		GameEngineSprite::CreateSingle("PressAnyButton.png");
	}

	Renderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::Background);
	Renderer->SetSprite("title_screen_background.png");

	PressKeyRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::BackgroundObject);
	PressKeyRenderer->SetSprite("PressAnyButton.png");
	PressKeyRenderer->Transform.AddLocalPosition({ 0.0f, -200.0f });
}

void TitleBackground::Update(float _Delta)
{
	PressKeyTime += _Delta;

	if (1.0f <= PressKeyTime)
	{
		PressKeyRenderer->Off();
	}

	if (2.0f <= PressKeyTime)
	{
		PressKeyRenderer->On();
		PressKeyTime = 0.0f;
	}
}