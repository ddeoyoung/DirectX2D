#include "PreCompile.h"
#include "ChipsBettiganLevel.h"

#include "ContentBackground.h"
#include "ContentActor.h"
#include "BaseCharacter.h"
#include "Cuphead.h"
#include "ChipsBettigan.h"

#include "CigSmoke.h"
#include "TopSmoke.h"

ChipsBettiganLevel::ChipsBettiganLevel()
{
}

ChipsBettiganLevel::~ChipsBettiganLevel()
{
}

void ChipsBettiganLevel::Start()
{
	ContentLevel::Start();
}

void ChipsBettiganLevel::Update(float _Delta)
{
	ContentLevel::Update(_Delta);
}

void ChipsBettiganLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	ContentLevel::LevelStart(_PrevLevel);

	// Background
	if (nullptr == GameEngineSprite::Find("poker_bg_far.png"))
	{
		// Far Background
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\ChipsBettigan\\StageObject");

		GameEngineTexture::Load(Dir.GetStringPath() + "\\poker_bg_far.png");
		GameEngineSprite::CreateSingle("poker_bg_far.png");

		// Main Background (Table)
		GameEngineTexture::Load(Dir.GetStringPath() + "\\poker_bg_main.png");
		GameEngineSprite::CreateSingle("poker_bg_main.png");

		// Pixel Background
		GameEngineTexture::Load(Dir.GetStringPath() + "\\poker_bg_main_pixel.png");
		GameEngineSprite::CreateSingle("poker_bg_main_pixel.png");
	}

	// Frontground
	if (nullptr == GameEngineSprite::Find("poker_fg_chips.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\ChipsBettigan\\StageObject");

		// Chips
		GameEngineTexture::Load(Dir.GetStringPath() + "\\poker_fg_chips.png");
		GameEngineSprite::CreateSingle("poker_fg_chips.png");

		// Hand
		GameEngineTexture::Load(Dir.GetStringPath() + "\\poker_fg_hands.png");
		GameEngineSprite::CreateSingle("poker_fg_hands.png");

		// Arm
		GameEngineTexture::Load(Dir.GetStringPath() + "\\poker_fg_arm.png");
		GameEngineSprite::CreateSingle("poker_fg_arm.png");
	}

	// Background
	CurLevelBackground = CreateActor<ContentBackground>();
	CurLevelBackground->BackgroundInit("poker_bg_far.png", { -80, 40 });

	// Main Background
	CurLevelBackground = CreateActor<ContentBackground>();
	CurLevelBackground->BackgroundInit("poker_bg_main.png", { -80, 40 });

	// Pixel Background
	CurLevelPixelBackground = CreateActor<ContentBackground>();
	CurLevelPixelBackground->PixelBackgroundInit("poker_bg_main_pixel.png");

	// Player
	Player = CreateActor<Cuphead>(RenderOrder::Play);
	Player->Transform.SetLocalPosition({ 250, -550 });

	// Boss
	Boss = CreateActor<ChipsBettigan>();

	// Frontground
	std::shared_ptr<ContentActor> Chip = CreateActor<ContentActor>();
	Chip->SpriteInit("poker_fg_chips.png", { 300, -700 });

	std::shared_ptr<ContentActor> Hand = CreateActor<ContentActor>();
	Hand->SpriteInit("poker_fg_hands.png", { 50, -700 });

	std::shared_ptr<ContentActor> Arm = CreateActor<ContentActor>();
	Arm->SpriteInit("poker_fg_arm.png", { 1100, -520 });

	// Smoke
	std::shared_ptr<CigSmoke> CiggaretteSmoke = CreateActor<CigSmoke>();
	std::shared_ptr<TopSmoke> BackgroundSmoke = CreateActor<TopSmoke>();
}

void ChipsBettiganLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
}