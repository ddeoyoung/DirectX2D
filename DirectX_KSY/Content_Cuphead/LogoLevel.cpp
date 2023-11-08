#include "PreCompile.h"
#include "LogoLevel.h"

#include "Logo_Mdhr.h"

LogoLevel::LogoLevel()
{

}

LogoLevel::~LogoLevel()
{

}

void LogoLevel::Start()
{
	ContentLevel::Start();
}

void LogoLevel::Update(float _Delta)
{
	ContentLevel::Update(_Delta);

	if (true == Logo->MainRenderer->IsCurAnimationEnd())
	{
		GameEngineCore::ChangeLevel("TitleLevel");
	}
}

void LogoLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	if (nullptr == Logo)
	{
		Logo = CreateActor<Logo_Mdhr>();
	}
}

void LogoLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
}