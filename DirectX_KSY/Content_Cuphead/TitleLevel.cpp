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
	GetMainCamera()->Transform.SetLocalPosition({ 0.0f, 0.0f, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	Back = CreateActor<TitleBackground>();
	CupheadAndMugman = CreateActor<Cuphead_And_Mugman>();
	MenuBack = CreateActor<TitleMenuBackground>();
	MenuBack->Off();
}


void TitleLevel::Update(float _Delta)
{
	if (GameEngineInput::IsPress('P'))
	{
		Back->Off();
		CupheadAndMugman->Off();
		MenuBack->On();
	}

	if (GameEngineInput::IsPress('Z'))
	{
		GameEngineCore::ChangeLevel("PlayLevel");
	}
}


void TitleLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	int a = 0;
}

void TitleLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	int a = 0;
}