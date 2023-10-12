#include "PreCompile.h"
#include "Scotch.h"

Scotch::Scotch()
{
}

Scotch::~Scotch()
{
}

void Scotch::Start()
{
	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Scotch_Idle"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\TipsyTroop\\Boss\\Scotch");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();

	MainRenderer->CreateAnimation("Scotch_Idle", "Scotch_Idle", 0.07f);
	MainRenderer->CreateAnimation("Scotch_Attack", "Scotch_Attack", 0.07f);
	MainRenderer->CreateAnimation("Scotch_Death", "Scotch_Death", 0.05f);
	MainRenderer->ChangeAnimation("Scotch_Idle");

	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetPivotType(PivotType::Bottom);

	Transform.SetLocalPosition({ 1150 , -700 });

	// Create Collision
	BossCollision = CreateComponent<GameEngineCollision>(CollisionOrder::Boss);

	std::shared_ptr<GameEngineSprite> Texture = GameEngineSprite::Find("Scotch_Idle");
	float4 Scale = Texture->GetSpriteData(0).GetScale();

	BossCollision->SetCollisionType(ColType::AABBBOX2D);
	BossCollision->Transform.SetLocalScale(Scale);
	BossCollision->Transform.SetLocalPosition({ 0, Scale.hY() });
	BossCollision->Off();
}

void Scotch::Update(float _Delta)
{
	StateUpdate(_Delta);
}

void Scotch::ChangeState(ScotchState _State)
{

}

void Scotch::StateUpdate(float _Delta)
{

}

void Scotch::ChangeAnimationState(const std::string& _StateName)
{

}

void Scotch::IdleStart()
{

}

void Scotch::IdleUpdate(float _Delta)
{

}

void Scotch::AttackStart()
{

}

void Scotch::AttackUpdate(float _Delta)
{

}

void Scotch::DeathStart()
{

}

void Scotch::DeathUpdate(float _Delta)
{

}