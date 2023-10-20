#include "PreCompile.h"
#include "Attack_Olive.h"
#include "BaseCharacter.h"
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
	MainRenderer->ChangeAnimation("Olive_Appear");

	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetPivotType(PivotType::Bottom);
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

}

void Attack_Olive::AppearStart(){ }
void Attack_Olive::AppearUpdate(float _Delta){ }

void Attack_Olive::IdleStart()
{
	ChangeAnimationState("Idle");

	IdleTimer = 1.0f;
}

void Attack_Olive::IdleUpdate(float _Delta)
{
	IdleTimer -= _Delta;

	float4 MovePos = float4::ZERO;
	float4 OlivePos = Transform.GetWorldPosition();
	float4 PlayerPos = ContentLevel::CurLevel->GetCurLevelPlayer()->Transform.GetWorldPosition();

	MovePos = PlayerPos - OlivePos;
	Transform.AddLocalPosition(MovePos * _Delta);
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