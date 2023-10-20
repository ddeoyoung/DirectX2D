#include "PreCompile.h"
#include "Attack_Olive.h"
#include "ContentLevel.h"

Attack_Olive::Attack_Olive()
{
}

Attack_Olive::~Attack_Olive()
{
}

void Attack_Olive::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Olive_Idle"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\TipsyTroop\\Boss\\Martini\\Martini_Attack\\Olive");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();

	MainRenderer->CreateAnimation("Olive_Appear", "Olive_Appear", false);
	MainRenderer->SetEndEvent("Olive_Appear", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Olive_Idle");
			_Renderer->GetParent<Attack_Olive>()->SetState(OliveState::Idle);
		});
	MainRenderer->CreateAnimation("Olive_Idle", "Olive_Idle");
	MainRenderer->CreateAnimation("Olive_Attack", "Olive_Attack");
	MainRenderer->CreateAnimation("Olive_Death", "Olive_Death");
	MainRenderer->AutoSpriteSizeOn();


	// Create Collision
	AttackCollision = CreateComponent<GameEngineCollision>(CollisionOrder::BossAttack);
	std::shared_ptr<GameEngineSprite> Texture = GameEngineSprite::Find("Olive_Idle");
	float4 Scale = Texture->GetSpriteData(0).GetScale();
	Scale -= { 50.0f, 30.0f };
	AttackCollision->SetCollisionType(ColType::AABBBOX2D);
	AttackCollision->Transform.SetLocalScale(Scale);



	ChangeState(OliveState::Appear);
}

void Attack_Olive::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	StateUpdate(_Delta);
}

void Attack_Olive::ChangeState(OliveState _State)
{
	if (_State != State)
	{
		switch (_State)
		{
		case OliveState::None:
			break;
		case OliveState::Appear:
			AppearStart();
			break;
		case OliveState::Idle:
			IdleStart();
			break;
		case OliveState::Move:
			MoveStart();
			break;
		case OliveState::Attack:
			AttackStart();
			break;
		case OliveState::Death:
			DeathStart();
			break;
		default:
			break;
		}
	}

	State = _State;
}

void Attack_Olive::StateUpdate(float _Delta)
{
	switch (State)
	{
	case OliveState::None:
		break;
	case OliveState::Appear:
		return AppearUpdate(_Delta);
	case OliveState::Idle:
		return IdleUpdate(_Delta);
	case OliveState::Move:
		return MoveUpdate(_Delta);
	case OliveState::Attack:
		return AttackUpdate(_Delta);
	case OliveState::Death:
		return DeathUpdate(_Delta);
	default:
		break;
	}
}

void Attack_Olive::ChangeAnimationState(const std::string& _StateName)
{
	std::string AnimationName = "Olive_";
	AnimationName += _StateName;

	CurState = _StateName;
	MainRenderer->ChangeAnimation(AnimationName);
}

void Attack_Olive::AppearStart()
{
	ChangeAnimationState("Appear");
}

void Attack_Olive::AppearUpdate(float _Delta)
{ 

}

void Attack_Olive::IdleStart()
{
	ChangeAnimationState("Idle");

	IdleTimer = 5.0f;
}

void Attack_Olive::IdleUpdate(float _Delta)
{
	IdleTimer -= _Delta;

	if (IdleTimer < 0.0f)
	{
		ChangeState(OliveState::Move);
		return;
	}
}

// 플레이어 위치 추적
void Attack_Olive::MoveStart()
{
	PlayerPos = ContentLevel::CurLevel->GetCurLevelPlayer()->Transform.GetWorldPosition();

	MoveDur = 1.0f;
}

void Attack_Olive::MoveUpdate(float _Delta)
{
	float4 MovePos = float4::ZERO;
	float4 OlivePos = Transform.GetWorldPosition();

	MoveDur -= _Delta;
	MovePos.Y = -50.0f;

	if (MoveDur > 0.0f)
	{
		MovePos.X = PlayerPos.X - OlivePos.X;
		Transform.AddLocalPosition(MovePos * _Delta);
	}

	if (MoveDur < 0.0f)
	{
		ChangeState(OliveState::Idle);
		return;
	}
}


void Attack_Olive::AttackStart()
{

}

void Attack_Olive::AttackUpdate(float _Delta)
{

}

void Attack_Olive::DeathStart()
{

}

void Attack_Olive::DeathUpdate(float _Delta)
{

}