#include "PreCompile.h"
#include "ContentGUI.h"

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
	ImGui::Text("Level Change");
	if (ImGui::Button("Tutorial Level"))
	{
		GameEngineCore::ChangeLevel("TutorialLevel");
	}

	if (ImGui::Button("KingDice Level"))
	{
		GameEngineCore::ChangeLevel("KingDiceLevel");
	}

}