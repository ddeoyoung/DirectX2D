#include "PreCompile.h"
#include "Hourglass.h"

Hourglass::Hourglass()
{
}

Hourglass::~Hourglass()
{
}

void Hourglass::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("HourGlass_New"))
	{
		// Dice
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Loading\\HourGlass");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();
	MainRenderer->CreateAnimation("HourGlass_New", "HourGlass_New", 0.05f);
	MainRenderer->ChangeAnimation("HourGlass_New");
	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->Transform.SetLocalPosition({ 1150 , -500 });
}

void Hourglass::Update(float _Delta)
{
	ContentActor::Update(_Delta);
}