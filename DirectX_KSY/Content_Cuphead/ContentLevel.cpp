#include "PreCompile.h"
#include "ContentLevel.h"

ContentLevel::ContentLevel()
{
}

ContentLevel::~ContentLevel()
{
}

void ContentLevel::Start()
{
	GetMainCamera()->Transform.SetLocalPosition({ 0.0f, 0.0f, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);
}

void ContentLevel::Update(float _Delta)
{
	if (true == GameEngineInput::IsDown(VK_F1))
	{
		GameEngineCore::ChangeLevel("TitleLevel");
	}

	if (true == GameEngineInput::IsDown(VK_F2))
	{
		GameEngineCore::ChangeLevel("TutorialLevel");
	}

	if (true == GameEngineInput::IsDown(VK_F3))
	{
		GameEngineCore::ChangeLevel("OverWorldLevel");
	}

	if (true == GameEngineInput::IsDown(VK_F4))
	{
		GameEngineCore::ChangeLevel("PlayLevel");
	}
}

void ContentLevel::LevelStart(GameEngineLevel* _PrevLevel)
{

}

void ContentLevel::LevelEnd(GameEngineLevel* _NextLevel)
{

}