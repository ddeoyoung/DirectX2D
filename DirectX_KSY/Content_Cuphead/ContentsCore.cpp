#include "PreCompile.h"
#include "ContentsCore.h"
#include "LogoLevel.h"
#include "TitleLevel.h"
#include "IntroLevel.h"
#include "TutorialLevel.h"
#include "OverWorldLevel.h"
#include "KingDiceLevel.h"
#include "TipsyTroopLevel.h"
#include "ChipsBettiganLevel.h"
#include "OutroLevel.h"

ContentsCore::ContentsCore()
{
}

ContentsCore::~ContentsCore()
{
}

void ContentsCore::Start()
{
	GameEngineCore::CreateLevel<LogoLevel>("LogoLevel");
	GameEngineCore::CreateLevel<TitleLevel>("TitleLevel");
	GameEngineCore::CreateLevel<IntroLevel>("IntroLevel");
	GameEngineCore::CreateLevel<TutorialLevel>("TutorialLevel");
	GameEngineCore::CreateLevel<OverWorldLevel>("OverWorldLevel");
	GameEngineCore::CreateLevel<KingDiceLevel>("KingDiceLevel");
	GameEngineCore::CreateLevel<TipsyTroopLevel>("TipsyTroopLevel");
	GameEngineCore::CreateLevel<ChipsBettiganLevel>("ChipsBettiganLevel");
	GameEngineCore::CreateLevel<OutroLevel>("OutroLevel");

	GameEngineCore::ChangeLevel("ChipsBettiganLevel");
}

void ContentsCore::Update(float _Delta)
{
	
}

void ContentsCore::Release()
{
}