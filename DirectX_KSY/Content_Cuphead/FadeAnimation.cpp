#include "PreCompile.h"
#include "FadeAnimation.h"

FadeAnimation::FadeAnimation()
{
}

FadeAnimation::~FadeAnimation()
{
}

void FadeAnimation::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("FadeAnimation"))
	{
		// Dice
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\UI");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	MainRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::Max);
	MainRenderer->CreateAnimation("FadeAnimation", "FadeAnimation", 0.05f, false);
	MainRenderer->SetEndEvent("FadeAnimation", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->Off();
		});
	MainRenderer->ChangeAnimation("FadeAnimation");
	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetAutoScaleRatio(2.5);
	MainRenderer->Transform.SetLocalPosition({ 640, -360 });
}

void FadeAnimation::Update(float _Delta)
{
	ContentActor::Update(_Delta);
}