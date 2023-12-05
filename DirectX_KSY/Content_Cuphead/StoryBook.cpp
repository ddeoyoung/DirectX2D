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
	ContentActor::Start();

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
	Renderer->CreateAnimation("Page0", "Page0", PAGEDUR, 1, 100, false);
	Renderer->SetEndEvent("Page0", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Page1");
		});

	Renderer->CreateAnimation("Page1", "Page1", PAGEDUR, 1, 24, false);
	Renderer->SetEndEvent("Page1", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Page2");
		});

	Renderer->CreateAnimation("Page2", "Page2", PAGEDUR, 1, 23, false);
	Renderer->SetEndEvent("Page2", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Page3");
		});

	Renderer->CreateAnimation("Page3", "Page3", PAGEDUR, 1, 23, false);
	Renderer->SetEndEvent("Page3", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Page4");
		});

	Renderer->CreateAnimation("Page4", "Page4", PAGEDUR, 1, 23, false);
	Renderer->SetEndEvent("Page4", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Page5");
		});

	Renderer->CreateAnimation("Page5", "Page5", PAGEDUR, 1, 24, false);
	Renderer->SetEndEvent("Page5", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Page6");
		});

	Renderer->CreateAnimation("Page6", "Page6", PAGEDUR, 1, 21, false);
	Renderer->SetEndEvent("Page6", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Page7");
		});

	Renderer->CreateAnimation("Page7", "Page7", PAGEDUR, 1, 23, false);
	Renderer->SetEndEvent("Page7", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Page8");
		});

	Renderer->CreateAnimation("Page8", "Page8", PAGEDUR, 1, 23, false);
	Renderer->SetEndEvent("Page8", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Page9");
		});

	Renderer->CreateAnimation("Page9", "Page9", PAGEDUR, 1, 23, false);
	Renderer->SetEndEvent("Page9", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Page10");
		});

	Renderer->CreateAnimation("Page10", "Page10", PAGEDUR, 1, 23, false);
	Renderer->SetEndEvent("Page10", [](GameEngineSpriteRenderer* _Render)
		{
			GameEngineCore::ChangeLevel("ElderKettleLevel");
		});



	/////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////// Outro ///////////////////////////////////////////

	Renderer->CreateAnimation("Page12", "Page12", PAGEDUR, 1, 23, false);
	Renderer->SetEndEvent("Page12", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Page13");
		});

	Renderer->CreateAnimation("Page13", "Page13", PAGEDUR, 1, 23, false);
	Renderer->SetEndEvent("Page13", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Page14");
		});

	Renderer->CreateAnimation("Page14", "Page14", PAGEDUR, 1, 23, false);
	Renderer->SetEndEvent("Page14", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Page15");
		});

	Renderer->CreateAnimation("Page15", "Page15", PAGEDUR, 1, 23, false);
	Renderer->SetEndEvent("Page15", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Page16");
		});

	Renderer->CreateAnimation("Page16", "Page16", PAGEDUR, 1, 23, false);
	Renderer->SetEndEvent("Page16", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Page17");
		});

	Renderer->CreateAnimation("Page17", "Page17", PAGEDUR, 1, 27, false);
	Renderer->SetEndEvent("Page17", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("TheEnd");
		});

	Renderer->CreateAnimation("TheEnd", "TheEnd", PAGEDUR, 1, 106, false);

	Renderer->ChangeAnimation("Page0");
	Renderer->AutoSpriteSizeOn();
	Renderer->Transform.SetLocalPosition({ 640, -360 });
}

void StoryBook::Update(float _Delta)
{
	ContentActor::Update(_Delta);
}

void StoryBook::SetStoryBook(StoryType _StoryType)
{
	switch (_StoryType)
	{
	case StoryType::None:
		break;
	case StoryType::Intro:
		Renderer->ChangeAnimation("Page0");
		break;
	case StoryType::Outro:
		Renderer->ChangeAnimation("Page12");
		break;
	default:
		break;
	}
}