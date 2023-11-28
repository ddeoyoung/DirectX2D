#include "PreCompile.h"
#include "BossExplosion.h"
#include "BaseMonster.h"

BossExplosion::BossExplosion()
{
}

BossExplosion::~BossExplosion()
{
}


void BossExplosion::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("BossExplosion"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Effect");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	MainRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::FrontgroundEffect);
	MainRenderer->CreateAnimation("BossExplosion", "BossExplosion", 0.05f);
	MainRenderer->ChangeAnimation("BossExplosion");
	MainRenderer->AutoSpriteSizeOn();
}

void BossExplosion::Update(float _Delta)
{
	ContentActor::Update(_Delta);
	SetRandom();
}

void BossExplosion::SetPos(float4 _Pos)
{
	BossPos = _Pos;
}

void BossExplosion::SetRandom()
{
	if (BossPos != float4::ZERO)
	{
		GameEngineRandom NewRandom;
		float RandomX = NewRandom.RandomFloat(-200, 200);
		float RandomY = NewRandom.RandomFloat(-200, 200);
		float4 EffectPos = BossPos;

		NewRandom.SetSeed((int)RandomX);
		NewRandom.SetSeed((int)RandomY);

		EffectPos.X += RandomX;
		EffectPos.Y += RandomY;

		Transform.SetLocalPosition({ EffectPos.X, EffectPos.Y });
	}
}