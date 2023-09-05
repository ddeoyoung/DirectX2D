#include "PreCompile.h"
#include "Logo_Mdhr.h"

Logo_Mdhr::Logo_Mdhr()
{
}

Logo_Mdhr::~Logo_Mdhr()
{
}

void Logo_Mdhr::Start()
{

	if (nullptr == GameEngineSprite::Find("Logo"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	Renderer = CreateComponent<GameEngineSpriteRenderer>();
	Renderer->CreateAnimation("Logo", "Logo", 0.03f);
	Renderer->ChangeAnimation("Logo");

	Renderer->Transform.SetLocalScale({1280, 720});
}