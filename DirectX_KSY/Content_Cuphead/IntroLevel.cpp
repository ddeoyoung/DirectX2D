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

}

void IntroLevel::Update(float _Delta)
{

}

void IntroLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	Storybook = CreateActor<StoryBook>();
}

void IntroLevel::LevelEnd(GameEngineLevel* _NextLevel)
{

}