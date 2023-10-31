#include "PreCompile.h"
#include "ContentGUI.h"
#include "Marker.h"

ContentGUI::ContentGUI()
{
}

ContentGUI::~ContentGUI()
{
}

void ContentGUI::Start()
{

}

void ContentGUI::OnGUI(GameEngineLevel* _Level, float _DeltaTime)
{
	// Mouse Pos
	ImGui::Text("Mouse Pos");
	std::string MousePos = GameEngineCore::MainWindow.GetMousePos().ToString();
	ImGui::Text(MousePos.c_str());
	ImGui::Text("\n");


	// Collision On/Off
	ImGui::Text("Collision On/Off");
	if (ImGui::Button("Collision On/Off"))
	{
		GameEngineLevel::IsDebug = !GameEngineLevel::IsDebug;
	}
	ImGui::Text("\n");


	// Level Change
	ImGui::Text("Change Level");
	if (ImGui::Button("Logo Level"))
	{
		GameEngineCore::ChangeLevel("LogoLevel");
	}

	if (ImGui::Button("Title Level"))
	{
		GameEngineCore::ChangeLevel("TitleLevel");
	}

	if (ImGui::Button("Intro Level"))
	{
		GameEngineCore::ChangeLevel("IntroLevel");
	}

	if (ImGui::Button("Tutorial Level"))
	{
		GameEngineCore::ChangeLevel("TutorialLevel");
	}

	if (ImGui::Button("OverWorld Level"))
	{
		GameEngineCore::ChangeLevel("OverWorldLevel");
	}

	if (ImGui::Button("KingDice Level"))
	{
		GameEngineCore::ChangeLevel("KingDiceLevel");
	}

	if (ImGui::Button("TipsyTroop Level"))
	{
		GameEngineCore::ChangeLevel("TipsyTroopLevel");
	}

	if (ImGui::Button("ChipsBettigan Level"))
	{
		GameEngineCore::ChangeLevel("ChipsBettiganLevel");
	}

	if (ImGui::Button("MrWheezy Level"))
	{
		GameEngineCore::ChangeLevel("MrWheezyLevel");
	}

	if (ImGui::Button("PipandDot Level"))
	{
		GameEngineCore::ChangeLevel("PipandDotLevel");
	}

	if (ImGui::Button("Loading Level"))
	{
		GameEngineCore::ChangeLevel("LoadingLevel");
	}
}