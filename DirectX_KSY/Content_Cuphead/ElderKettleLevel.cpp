#include "PreCompile.h"
#include "ElderKettleLevel.h"

#include "ContentBackground.h"
#include "BaseCharacter.h"
#include "Cuphead.h"

#include "ElderKettle.h"
#include "EnterMessage.h"
#include "FadeAnimation.h"

ElderKettleLevel::ElderKettleLevel()
{
}

ElderKettleLevel::~ElderKettleLevel()
{
}


void ElderKettleLevel::Start()
{
	ContentLevel::Start();

	// Sprite Load
	if (nullptr == GameEngineSprite::Find("ek_bg_main.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\ElderKettle");

		// Background
		GameEngineTexture::Load(Dir.GetStringPath() + "\\ek_bg_main.png");
		GameEngineSprite::CreateSingle("ek_bg_main.png");

		// Pixel Background
		GameEngineTexture::Load(Dir.GetStringPath() + "\\ek_bg_main_pixel.png");
		GameEngineSprite::CreateSingle("ek_bg_main_pixel.png");

		// Vignette
		GameEngineTexture::Load(Dir.GetStringPath() + "\\ek_bg_vignette.png");
		GameEngineSprite::CreateSingle("ek_bg_vignette.png");

		// Enter Message
		GameEngineTexture::Load(Dir.GetStringPath() + "\\EnterMessage.png");
		GameEngineSprite::CreateSingle("EnterMessage.png");
	}
}

void ElderKettleLevel::Update(float _Delta)
{
	ContentLevel::Update(_Delta);
	EnterBubble->InteractionCheck();
	TutorialEnterInteraction();
}

void ElderKettleLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	ContentLevel::LevelStart(_PrevLevel);


	// Background
	CurLevelBackground = CreateActor<ContentBackground>();
	CurLevelBackground->BackgroundInit("ek_bg_main.png", { -0, 50 });

	CurLevelPixelBackground = CreateActor<ContentBackground>();
	CurLevelPixelBackground->PixelBackgroundInit("ek_bg_main_pixel.png");

	// Player
	CurLevelPlayer = CreateActor<Cuphead>();
	CurLevelPlayer->Transform.SetLocalPosition({ 250, -550 });

	// Vignette
	std::shared_ptr<ContentActor> Vignette = CreateActor<ContentActor>();
	Vignette->SpriteInit("ek_bg_vignette.png", { 800, -380 }, RenderOrder::FrontgroundEffect);

	// Elder Kettle
	Kettle = CreateActor<ElderKettle>();
	
	// Enter Message
	EnterBubble = CreateActor<EnterMessage>();

	// UI - Fade Out
	Fade = CreateActor<FadeAnimation>(RenderOrder::Max);
	Fade->Transform.AddLocalPosition({ 175, 0});
	Fade->Off();
}

void ElderKettleLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
}

void ElderKettleLevel::TutorialEnterInteraction()
{
	bool Check = EnterBubble->InteractionCheck();
	if (false == IsLevelChange)
	{
		if (true == Check && true == GameEngineInput::IsDown('Z', this))
		{
			Fade->On();
			Fade->SetFade("Out");
			IsLevelChange = true;
		}
	}

	else if (true == IsLevelChange)
	{
		if (true == Fade->IsCurAnimationEnd())
		{
			GameEngineCore::ChangeLevel("TutorialLevel");
		}
	}
}