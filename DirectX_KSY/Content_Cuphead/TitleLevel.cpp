#include "PreCompile.h"
#include "TitleLevel.h"

#include "TitleBackground.h"
#include "Cuphead_And_Mugman.h"
#include "TitleMenuBackground.h"

TitleLevel::TitleLevel() 
{
}

TitleLevel::~TitleLevel() 
{
}

void TitleLevel::Start()
{
	ContentLevel::Start();
}

void TitleLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	ContentLevel::LevelStart(_PrevLevel);

	if (nullptr == Back)
	{
		Back = CreateActor<TitleBackground>();
	}

	if (nullptr == CupheadAndMugman)
	{
		CupheadAndMugman = CreateActor<Cuphead_And_Mugman>();
	}
	
	if (nullptr == MenuBack)
	{
		MenuBack = CreateActor<TitleMenuBackground>();
	}
	MenuBack->Off();
}

void TitleLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
}

void TitleLevel::Update(float _Delta)
{
	ContentLevel::Update(_Delta);

	if (GameEngineInput::IsPress('P', this))
	{
		Back->Off();
		CupheadAndMugman->Off();
		MenuBack->On();
	}

	if (GameEngineInput::IsPress('Z', this))
	{
		GameEngineCore::ChangeLevel("IntroLevel");
	}
}
