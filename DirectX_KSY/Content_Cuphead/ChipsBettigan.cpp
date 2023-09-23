#include "PreCompile.h"
#include "ChipsBettigan.h"

ChipsBettigan::ChipsBettigan()
{
}

ChipsBettigan::~ChipsBettigan()
{
}

void ChipsBettigan::Start()
{
	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Chips_Idle"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\ChipsBettigan\\Boss");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();

	MainRenderer->CreateAnimation("Chips_Intro", "Chips_Intro");
	MainRenderer->CreateAnimation("Chips_Idle", "Chips_Idle", 0.05f);
	MainRenderer->ChangeAnimation("Chips_Idle");

	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetPivotType(PivotType::Bottom);

	Transform.SetLocalPosition({ 1000 , -650 });
}

void ChipsBettigan::Update(float _Delta)
{

}

void ChipsBettigan::ChangeState(ChipsState _State)
{

}

void ChipsBettigan::StateUpdate(float _Delta)
{

}