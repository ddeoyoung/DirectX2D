#include "PreCompile.h"
#include "IntroLevel.h"

#include "StoryBook.h"

IntroLevel::IntroLevel()
{
}

IntroLevel::~IntroLevel()
{
}

void IntroLevel::Start()
{
	ContentLevel::Start();
}

void IntroLevel::Update(float _Delta)
{
	ContentLevel::Update(_Delta);
}

void IntroLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	ContentLevel::LevelStart(_PrevLevel);

	Storybook = CreateActor<StoryBook>();
	Storybook->SetStoryBook(StoryType::Intro);
}

void IntroLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
}