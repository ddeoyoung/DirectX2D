#include "PreCompile.h"
#include "StoryBook.h"

StoryBook::StoryBook()
{
}

StoryBook::~StoryBook()
{
}

void StoryBook::Start()
{
	if (nullptr == GameEngineSprite::Find("Page0"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Storybook");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	Renderer = CreateComponent<GameEngineSpriteRenderer>();

	// Intro
	Renderer->CreateAnimation("Page0", "Page0", 0.03f);
	//Renderer->SetEndEvent("Page0", [](GameEngineSpriteRenderer* _Render)
	//	{
	//		_Render->ChangeAnimation("Page1");
	//	});

	Renderer->CreateAnimation("Page1", "Page1", 0.03f);
	//Renderer->SetEndEvent("Page1", [](GameEngineSpriteRenderer* _Render)
	//	{
	//		_Render->ChangeAnimation("Page2");
	//	});

	Renderer->CreateAnimation("Page2", "Page2", 0.03f, false);
	Renderer->CreateAnimation("Page3", "Page3", 0.03f, false);
	Renderer->CreateAnimation("Page4", "Page4", 0.03f, false);
	Renderer->CreateAnimation("Page5", "Page5", 0.03f, false);
	Renderer->CreateAnimation("Page6", "Page6", 0.03f, false);
	Renderer->CreateAnimation("Page7", "Page7", 0.03f, false);
	Renderer->CreateAnimation("Page8", "Page8", 0.03f, false);
	Renderer->CreateAnimation("Page9", "Page9", 0.03f, false);
	Renderer->CreateAnimation("Page10", "Page10", 0.03f, 1, 23, false);
	Renderer->SetEndEvent("Page10", [](GameEngineSpriteRenderer* _Render)
		{
			GameEngineCore::ChangeLevel("TutorialLevel");
		});

	// Outro
	Renderer->CreateAnimation("Page12", "Page12", 0.03f, false);
	Renderer->CreateAnimation("Page13", "Page13", 0.03f, false);
	Renderer->CreateAnimation("Page14", "Page14", 0.03f, false);
	Renderer->CreateAnimation("Page15", "Page15", 0.03f, false);
	Renderer->CreateAnimation("Page16", "Page16", 0.03f, false);
	Renderer->CreateAnimation("Page17", "Page17", 0.03f, false);

	Renderer->ChangeAnimation("Page0");

	Renderer->Transform.SetLocalScale({ 1280, 720 });
}

void StoryBook::Update(float _Delta)
{
	if (true == Renderer->IsCurAnimationEnd() && PageNumber <= 10)
	{
		Renderer->ChangeAnimation("Page" + std::to_string(PageNumber++));
		//PageDur = 0.0f;
	}
}