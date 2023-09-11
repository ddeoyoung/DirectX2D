#include "PreCompile.h"
#include "BaseCharacter.h"

#include "KingDiceTable.h"

BaseCharacter::BaseCharacter()
{
}

BaseCharacter::~BaseCharacter()
{
}

void BaseCharacter::Start()
{
	
}

void BaseCharacter::Update(float _Delta)
{
	StateUpdate(_Delta);

	GameEngineColor PixelColor = KingDiceTable::KDTable->GetColor(Transform.GetWorldPosition(), GameEngineColor::RED);

	if (PixelColor != GameEngineColor::RED)
	{
		GravityForce.Y -= _Delta * 2000.0f;
		Transform.AddLocalPosition(GravityForce * _Delta);
	}

	else
	{
		GravityForce = 0.0f;
	}
}

void BaseCharacter::ChangeState(CharacterState _State)
{
	if (_State != State)
	{
		switch (_State)
		{
		case CharacterState::None:
			break;
		case CharacterState::Idle:
			IdleStart();
			break;
		case CharacterState::Run:
			RunStart();
			break;
		case CharacterState::Aim:
			AimStart();
			break;
		case CharacterState::Shoot:
			ShootStart();
			break;
		case CharacterState::Duck:
			DuckStart();
			break;
		case CharacterState::DuckIdle:
			DuckIdleStart();
			break;
		case CharacterState::DuckShoot:
			DuckShootStart();
			break;
		case CharacterState::Hit:
			HitStart();
			break;
		case CharacterState::Dash:
			DashStart();
			break;
		case CharacterState::Jump:
			JumpStart();
			break;
		case CharacterState::Parry:
			ParryStart();
			break;
		case CharacterState::Intro:
			IntroStart();
			break;
		case CharacterState::Ghost:
			GhostStart();
			break;
		case CharacterState::Death:
			DeathStart();
			break;
		case CharacterState::Max:
			break;
		default:
			break;
		}
	}

	State = _State;
}

void BaseCharacter::StateUpdate(float _Delta)
{
	switch (State)
	{
	case CharacterState::None:
		break;
	case CharacterState::Idle:
		return IdleUpdate(_Delta);
	case CharacterState::Run:
		return RunUpdate(_Delta);
	case CharacterState::Aim:
		return AimUpdate(_Delta);
	case CharacterState::Shoot:
		return ShootUpdate(_Delta);
	case CharacterState::Duck:
		return DuckUpdate(_Delta);
	case CharacterState::DuckIdle:
		return DuckIdleUpdate(_Delta);
	case CharacterState::DuckShoot:
		return DuckShootUpdate(_Delta);
	case CharacterState::Hit:
		return HitUpdate(_Delta);
	case CharacterState::Dash:
		return DashUpdate(_Delta);
	case CharacterState::Jump:
		return JumpUpdate(_Delta);
	case CharacterState::Parry:
		return ParryUpdate(_Delta);
	case CharacterState::Intro:
		return IntroUpdate(_Delta);
	case CharacterState::Ghost:
		return GhostUpdate(_Delta);
	case CharacterState::Death:
		return DeathUpdate(_Delta);
	case CharacterState::Max:
		break;
	default:
		break;
	}
}

void BaseCharacter::ChangeAnimationState(const std::string& _StateName) {}

void BaseCharacter::DirCheck()
{
	ActorDir CheckDir = Dir;

	if (true == GameEngineInput::IsDown(VK_LEFT) || true == GameEngineInput::IsPress(VK_LEFT))
	{
		CheckDir = ActorDir::Left;
		Transform.SetLocalScale({ -1.0f, 1.0f });
	}
	if (true == GameEngineInput::IsDown(VK_RIGHT) || true == GameEngineInput::IsPress(VK_RIGHT))
	{
		CheckDir = ActorDir::Right;
		Transform.SetLocalScale({ 1.0f, 1.0f });
	}
	if (true == GameEngineInput::IsDown(VK_UP) || true == GameEngineInput::IsPress(VK_UP))
	{
		CheckDir = ActorDir::Up;
	}
	if (true == GameEngineInput::IsDown(VK_DOWN) || true == GameEngineInput::IsPress(VK_DOWN))
	{
		CheckDir = ActorDir::Down;
	}

	if (CheckDir != Dir)
	{
		Dir = CheckDir;
		ChangeAnimationState(CurState);
	}
}