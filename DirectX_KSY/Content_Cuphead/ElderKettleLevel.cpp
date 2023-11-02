#include "PreCompile.h"
#include "ElderKettleLevel.h"

#include "ContentBackground.h"
#include "BaseCharacter.h"
#include "Cuphead.h"

#include "ElderKettle.h"

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
	}
}

void ElderKettleLevel::Update(float _Delta)
{
	ContentLevel::Update(_Delta);
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
	

	
}

void ElderKettleLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
}
