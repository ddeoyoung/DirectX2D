#include "PreCompile.h"
#include "ContentsCore.h"
#include "LogoLevel.h"
#include "TitleLevel.h"
#include "IntroLevel.h"
#include "ElderKettleLevel.h"
#include "TutorialLevel.h"
#include "OverWorldLevel.h"
#include "InkwellHellLevel.h"
#include "KingDiceLevel.h"
#include "TipsyTroopLevel.h"
#include "ChipsBettiganLevel.h"
#include "MrWheezyLevel.h"
#include "PipandDotLevel.h"
#include "OutroLevel.h"
#include "LoadingLevel.h"


ContentsCore::ContentsCore()
{
}

ContentsCore::~ContentsCore()
{
}

void ContentsCore::Start()
{
	ContentRes();

	GameEngineCore::CreateLevel<LogoLevel>("LogoLevel");
	GameEngineCore::CreateLevel<TitleLevel>("TitleLevel");
	GameEngineCore::CreateLevel<IntroLevel>("IntroLevel");
	GameEngineCore::CreateLevel<ElderKettleLevel>("ElderKettleLevel");
	GameEngineCore::CreateLevel<TutorialLevel>("TutorialLevel");
	GameEngineCore::CreateLevel<OverWorldLevel>("OverWorldLevel");
	GameEngineCore::CreateLevel<InkwellHellLevel>("InkwellHellLevel");
	GameEngineCore::CreateLevel<KingDiceLevel>("KingDiceLevel");
	GameEngineCore::CreateLevel<TipsyTroopLevel>("TipsyTroopLevel");
	GameEngineCore::CreateLevel<ChipsBettiganLevel>("ChipsBettiganLevel");
	GameEngineCore::CreateLevel<MrWheezyLevel>("MrWheezyLevel");
	GameEngineCore::CreateLevel<PipandDotLevel>("PipandDotLevel");
	GameEngineCore::CreateLevel<OutroLevel>("OutroLevel");
	GameEngineCore::CreateLevel<LoadingLevel>("LoadingLevel");

	GameEngineCore::ChangeLevel("OverWorldLevel");
}

void ContentsCore::Update(float _Delta)
{
	
}

void ContentsCore::Release()
{

}