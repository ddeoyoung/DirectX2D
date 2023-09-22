#include "PreCompile.h"
#include "ContentsCore.h"
#include "LogoLevel.h"
#include "TitleLevel.h"
#include "IntroLevel.h"
#include "TutorialLevel.h"
#include "OverWorldLevel.h"
#include "KingDiceLevel.h"
#include "PlayLevel.h"
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
	GameEngineCore::CreateLevel<OutroLevel>("OutroLevel");

	// Test Level
	GameEngineCore::CreateLevel<PlayLevel>("PlayLevel");

	GameEngineCore::ChangeLevel("KingDiceLevel");
}

void ContentsCore::Update(float _Delta)
{
	
}

void ContentsCore::Release()
{
}