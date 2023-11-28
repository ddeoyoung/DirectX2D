#include "PreCompile.h"
#include "Scotch.h"
#include "Attack_Liquid.h"
#include "ContentLevel.h"
#include "BossExplosion.h"

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

	ChangeState(ScotchState::Idle);
	HP = 20;
}

void Scotch::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	StateUpdate(_Delta);
	DeathCheck();
}

void Scotch::ChangeState(ScotchState _State)
{
	if (_State != State)
	{
		switch (_State)
		{
		case ScotchState::None:
			break;
		case ScotchState::Idle:
			IdleStart();
			break;
		case ScotchState::Attack:
			AttackStart();
			break;
		case ScotchState::Death:
			DeathStart();
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
	IdleTimer = 9.0f;
}

void Scotch::IdleUpdate(float _Delta)
{
	IdleTimer -= _Delta;
	if (IdleTimer < 0.0f)
	{
		ChangeState(ScotchState::Attack);
		return;
	}
}

void Scotch::AttackStart()
{
	ChangeAnimationState("Attack");
	AttackTimer = 1.5f;
}

void Scotch::AttackUpdate(float _Delta)
{
	AttackTimer -= _Delta;
	if (AttackTimer < 0.0f)
	{
		CreateLiquid();
		AttackTimer = 1.5f;
	}

	if (true == MainRenderer->IsCurAnimationEnd())
	{
		ChangeState(ScotchState::Idle);
		return;
	}
}

void Scotch::DeathStart()
{
	ChangeAnimationState("Death");
}

void Scotch::DeathUpdate(float _Delta)
{

}

void Scotch::CreateLiquid()
{
	Liquid = GetLevel()->CreateActor<Attack_Liquid>();
	float4 PlayerPos = ContentLevel::CurLevel->GetCurLevelPlayer()->Transform.GetWorldPosition();
	float4 Pos = { PlayerPos.X , -300 };
	Liquid->Transform.SetLocalPosition(Pos);
}

void Scotch::DeathCheck()
{
	if (false == IsDeath)
	{
		return;
	}

	BossCollision->Off();
	ChangeState(ScotchState::Death);
}

void Scotch::CreateDeathEffect()
{
	std::shared_ptr<BossExplosion> DeathEffect = GetLevel()->CreateActor<BossExplosion>();
	float4 BossPos = Transform.GetLocalPosition();
	BossPos += { 0.0f, 400.0f };
	DeathEffect->SetPos(BossPos);
}