#include "PreCompile.h"
#include "ContentsCore.h"
#include "LogoLevel.h"
#include "TitleLevel.h"

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
	GameEngineCore::ChangeLevel("LogoLevel");
}

void ContentsCore::Update(float _Delta)
{
}

void ContentsCore::Release()
{
}