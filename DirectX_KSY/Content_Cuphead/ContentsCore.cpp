#include "PreCompile.h"
#include "ContentsCore.h"
#include "LogoLevel.h"
#include "TitleLevel.h"
#include "TutorialLevel.h"
#include "OverWorldLevel.h"
#include "PlayLevel.h"

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
	GameEngineCore::CreateLevel<TutorialLevel>("TutorialLevel");
	GameEngineCore::CreateLevel<OverWorldLevel>("OverWorldLevel");
	GameEngineCore::CreateLevel<PlayLevel>("PlayLevel");
	GameEngineCore::ChangeLevel("PlayLevel");
}

void ContentsCore::Update(float _Delta)
{
}

void ContentsCore::Release()
{
}