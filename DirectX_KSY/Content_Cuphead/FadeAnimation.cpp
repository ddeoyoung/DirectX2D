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
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\UI\\FadeAnimation");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	MainRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::Max);
	MainRenderer->CreateAnimation("FadeIn", "FadeIn", 0.05f, -1, -1, false);
	MainRenderer->SetEndEvent("FadeIn", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->Off();
		});
	MainRenderer->CreateAnimation("FadeOut", "FadeOut", 0.05f, -1, -1, false);
	MainRenderer->ChangeAnimation("FadeIn");
	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetAutoScaleRatio(2.5);
	MainRenderer->Transform.SetLocalPosition({ 640, -360 });
}

void FadeAnimation::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	EndCheck();
}

void FadeAnimation::SetFade(const std::string& _Name)
{
	std::string Name = "Fade";
	if (_Name == "In" || _Name == "Out")
	{
		Name += _Name;
		MainRenderer->ChangeAnimation(Name);
	}
}

void FadeAnimation::EndCheck()
{
	if (true == MainRenderer->IsCurAnimationEnd())
	{
		//Death();
	}
}

bool FadeAnimation::IsCurAnimationEnd()
{
	if (true == MainRenderer->IsCurAnimationEnd())
	{
		return true;
	}

	return false;
}