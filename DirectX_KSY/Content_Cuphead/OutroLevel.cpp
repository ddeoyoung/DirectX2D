#include "PreCompile.h"
#include "OutroLevel.h"

#include "StoryBook.h"

OutroLevel::OutroLevel()
{
}

OutroLevel::~OutroLevel()
{
}

void OutroLevel::Start()
{

}

void OutroLevel::Update(float _Delta)
{

}

void OutroLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	Storybook = CreateActor<StoryBook>();
}

void OutroLevel::LevelEnd(GameEngineLevel* _NextLevel)
{

}