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
	if (nullptr == GameEngineSprite::Find("TitleBackground"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Title\\Background\\title_screen_background.png");

		GameEngineTexture::Load(Dir.GetStringPath());
		GameEngineSprite::CreateSingle("title_screen_background.png");
	}

	Renderer = CreateComponent<GameEngineSpriteRenderer>();
	Renderer->SetSprite("title_screen_background.png");
}

void TitleBackground::Update(float _Delta)
{

}