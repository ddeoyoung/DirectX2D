#include "PreCompile.h"
#include "BaseCharacter.h"
#include "JumpDust.h"
#include "DashDust.h"

void BaseCharacter::CreateJumpDust()
{
	if (true == IsJump)
	{
		return;
	}

	std::shared_ptr<JumpDust> Dust = GetLevel()->CreateActor<JumpDust>();
	float4 PlayerPos = Transform.GetLocalPosition();
	float4 DustPos = PlayerPos;
	DustPos += float4{ 0, -120 };

	Dust->Transform.SetLocalPosition(DustPos);
}

void BaseCharacter::CreateDashDust()
{

}
