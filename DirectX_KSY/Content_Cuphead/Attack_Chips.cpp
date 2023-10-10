#include "PreCompile.h"
#include "Attack_Chips.h"

Attack_Chips::Attack_Chips()
{
}

Attack_Chips::~Attack_Chips()
{
}

void Attack_Chips::Start()
{
	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("CigSmoke"))
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

	MainRenderer->CreateAnimation("Chips_Spin_Middle", "Chips_Spin_Middle");
	MainRenderer->CreateAnimation("Chips_Spin_Bottom", "Chips_Spin_Bottom");

	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetPivotType(PivotType::Bottom);
}

void Attack_Chips::Update(float _Delta)
{

}

void Attack_Chips::SetChips(float4 _BossPos, const std::string& _ChipType)
{
	float4 ChipPos = _BossPos;
	std::string ChipType = "Chips_Spin_" + _ChipType;

	MainRenderer->Transform.SetLocalPosition(ChipPos);
	MainRenderer->ChangeAnimation(ChipType);
}