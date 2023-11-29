#include "PreCompile.h"
#include "TitleLevel.h"

#include "TitleBackground.h"
#include "Cuphead_And_Mugman.h"
#include "TitleMenuBackground.h"
#include "TitleMenuButton.h"
#include "FadeAnimation.h"

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

	// Title - Background
	if (nullptr == Back)
	{
		Back = CreateActor<TitleBackground>();
	}

	// Cuphead And Mugman Animation
	if (nullptr == CupheadAndMugman)
	{
		CupheadAndMugman = CreateActor<Cuphead_And_Mugman>();
	}
	
	// Menu - Background
	if (nullptr == MenuBack)
	{
		MenuBack = CreateActor<TitleMenuBackground>();
	}
	MenuBack->Off();

	// Menu - Button
	if (nullptr == MenuButton)
	{
		MenuButton = CreateActor<TitleMenuButton>();
	}
	MenuButton->Off();

	// Fade Out
	if (nullptr == FadeOut)
	{
		FadeOut = CreateActor<FadeAnimation>();
		FadeOut->SetFade("Out");
		FadeOut->Off();
	}
}

void TitleLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
}

void TitleLevel::Update(float _Delta)
{
	ContentLevel::Update(_Delta);

	// Change To Menu
	if (true == GameEngineInput::IsPress('P', this))
	{
		Back->Off();
		CupheadAndMugman->Off();
		MenuBack->On();
		MenuButton->On();
	}

	// FadeOut On
	bool IsLevelChange = MenuButton->GetIsLevelChange();
	if (true == IsLevelChange)
	{
		FadeOut->On();
	}

	// Check FadeOut End
	if (true == FadeOut->IsCurAnimationEnd())
	{
		GameEngineCore::ChangeLevel("IntroLevel");
	}

	// Exit Game
	bool IsGameExit = MenuButton->GetIsGameExit();
	if (true == IsGameExit)
	{
		GameEngineWindow::WindowLoopOff();
	}
}
