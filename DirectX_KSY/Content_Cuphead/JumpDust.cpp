#include "PreCompile.h"
#include "JumpDust.h"

JumpDust::JumpDust()
{
}

JumpDust::~JumpDust()
{
}

void JumpDust::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Peashot_Spark"))
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

	MainRenderer->CreateAnimation("Jump_Dust_A", "Jump_Dust_A", 0.07f, false);
	MainRenderer->CreateAnimation("Jump_Dust_B", "Jump_Dust_B", 0.07f, false);
	MainRenderer->ChangeAnimation("Jump_Dust_A");

	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetPivotType(PivotType::Bottom);
}

void JumpDust::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	EndCheck();
}

void JumpDust::EndCheck()
{
	if (true == MainRenderer->IsCurAnimationEnd())
	{
		Death();
	}
}