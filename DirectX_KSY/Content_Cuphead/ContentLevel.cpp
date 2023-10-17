#include "PreCompile.h"
#include "ContentLevel.h"


ContentLevel::ContentLevel()
{
}

ContentLevel::~ContentLevel()
{
}

ContentLevel* ContentLevel::CurLevel = nullptr;

void ContentLevel::Start()
{
	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	//CurLevelGUI = GameEngineGUI::CreateGUIWindow<ContentGUI>("ContentGUI");
}


//TitleLevel
//IntroLevel
//TutorialLevel
//OverWorldLevel
//KingDiceLevel
//OutroLevel

void ContentLevel::Update(float _Delta)
{
	if (true == GameEngineInput::IsDown(VK_F1, this))
	{
		GameEngineCore::ChangeLevel("TitleLevel");
	}

	if (true == GameEngineInput::IsDown(VK_F2, this))
	{
		GameEngineCore::ChangeLevel("IntroLevel");
	}

	if (true == GameEngineInput::IsDown(VK_F3, this))
	{
		GameEngineCore::ChangeLevel("TutorialLevel");
	}

	if (true == GameEngineInput::IsDown(VK_F4, this))
	{
		GameEngineCore::ChangeLevel("OverWorldLevel");
	}

	if (true == GameEngineInput::IsDown(VK_F5, this))
	{
		GameEngineCore::ChangeLevel("KingDiceLevel");
	}

	if (true == GameEngineInput::IsDown(VK_F6, this))
	{
		GameEngineCore::ChangeLevel("ChipsBettiganLevel");
	}

}

void ContentLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	CurLevel = this;
}

void ContentLevel::LevelEnd(GameEngineLevel* _NextLevel)
{

}