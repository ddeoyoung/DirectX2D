#include "PreCompile.h"
#include "KingDice.h"

KingDice::KingDice()
{
}

KingDice::~KingDice()
{
}

void KingDice::Start()
{
	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("KingDice_Idle"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\KingDice\\Boss");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::Play);

	// Idle
	MainRenderer->CreateAnimation("KingDice_Idle", "KingDice_Idle", 0.05f);
	MainRenderer->CreateAnimation("KingDice_Intro", "KingDice_Intro");
	MainRenderer->CreateAnimation("KingDice_Reveal", "KingDice_Reveal");
	MainRenderer->CreateAnimation("KingDice_CameraEat", "KingDice_CameraEat");
	MainRenderer->CreateAnimation("KingDice_Death", "KingDice_Death");
	MainRenderer->ChangeAnimation("KingDice_Idle");

	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetPivotType(PivotType::Bottom);

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({HalfWindowScale.X + 25.0f, -HalfWindowScale.Y -40.0f});
}

void KingDice::Update(float _Delta)
{

}