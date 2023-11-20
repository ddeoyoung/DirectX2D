#include "PreCompile.h"
#include "Peashot.h"
#include "BaseCharacter.h"

Peashot::Peashot()
{
}

Peashot::~Peashot()
{
}

void Peashot::Start()
{
	BaseWeapon::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Peashot_Spark"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Weapon\\Peashot");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	MainRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::PlayerShoot);

	MainRenderer->CreateAnimation("Peashot_Spark", "Peashot_Spark", 0.04f, -1, -1, false);
	MainRenderer->CreateAnimation("Peashot_Attack", "Peashot_Attack", 0.05f);
	MainRenderer->CreateAnimation("Peashot_Death", "Peashot_Death", 0.05f, -1, -1, false);
	MainRenderer->CreateAnimation("Peashot_EX", "Peashot_EX");
	MainRenderer->CreateAnimation("Peashot_EX_Death", "Peashot_EX_Death", 0.05f, -1, -1, false);
	MainRenderer->AutoSpriteSizeOn();

	// Create Collision
	AttackCollision = CreateComponent<GameEngineCollision>(CollisionOrder::PlayerAttack);
	AttackCollision->SetCollisionType(ColType::AABBBOX2D);
	AttackCollision->Transform.SetLocalScale({ 60, 20 });

	ChangeState(AttackState::Spark);
}

void Peashot::Update(float _Delta)
{
	BaseWeapon::Update(_Delta);
}

void Peashot::ChangeAnimationState(const std::string& _StateName)
{
	std::string AnimationName = "Peashot_";
	AnimationName += _StateName;

	CurState = _StateName;
	MainRenderer->ChangeAnimation(AnimationName);
}