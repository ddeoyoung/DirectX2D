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
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\MrWheezy\\AttackObject");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::Frontground);
	MainRenderer->CreateAnimation("Cigar_CiggyDemon", "Cigar_CiggyDemon", 0.05f);
	MainRenderer->ChangeAnimation("Cigar_CiggyDemon");
	MainRenderer->AutoSpriteSizeOn();


	SetRandomPos();


	// Create Collision
	AttackCollision = CreateComponent<GameEngineCollision>(CollisionOrder::BossAttack);
	std::shared_ptr<GameEngineSprite> Texture = GameEngineSprite::Find("Cigar_CiggyDemon");
	float4 Scale = Texture->GetSpriteData(0).GetScale();
	Scale -= { 100.0f, 40.0f };
	AttackCollision->SetCollisionType(ColType::AABBBOX2D);
	AttackCollision->Transform.SetLocalScale(Scale);
}

void Attack_CiggyDemon::Update(float _Delta)
{
	ContentActor::Update(_Delta);
	MoveUpdate(_Delta);
}

void Attack_CiggyDemon::SetRandomPos()
{
	GameEngineRandom NewRandom;
	float Random = NewRandom.RandomFloat(450.0f, 750.0f);
	NewRandom.SetSeed((int)Random);

	Transform.SetLocalPosition({ Random, -650.0f });
}

void Attack_CiggyDemon::MoveUpdate(float _Delta)
{
	float4 MovePos = float4::UP * 200.0f * _Delta;
	//float4 FxMovePos = float4::DOWN * 20.0f * _Delta;
	Transform.AddLocalPosition(MovePos);
	//FxRenderer->Transform.AddLocalPosition(FxMovePos);

	LiveTime -= _Delta;
	if (LiveTime < 0.0f)
	{
		Death();
	}
}