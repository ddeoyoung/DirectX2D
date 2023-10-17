#include "PreCompile.h"
#include "BaseCharacter.h"
#include "JumpDust.h"
#include "DashDust.h"
#include "RunDust.h"

void BaseCharacter::CreateRunDust()
{
	RunEffect = GetLevel()->CreateActor<RunDust>();
	float4 PlayerPos = Transform.GetLocalPosition();
	float4 DustPos = PlayerPos;
	DustPos += float4{ 0, -10 };

	RunEffect->Transform.SetLocalPosition(DustPos);
}

void BaseCharacter::CreateJumpDust()
{
	if (true == IsJump)
	{
		return;
	}

	JumpEffect = GetLevel()->CreateActor<JumpDust>();
	float4 PlayerPos = Transform.GetLocalPosition();
	float4 DustPos = PlayerPos;
	DustPos += float4{ 0, -20 };

	JumpEffect->Transform.SetLocalPosition(DustPos);
}

void BaseCharacter::CreateDashDust()
{
	DashEffect = GetLevel()->CreateActor<DashDust>();

	float4 PlayerPos = Transform.GetLocalPosition();
	float4 DustPos = PlayerPos;
	ActorDir PlayerDir = GetPlayerDir();

	switch (PlayerDir)
	{
	case ActorDir::Left:
		DustPos += float4{ 20.0f, -20.0f };
		DashEffect->Transform.SetLocalPosition(DustPos);
		DashEffect->Transform.SetLocalScale({ -1.0f, 1.0f });
		break;
	case ActorDir::Right:
		DustPos += float4{ -20.0f, -20.0f };
		DashEffect->Transform.SetLocalPosition(DustPos);
		DashEffect->Transform.SetLocalScale({ 1.0f, 1.0f });
		break;
	default:
		break;
	}
}
