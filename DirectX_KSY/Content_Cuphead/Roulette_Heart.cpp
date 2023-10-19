#include "PreCompile.h"
#include "Roulette_Heart.h"

Roulette_Heart::Roulette_Heart()
{
}

Roulette_Heart::~Roulette_Heart()
{
}

void Roulette_Heart::Start()
{
	ContentActor::Start();

	// KingDice Roulette Heart
	if (nullptr == GameEngineSprite::Find("kd_gb_heart_01.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\KingDice\\StageObject\\Heart");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_heart_01.png");
		GameEngineSprite::CreateSingle("kd_gb_heart_01.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_heart_02.png");
		GameEngineSprite::CreateSingle("kd_gb_heart_02.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_heart_03.png");
		GameEngineSprite::CreateSingle("kd_gb_heart_03.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_heart_04.png");
		GameEngineSprite::CreateSingle("kd_gb_heart_04.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_heart_05.png");
		GameEngineSprite::CreateSingle("kd_gb_heart_05.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_heart_06.png");
		GameEngineSprite::CreateSingle("kd_gb_heart_06.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_heart_07.png");
		GameEngineSprite::CreateSingle("kd_gb_heart_07.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_heart_08.png");
		GameEngineSprite::CreateSingle("kd_gb_heart_08.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_heart_09.png");
		GameEngineSprite::CreateSingle("kd_gb_heart_09.png");
	}

	MainRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::FrontgroundObject);
	MainRenderer->SetSprite("kd_gb_heart_01.png");
}

void Roulette_Heart::Update(float _Delta)
{
	ContentActor::Update(_Delta);
}