#include "PreCompile.h"
#include "ParrySpark_Object.h"

ParrySpark_Object::ParrySpark_Object()
{
}

ParrySpark_Object::~ParrySpark_Object()
{
}


void ParrySpark_Object::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Parry_Slap_Spark"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Cuphead\\Parry\\Parry_Slap_Spark");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();
	MainRenderer->CreateAnimation("Parry_Slap_Spark", "Parry_Slap_Spark", 0.05f, false);
	MainRenderer->SetEndEvent("Parry_Slap_Spark", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->Off();
		});
	MainRenderer->ChangeAnimation("Parry_Slap_Spark");
	MainRenderer->AutoSpriteSizeOn();

}

void ParrySpark_Object::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	EndCheck();
}

void ParrySpark_Object::EndCheck()
{
	if (true == MainRenderer->IsCurAnimationEnd())
	{
		Death();
	}
}