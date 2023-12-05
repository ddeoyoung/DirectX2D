#include "PreCompile.h"
#include "TitleCard_Fader.h"

TitleCard_Fader::TitleCard_Fader()
{
}

TitleCard_Fader::~TitleCard_Fader()
{
}

void TitleCard_Fader::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("title_card_fader.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\UI\\TitleCard");

		GameEngineTexture::Load(Dir.GetStringPath() + "\\title_card_fader.png");
		GameEngineSprite::CreateSingle("title_card_fader.png");
	}

	MainRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::UI);
	MainRenderer->SetSprite("title_card_fader.png");
	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->Transform.SetLocalPosition({ 640, -360 });
}

void TitleCard_Fader::Update(float _Delta)
{
	ContentActor::Update(_Delta);
}