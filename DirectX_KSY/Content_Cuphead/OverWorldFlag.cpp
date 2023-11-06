#include "PreCompile.h"
#include "OverWorldFlag.h"

OverWorldFlag::OverWorldFlag()
{
}

OverWorldFlag::~OverWorldFlag()
{
}


void OverWorldFlag::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Flag_Start"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\OverWorld\\OverWorldFlag");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();
	MainRenderer->CreateAnimation("BossExplosion", "BossExplosion", 0.05f, -1, -1, false);
	MainRenderer->SetEndEvent("BossExplosion", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->Off();
		});
	MainRenderer->ChangeAnimation("BossExplosion");
	MainRenderer->AutoSpriteSizeOn();

}

void OverWorldFlag::Update(float _Delta)
{
	ContentActor::Update(_Delta);
}
