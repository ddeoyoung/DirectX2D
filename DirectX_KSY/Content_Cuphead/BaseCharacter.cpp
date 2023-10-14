#include "PreCompile.h"
#include "BaseCharacter.h"
#include "Peashot.h"

#include "ContentLevel.h"
#include "ContentBackground.h"

BaseCharacter::BaseCharacter()
{
}

BaseCharacter::~BaseCharacter()
{
}

void BaseCharacter::Start()
{
	ContentActor::Start();
}

void BaseCharacter::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	StateUpdate(_Delta);
	DirCheck();
	Gravity(_Delta);
	LerpCamera(_Delta);

	MoveCheck();
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
		case CharacterState::RunShoot:
			RunShootStart();
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
	case CharacterState::RunShoot:
		return RunShootUpdate(_Delta);
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

	// Intro 상태일 때, 이동 불가
	if (CurState == "Intro")
	{
		return;
	}

	// 아무 방향키도 누르지 않은 상태면 ActorDir를 따름
	if ((false == GameEngineInput::IsDown(VK_LEFT, this) || false == GameEngineInput::IsPress(VK_LEFT, this))
		&& (false == GameEngineInput::IsDown(VK_RIGHT, this) || false == GameEngineInput::IsPress(VK_RIGHT, this)))
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
	if ((true == GameEngineInput::IsDown(VK_LEFT, this) || true == GameEngineInput::IsPress(VK_LEFT, this))
		&& (true == GameEngineInput::IsUp(VK_UP, this) || true == GameEngineInput::IsFree(VK_UP, this))
		&& (true == GameEngineInput::IsUp(VK_DOWN, this) || true == GameEngineInput::IsFree(VK_DOWN, this)))
	{
		CheckDir = ActorDir::Left;
		CheckAttDir = AttackDir::Left_Straight;
		Transform.SetLocalScale({ -1.0f, 1.0f });
	}

	// Right Straight
	if ((true == GameEngineInput::IsDown(VK_RIGHT, this) || true == GameEngineInput::IsPress(VK_RIGHT, this))
		&& (true == GameEngineInput::IsUp(VK_UP, this) || true == GameEngineInput::IsFree(VK_UP, this))
		&& (true == GameEngineInput::IsUp(VK_DOWN, this) || true == GameEngineInput::IsFree(VK_DOWN, this)))
	{
		CheckDir = ActorDir::Right;
		CheckAttDir = AttackDir::Right_Straight;
		Transform.SetLocalScale({ 1.0f, 1.0f });
	}

	// Up
	if (true == GameEngineInput::IsDown(VK_UP, this) || true == GameEngineInput::IsPress(VK_UP, this))
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
	if (true == GameEngineInput::IsDown(VK_DOWN, this) || true == GameEngineInput::IsPress(VK_DOWN, this))
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
	if ((true == GameEngineInput::IsDown(VK_LEFT, this) || true == GameEngineInput::IsPress(VK_LEFT, this))
		&& (true == GameEngineInput::IsDown(VK_UP, this) || true == GameEngineInput::IsPress(VK_UP, this)))
	{
		CheckDir = ActorDir::Left;
		CheckAttDir = AttackDir::Left_Diagonal_Up;
		Transform.SetLocalScale({ -1.0f, 1.0f });
	}

	// Right Diagonal Up
	if ((true == GameEngineInput::IsDown(VK_RIGHT, this) || true == GameEngineInput::IsPress(VK_RIGHT, this))
		&& (true == GameEngineInput::IsDown(VK_UP, this) || true == GameEngineInput::IsPress(VK_UP, this)))
	{
		CheckDir = ActorDir::Right;
		CheckAttDir = AttackDir::Right_Diagonal_Up;
		Transform.SetLocalScale({ 1.0f, 1.0f });
	}

	// Left Diagonal Down
	if ((true == GameEngineInput::IsDown(VK_LEFT, this) || true == GameEngineInput::IsPress(VK_LEFT, this))
		&& (true == GameEngineInput::IsDown(VK_DOWN, this) || true == GameEngineInput::IsPress(VK_DOWN, this)))
	{
		CheckDir = ActorDir::Left;
		CheckAttDir = AttackDir::Left_Diagonal_Down;
		Transform.SetLocalScale({ -1.0f, 1.0f });
	}

	// Right Diagonal Down
	if ((true == GameEngineInput::IsDown(VK_RIGHT, this) || true == GameEngineInput::IsPress(VK_RIGHT, this))
		&& (true == GameEngineInput::IsDown(VK_DOWN, this) || true == GameEngineInput::IsPress(VK_DOWN, this)))
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

bool BaseCharacter::MoveCheck()
{
	if ((true == GameEngineInput::IsDown(VK_LEFT, this) || true == GameEngineInput::IsPress(VK_LEFT, this))
		|| (true == GameEngineInput::IsDown(VK_RIGHT, this) || true == GameEngineInput::IsPress(VK_RIGHT, this)))
	{
		if (true == GameEngineInput::IsDown('C', this) || true == GameEngineInput::IsPress('C', this))
		{
			IsAim = true;

			return false;
		}

		else
		{
			IsAim = false;
		}

		return true;
	}


	//GameEngineColor Color = GetPixelColor();

	//if (Color == GameEngineColor::RED)
	//{
	//	int a = 0;
	//}

	return false;
}

void BaseCharacter::Gravity(float _Delta)
{
	GameEngineColor GroundColor = GetPixelColor(float4::ZERO);
	 
	if (GroundColor != GameEngineColor::RED)
	{
		GravityForce.Y -= _Delta * GRAVITYFORCE;
		Transform.AddLocalPosition(GravityForce * _Delta);
	}

	else
	{
		GravityForce = 0.0f;
	}
}

void BaseCharacter::LerpCamera(float _Delta)
{
	float CameraSpeed = 2.5f;
	float4 WindowScale = GameEngineCore::MainWindow.GetScale();
	float4 TextureScale = ContentLevel::CurLevel->GetCurLevelPixelBackground()->GetPixelTextureScale();

	float4 CameraPos = GetLevel()->GetMainCamera()->Transform.GetWorldPosition(); // Start
	float4 PlayerPos = Transform.GetWorldPosition(); // End
	float4 MovePos = float4::LerpClamp(CameraPos, PlayerPos, CameraSpeed * _Delta);

	// 카메라 Y 고정
	MovePos.Y = CameraPos.Y;

	if (MovePos.iX() > WindowScale.hX()
		&& MovePos.iX() < TextureScale.iX() - WindowScale.hX())
	{
		GetLevel()->GetMainCamera()->Transform.SetWorldPosition(MovePos);
	}

}

GameEngineColor BaseCharacter::GetPixelColor(float4 _Pos)
{
	float4 PlayerPos = Transform.GetWorldPosition();
	float4 CheckPos = PlayerPos + _Pos;

	GameEngineColor Color = ContentLevel::CurLevel->GetCurLevelPixelBackground()->GetColor(CheckPos, GameEngineColor::RED);

	return Color;
}