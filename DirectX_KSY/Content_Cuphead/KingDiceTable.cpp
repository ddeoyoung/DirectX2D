#include "PreCompile.h"
#include "KingDiceTable.h"

KingDiceTable::KingDiceTable()
{
}

KingDiceTable::~KingDiceTable()
{
}

void KingDiceTable::Start()
{
	if (nullptr == GameEngineSprite::Find("kd_bg_table.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\KingDice\\StageObject\\Table\\kd_bg_table.png");

		GameEngineTexture::Load(Dir.GetStringPath());
		GameEngineSprite::CreateSingle("kd_bg_table.png");
	}

	std::shared_ptr<GameEngineTexture> Texture = GameEngineTexture::Find("kd_bg_table.png");

	float4 Pos = Texture->GetScale().Half();
	Pos.Y *= -1.0f;
	Pos.Y -= 241.0f;

	Renderer = CreateComponent<GameEngineSpriteRenderer>();
	Renderer->SetSprite("kd_bg_table.png");
	Renderer->Transform.SetLocalPosition(Pos);
}