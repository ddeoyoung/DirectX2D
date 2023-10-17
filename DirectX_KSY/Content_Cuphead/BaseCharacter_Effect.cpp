#include "PreCompile.h"
#include "BaseCharacter.h"
#include "JumpDust.h"
#include "DashDust.h"
#include "RunDust.h"

void BaseCharacter::CreateRunDust()
{
	std::shared_ptr<RunDust> Dust = GetLevel()->CreateActor<RunDust>();
	float4 PlayerPos = Transform.GetLocalPosition();
	float4 DustPos = PlayerPos;
	DustPos += float4{ 0, -10 };

	Dust->Transform.SetLocalPosition(DustPos);
}

void BaseCharacter::CreateJumpDust()
{
	if (true == IsJump)
	{
		return;
	}

	std::shared_ptr<JumpDust> Dust = GetLevel()->CreateActor<JumpDust>();
	float4 PlayerPos = Transform.GetLocalPosition();
	float4 DustPos = PlayerPos;
	DustPos += float4{ 0, -20 };

	Dust->Transform.SetLocalPosition(DustPos);
}

void BaseCharacter::CreateDashDust()
{

}
