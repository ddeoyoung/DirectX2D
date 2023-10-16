#include "PreCompile.h"
#include "RunDust.h"

RunDust::RunDust()
{
}

RunDust::~RunDust()
{
}

void RunDust::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Run_Dust"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Cuphead\\Jump");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();

	MainRenderer->CreateAnimation("Run_Dust", "Run_Dust", 0.07f, false);
	MainRenderer->ChangeAnimation("Run_Dust");

	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetPivotType(PivotType::Bottom);
}

void RunDust::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	EndCheck();
}

void RunDust::EndCheck()
{
	if (true == MainRenderer->IsCurAnimationEnd())
	{
		Death();
	}
}