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

	DirCheck();

	GameEngineColor PixelColor = KingDiceTable::KDTable->GetColor(Transform.GetWorldPosition(), GameEngineColor::RED);

	if (PixelColor != GameEngineColor::RED)
	{
		GravityForce.Y -= _Delta * 2200.0f;
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
	AttackDir CheckAttDir = AttDir;


	// 아무 방향키도 누르지 않은 상태면 ActorDir를 따름
	if ((false == GameEngineInput::IsDown(VK_LEFT) || false == GameEngineInput::IsPress(VK_LEFT))
		&& (false == GameEngineInput::IsDown(VK_RIGHT) || false == GameEngineInput::IsPress(VK_RIGHT)))
	{
		switch (Dir)
		{
		case ActorDir::Left:
			CheckAttDir = AttackDir::Left_Straight;
			break;
		case ActorDir::Right:
			CheckAttDir = AttackDir::Right_Straight;
			break;
		default:
			break;
		}
	}


	// Left Straight
	if ((true == GameEngineInput::IsDown(VK_LEFT) || true == GameEngineInput::IsPress(VK_LEFT)) 
		&& (true == GameEngineInput::IsUp(VK_UP) || true == GameEngineInput::IsFree(VK_UP))
		&& (true == GameEngineInput::IsUp(VK_DOWN) || true == GameEngineInput::IsFree(VK_DOWN)))
	{
		CheckDir = ActorDir::Left;
		CheckAttDir = AttackDir::Left_Straight;
		Transform.SetLocalScale({ -1.0f, 1.0f });
	}

	// Right Straight
	if ((true == GameEngineInput::IsDown(VK_RIGHT) || true == GameEngineInput::IsPress(VK_RIGHT))
		&& (true == GameEngineInput::IsUp(VK_UP) || true == GameEngineInput::IsFree(VK_UP))
		&& (true == GameEngineInput::IsUp(VK_DOWN) || true == GameEngineInput::IsFree(VK_DOWN)))
	{
		CheckDir = ActorDir::Right;
		CheckAttDir = AttackDir::Right_Straight;
		Transform.SetLocalScale({ 1.0f, 1.0f });
	}

	// Up
	if (true == GameEngineInput::IsDown(VK_UP) || true == GameEngineInput::IsPress(VK_UP))
	{
		CheckDir = ActorDir::Up;

		if (Dir == ActorDir::Left)
		{
			CheckAttDir = AttackDir::Left_Up;
			Transform.SetLocalScale({ -1.0f, 1.0f });
		}

		if (Dir == ActorDir::Right)
		{
			CheckAttDir = AttackDir::Right_Up;
			Transform.SetLocalScale({ 1.0f, 1.0f });
		}
	}

	// Down
	if (true == GameEngineInput::IsDown(VK_DOWN) || true == GameEngineInput::IsPress(VK_DOWN))
	{
		CheckDir = ActorDir::Down;

		if (Dir == ActorDir::Left)
		{
			CheckAttDir = AttackDir::Left_Down;
			Transform.SetLocalScale({ -1.0f, 1.0f });
		}

		if (Dir == ActorDir::Right)
		{
			CheckAttDir = AttackDir::Right_Down;
			Transform.SetLocalScale({ 1.0f, 1.0f });
		}
	}

	// Left Diagonal Up
	if ((true == GameEngineInput::IsDown(VK_LEFT) || true == GameEngineInput::IsPress(VK_LEFT))
		&& (true == GameEngineInput::IsDown(VK_UP) || true == GameEngineInput::IsPress(VK_UP)))
	{
		CheckDir = ActorDir::Left;
		CheckAttDir = AttackDir::Left_Diagonal_Up;
		Transform.SetLocalScale({ -1.0f, 1.0f });
	}

	// Right Diagonal Up
	if ((true == GameEngineInput::IsDown(VK_RIGHT) || true == GameEngineInput::IsPress(VK_RIGHT))
		&& (true == GameEngineInput::IsDown(VK_UP) || true == GameEngineInput::IsPress(VK_UP)))
	{
		CheckDir = ActorDir::Right;
		CheckAttDir = AttackDir::Right_Diagonal_Up;
		Transform.SetLocalScale({ 1.0f, 1.0f });
	}

	// Left Diagonal Down
	if ((true == GameEngineInput::IsDown(VK_LEFT) || true == GameEngineInput::IsPress(VK_LEFT))
		&& (true == GameEngineInput::IsDown(VK_DOWN) || true == GameEngineInput::IsPress(VK_DOWN)))
	{
		CheckDir = ActorDir::Left;
		CheckAttDir = AttackDir::Left_Diagonal_Down;
		Transform.SetLocalScale({ -1.0f, 1.0f });
	}

	// Right Diagonal Down
	if ((true == GameEngineInput::IsDown(VK_RIGHT) || true == GameEngineInput::IsPress(VK_RIGHT))
		&& (true == GameEngineInput::IsDown(VK_DOWN) || true == GameEngineInput::IsPress(VK_DOWN)))
	{
		CheckDir = ActorDir::Right;
		CheckAttDir = AttackDir::Right_Diagonal_Down;
		Transform.SetLocalScale({ 1.0f, 1.0f });
	}

	if (CheckDir != Dir || CheckAttDir != AttDir)
	{
		Dir = CheckDir;
		AttDir = CheckAttDir;
		ChangeAnimationState(CurState);
	}
}