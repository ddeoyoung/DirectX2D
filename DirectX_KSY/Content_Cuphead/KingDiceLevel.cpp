#include "PreCompile.h"
#include "KingDiceLevel.h"

#include "ContentBackground.h"
#include "BaseCharacter.h"
#include "Cuphead.h"
#include "KingDice.h"


KingDiceLevel::KingDiceLevel()
{
}

KingDiceLevel::~KingDiceLevel()
{
}

void KingDiceLevel::Start()
{
	ContentLevel::Start();
}

void KingDiceLevel::Update(float _Delta)
{
	ContentLevel::Update(_Delta);
}

void KingDiceLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	ContentLevel::LevelStart(_PrevLevel);

	// Background
	if (nullptr == GameEngineSprite::Find("kd_bg_painting.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\KingDice\\StageObject\\Background\\kd_bg_painting.png");

		// 페인팅 배경
		GameEngineTexture::Load(Dir.GetStringPath());
		GameEngineSprite::CreateSingle("kd_bg_painting.png");

		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\KingDice\\StageObject\\Table");

		// 테이블 배경
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_bg_table.png");
		GameEngineSprite::CreateSingle("kd_bg_table.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_bg_table_pixel.bmp");
		GameEngineSprite::CreateSingle("kd_bg_table_pixel.bmp");
	}

	// Background
	CurLevelBackground = CreateActor<ContentBackground>();
	CurLevelBackground->BackgroundInit("kd_bg_painting.png");

	CurLevelPixelBackground = CreateActor<ContentBackground>();
	CurLevelPixelBackground->PixelBackgroundInit("kd_bg_table_pixel.bmp");

	// Boss
	std::shared_ptr<KingDice> Boss = CreateActor<KingDice>();

	// Frontground
	std::shared_ptr<ContentBackground> Frontground = CreateActor<ContentBackground>();
	Frontground->BackgroundInit("kd_bg_table.png");

	// Player
	std::shared_ptr<BaseCharacter> Player = CreateActor<Cuphead>();
	Player->Transform.SetLocalPosition({ 250, -550 });

}

void KingDiceLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
}