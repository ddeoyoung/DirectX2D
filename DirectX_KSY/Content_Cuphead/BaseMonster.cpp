#include "PreCompile.h"
#include "BaseMonster.h"

BaseMonster::BaseMonster()
{
}

BaseMonster::~BaseMonster()
{
}

void BaseMonster::HPMinus()
{
	if (1 <= HP)
	{
		--HP;
	}

	if (0 >= HP)
	{
		IsDeath = true;
	}
}