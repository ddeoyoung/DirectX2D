#include "PreCompile.h"
#include "KingDiceTable.h"

KingDiceTable* KingDiceTable::KDTable;

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
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\KingDice\\StageObject\\Table");

		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_bg_table.png");
		GameEngineSprite::CreateSingle("kd_bg_table.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_bg_table_pixel.bmp");
		GameEngineSprite::CreateSingle("kd_bg_table_pixel.bmp");
	}

	std::shared_ptr<GameEngineTexture> Texture = GameEngineTexture::Find("kd_bg_table.png");

	float4 Pos = Texture->GetScale().Half();
	Pos.Y *= -1.0f;

	Renderer = CreateComponent<GameEngineSpriteRenderer>();
	Renderer->SetSprite("kd_bg_table.png");
	Renderer->Transform.SetLocalPosition(Pos);

}

GameEngineColor KingDiceTable::GetColor(float4 _Pos, GameEngineColor _DefaultColor)
{
	_Pos.Y *= -1.0f;

	std::shared_ptr<GameEngineTexture> Texture = GameEngineTexture::Find("kd_bg_table_pixel.bmp");

	return Texture->GetColor(_Pos, _DefaultColor);
}