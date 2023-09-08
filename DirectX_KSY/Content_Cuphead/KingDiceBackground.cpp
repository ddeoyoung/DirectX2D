#include "PreCompile.h"
#include "KingDiceBackground.h"

KingDiceBackground::KingDiceBackground()
{
}

KingDiceBackground::~KingDiceBackground()
{
}

void KingDiceBackground::Start()
{
	if (nullptr == GameEngineSprite::Find("kd_bg_painting.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\KingDice\\StageObject\\Background\\kd_bg_painting.png");

		GameEngineTexture::Load(Dir.GetStringPath());
		GameEngineSprite::CreateSingle("kd_bg_painting.png");
	}

	Renderer = CreateComponent<GameEngineSpriteRenderer>();
	Renderer->SetSprite("kd_bg_painting.png");

	std::shared_ptr<GameEngineTexture> Texture = GameEngineTexture::Find("kd_bg_painting.png");

	float4 Scale = Texture->GetScale().Half();
	Scale.Y *= -1.0f;

	Renderer->Transform.SetLocalPosition(Scale);
}