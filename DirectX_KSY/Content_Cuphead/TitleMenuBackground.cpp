#include "PreCompile.h"
#include "TitleMenuBackground.h"

TitleMenuBackground::TitleMenuBackground()
{
}

TitleMenuBackground::~TitleMenuBackground()
{
}

void TitleMenuBackground::Start()
{
	if (nullptr == GameEngineSprite::Find("cuphead_secondary_title_screen.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Title\\Menu\\cuphead_secondary_title_screen.png");

		GameEngineTexture::Load(Dir.GetStringPath());
		GameEngineSprite::CreateSingle("cuphead_secondary_title_screen.png");
	}

	Renderer = CreateComponent<GameEngineSpriteRenderer>();
	Renderer->SetSprite("cuphead_secondary_title_screen.png");
}

void TitleMenuBackground::Update(float _Delta)
{

}