#include "PreCompile.h"
#include "OutroLevel.h"

#include "StoryBook.h"
#include "FadeAnimation.h"

OutroLevel::OutroLevel()
{
}

OutroLevel::~OutroLevel()
{
}

void OutroLevel::Start()
{
	ContentLevel::Start();
}

void OutroLevel::Update(float _Delta)
{
	ContentLevel::Update(_Delta);

	bool CheckStoryEnd = Storybook->GetIsStoryEnd();
	if (true == CheckStoryEnd)
	{
		FadeOutTime += _Delta;
		if (FadeOutTime > 2.0f)
		{
			FadeOut->On();
		}
	}

	// End Game
	if (true == FadeOut->IsCurAnimationEnd())
	{
		GameEngineWindow::WindowLoopOff();
	}
}

void OutroLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	ContentLevel::LevelStart(_PrevLevel);

	if (nullptr == Storybook)
	{
		Storybook = CreateActor<StoryBook>();
		Storybook->SetStoryBook(StoryType::Outro);
	}

	if (nullptr == FadeOut)
	{
		FadeOut = CreateActor<FadeAnimation>();
		FadeOut->SetFade("Out");
		FadeOut->Off();
	}
}

void OutroLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
}