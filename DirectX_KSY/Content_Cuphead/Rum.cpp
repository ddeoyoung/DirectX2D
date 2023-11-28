#include "PreCompile.h"
#include "Rum.h"
#include "Attack_Spew.h"
#include "BossExplosion.h"

Rum::Rum()
{
}

Rum::~Rum()
{
}


void Rum::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Rum_Idle"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\TipsyTroop\\Boss\\Rum");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();
	MainRenderer->CreateAnimation("Rum_Idle", "Rum_Idle", 0.06f);
	MainRenderer->CreateAnimation("Rum_Attack", "Rum_Attack", 0.06f);
	MainRenderer->CreateAnimation("Rum_Death", "Rum_Death", 0.05f);
	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetPivotType(PivotType::RightBottom);
	Transform.SetLocalPosition({ 1100 , -700 });

	// Create Collision
	BossCollision = CreateComponent<GameEngineCollision>(CollisionOrder::Boss);
	std::shared_ptr<GameEngineSprite> Texture = GameEngineSprite::Find("Rum_Idle");
	float4 Scale = Texture->GetSpriteData(0).GetScale();
	Scale -= { 100, 80 };
	BossCollision->SetCollisionType(ColType::AABBBOX2D);
	BossCollision->Transform.SetLocalScale(Scale);
	BossCollision->Transform.SetLocalPosition({ -120, Scale.hY() + 20.0f });


	ChangeState(RumState::Idle);
	HP = 20;
}

void Rum::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	StateUpdate(_Delta);
	DeathCheck();
}

void Rum::ChangeState(RumState _State)
{
	if (_State != State)
	{
		switch (_State)
		{
		case RumState::None:
			break;
		case RumState::Idle:
			IdleStart();
			break;
		case RumState::Attack:
			AttackStart();
			break;
		case RumState::Death:
			DeathStart();
			break;
		default:
			break;
		}
	}

	State = _State;
}

void Rum::StateUpdate(float _Delta)
{
	switch (State)
	{
	case RumState::None:
		break;
	case RumState::Idle:
		return IdleUpdate(_Delta);
	case RumState::Attack:
		return AttackUpdate(_Delta);
	case RumState::Death:
		return DeathUpdate(_Delta);
	default:
		break;
	}
}

void Rum::ChangeAnimationState(const std::string& _StateName)
{
	std::string AnimationName = "Rum_";
	AnimationName += _StateName;

	CurState = _StateName;
	MainRenderer->ChangeAnimation(AnimationName);
}

void Rum::IdleStart()
{
	ChangeAnimationState("Idle");
	IdleTimer = 7.0f;
}

void Rum::IdleUpdate(float _Delta)
{
	IdleTimer -= _Delta;
	if (IdleTimer < 0.0f)
	{
		Transform.AddLocalPosition({ 100.0f, 0.0f });
		ChangeState(RumState::Attack);
		return;
	}
}

void Rum::AttackStart()
{
	ChangeAnimationState("Attack");
	AttackTimer = 1.0f;
}

void Rum::AttackUpdate(float _Delta)
{
	AttackTimer -= _Delta;
	if (AttackTimer < 0.0f)
	{
		CreateSpew();
		AttackTimer = 1.0f;
	}

	if (true == MainRenderer->IsCurAnimationEnd())
	{
		Transform.AddLocalPosition({ -100.0f, 0.0f });
		ChangeState(RumState::Idle);
		return;
	}

}

void Rum::DeathStart()
{
	ChangeAnimationState("Death");
}

void Rum::DeathUpdate(float _Delta)
{

}

void Rum::CreateSpew()
{
	std::shared_ptr<Attack_Spew> Spew = GetLevel()->CreateActor<Attack_Spew>();
	float4 Pos = { 620, -680 };
	Spew->Transform.SetLocalPosition(Pos);
}

void Rum::DeathCheck()
{
	if (false == IsDeath)
	{
		return;
	}

	BossCollision->Off();
	ChangeState(RumState::Death);
}

void Rum::CreateDeathEffect()
{
	std::shared_ptr<BossExplosion> DeathEffect = GetLevel()->CreateActor<BossExplosion>();
	float4 BossPos = Transform.GetLocalPosition();
	BossPos += { 30.0f, 150.0f };
	DeathEffect->SetPos(BossPos);
}