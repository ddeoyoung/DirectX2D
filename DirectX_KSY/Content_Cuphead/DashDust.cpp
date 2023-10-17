#include "PreCompile.h"
#include "DashDust.h"

DashDust::DashDust()
{
}

DashDust::~DashDust()
{
}

void DashDust::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Dash_Dust"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Cuphead\\Dash");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();

	MainRenderer->CreateAnimation("Dash_Dust", "Dash_Dust", 0.07f, false);
	MainRenderer->ChangeAnimation("Dash_Dust");

	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetPivotType(PivotType::Bottom);

}

void DashDust::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	EndCheck();
}

void DashDust::EndCheck()
{
	if (true == MainRenderer->IsCurAnimationEnd())
	{
		Death();
	}
}