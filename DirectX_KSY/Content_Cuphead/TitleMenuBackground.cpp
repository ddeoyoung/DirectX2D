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
	ContentActor::Start();

	if (nullptr == GameEngineSprite::Find("cuphead_secondary_title_screen.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Title\\Menu");

		GameEngineTexture::Load(Dir.GetStringPath() + "\\cuphead_secondary_title_screen.png");
		GameEngineSprite::CreateSingle("cuphead_secondary_title_screen.png");
	}

	Renderer = CreateComponent<GameEngineSpriteRenderer>();
	Renderer->SetSprite("cuphead_secondary_title_screen.png");

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Renderer->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });
}

void TitleMenuBackground::Update(float _Delta)
{
	ContentActor::Update(_Delta);
}