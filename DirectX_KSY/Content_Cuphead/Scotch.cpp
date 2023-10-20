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
	ContentActor::Start();

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
	Scale -= { 60.0f, 200.0f };

	BossCollision->SetCollisionType(ColType::AABBBOX2D);
	BossCollision->Transform.SetLocalScale(Scale);
	BossCollision->Transform.SetLocalPosition({ 0, Scale.hY() + 80.0f });
}

void Scotch::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	StateUpdate(_Delta);
}

void Scotch::ChangeState(ScotchState _State)
{
	if (State != _State)
	{
		switch (State)
		{
		case ScotchState::None:
			break;
		case ScotchState::Idle:
			break;
		case ScotchState::Attack:
			break;
		case ScotchState::Death:
			break;
		default:
			break;
		}
	}

	State = _State;
}

void Scotch::StateUpdate(float _Delta)
{
	switch (State)
	{
	case ScotchState::None:
		break;
	case ScotchState::Idle:
		return IdleUpdate(_Delta);
	case ScotchState::Attack:
		return AttackUpdate(_Delta);
	case ScotchState::Death:
		return DeathUpdate(_Delta);
	default:
		break;
	}
}

void Scotch::ChangeAnimationState(const std::string& _StateName)
{
	std::string AnimationName = "Scotch_";
	AnimationName += _StateName;

	CurState = _StateName;
	MainRenderer->ChangeAnimation(AnimationName);
}

void Scotch::IdleStart()
{
	ChangeAnimationState("Idle");
}

void Scotch::IdleUpdate(float _Delta)
{

}

void Scotch::AttackStart()
{
	ChangeAnimationState("Attack");
}

void Scotch::AttackUpdate(float _Delta)
{

}

void Scotch::DeathStart()
{
	ChangeAnimationState("Death");
}

void Scotch::DeathUpdate(float _Delta)
{

}