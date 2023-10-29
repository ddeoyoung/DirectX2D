#include "PreCompile.h"
#include "Attack_CiggyDemon.h"

Attack_CiggyDemon::Attack_CiggyDemon()
{
}

Attack_CiggyDemon::~Attack_CiggyDemon()
{
}


void Attack_CiggyDemon::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Cigar_CiggyDemon"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\MrWheezy\\AttackObejct");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();
	MainRenderer->CreateAnimation("Cigar_CiggyDemon", "Cigar_CiggyDemon", -1, -1, false);
	MainRenderer->ChangeAnimation("Cigar_CiggyDemon");
	MainRenderer->AutoSpriteSizeOn();


	SetRandomPos();


	FxRenderer = CreateComponent<GameEngineSpriteRenderer>();
	FxRenderer->CreateAnimation("CiggyDemonFx", "CiggyDemonFx", -1, -1, false);
	FxRenderer->ChangeAnimation("CiggyDemonFx");
	FxRenderer->AutoSpriteSizeOn();
	FxRenderer->Off();

	// Create Collision
	AttackCollision = CreateComponent<GameEngineCollision>(CollisionOrder::BossAttack);
	std::shared_ptr<GameEngineSprite> Texture = GameEngineSprite::Find("Cigar_CiggyDemon");
	float4 Scale = Texture->GetSpriteData(0).GetScale();
	Scale -= { 60.0f, 40.0f };
	AttackCollision->SetCollisionType(ColType::AABBBOX2D);
	AttackCollision->Transform.SetLocalScale(Scale);
}

void Attack_CiggyDemon::Update(float _Delta)
{
	ContentActor::Update(_Delta);
}

void Attack_CiggyDemon::SetRandomPos()
{
	GameEngineRandom NewRandom;
	float Random = NewRandom.RandomFloat(450.0f, 750.0f);
	NewRandom.SetSeed(Random);

	Transform.SetLocalPosition(Random);
}