#include "PreCompile.h"
#include "KD_Chips.h"

KD_Chips::KD_Chips()
{
}

KD_Chips::~KD_Chips()
{
}

void KD_Chips::Start()
{
	ContentActor::Start();

	// KingDice Frontground Chips
	if (nullptr == GameEngineSprite::Find("kd_fg_chips_right.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\KingDice\\StageObject\\Frontground\\kd_fg_chips_right.png");

		// Right
		GameEngineTexture::Load(Dir.GetStringPath());
		GameEngineSprite::CreateSingle("kd_fg_chips_right.png");

		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\KingDice\\StageObject\\Frontground\\kd_fg_chips_left.png");

		// Left
		GameEngineTexture::Load(Dir.GetStringPath());
		GameEngineSprite::CreateSingle("kd_fg_chips_left.png");
	}

	Renderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::FrontgroundObject);
	Renderer->SetSprite("kd_fg_chips_right.png");
	Renderer->Transform.SetLocalPosition( { 1200 , -690 } );

	Renderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::FrontgroundObject);
	Renderer->SetSprite("kd_fg_chips_left.png");
	Renderer->Transform.SetLocalPosition({ 80 , -700 });

}

void KD_Chips::Update(float _Delta)
{
	ContentActor::Update(_Delta);
}