#include "PreCompile.h"
#include "ChipsBettiganLevel.h"

#include "ContentBackground.h"
#include "BaseCharacter.h"
#include "Cuphead.h"
#include "ChipsBettigan.h"

#include "ContentActor.h"

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
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\ChipsBettigan\\StageObject\\poker_bg_far.png");

		GameEngineTexture::Load(Dir.GetStringPath());
		GameEngineSprite::CreateSingle("poker_bg_far.png");

		// Main Background (Table)
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\ChipsBettigan\\StageObject\\poker_bg_main.png");

		GameEngineTexture::Load(Dir.GetStringPath());
		GameEngineSprite::CreateSingle("poker_bg_main.png");
	}

	// Frontground
	if (nullptr == GameEngineSprite::Find("poker_fg_chips.png"))
	{
		// Left Chips
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\ChipsBettigan\\StageObject\\poker_fg_chips.png");

		GameEngineTexture::Load(Dir.GetStringPath());
		GameEngineSprite::CreateSingle("poker_fg_chips.png");
	}

	// Background
	CurLevelBackground = CreateActor<ContentBackground>();
	//CurLevelBackground->BackgroundInit("poker_bg_far.png");
	//CurLevelBackground->Transform.SetLocalPosition({ -80, 40 });
	CurLevelBackground->BackgroundInit("poker_bg_far.png", { -80, 40 });

	// Main Background
	CurLevelBackground = CreateActor<ContentBackground>();
	CurLevelBackground->BackgroundInit("poker_bg_main.png");
	CurLevelBackground->Transform.SetLocalPosition({ -80, 40 });

	// Frontground
	std::shared_ptr<ContentActor> Chip = CreateActor<ContentActor>();
	Chip->SpriteInit("poker_fg_chips.png", { 300, -700 });
}

void ChipsBettiganLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
}