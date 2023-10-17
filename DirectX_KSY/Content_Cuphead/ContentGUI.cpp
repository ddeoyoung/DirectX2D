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
	std::string MousePos = GameEngineCore::MainWindow.GetMousePos().ToString();
	ImGui::Text(MousePos.c_str());

	// Collision On/OFf
	if (ImGui::Button("Collision On/Off"))
	{
		GameEngineLevel::IsDebug = !GameEngineLevel::IsDebug;
	}

}