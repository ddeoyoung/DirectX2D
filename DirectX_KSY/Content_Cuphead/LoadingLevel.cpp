#include "PreCompile.h"
#include "LoadingLevel.h"
#include "Hourglass.h"

LoadingLevel::LoadingLevel()
{
}

LoadingLevel::~LoadingLevel()
{
}

void LoadingLevel::Start()
{
	ContentLevel::Start();

	// Background
	if (nullptr == GameEngineSprite::Find("BlackBack.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Loading");

		GameEngineTexture::Load(Dir.GetStringPath() + "\\BlackBack.png");
		GameEngineSprite::CreateSingle("BlackBack.png");
	}

}

void LoadingLevel::Update(float _Delta)
{
	ContentLevel::Update(_Delta);
}


void LoadingLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	ContentLevel::LevelStart(_PrevLevel);

	CurLevelBackground = CreateActor<ContentBackground>();
	CurLevelBackground->BackgroundInit("BlackBack.png");

	Glass = CreateActor<Hourglass>();
}

void LoadingLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
}