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
	ContentLevel::Start();
}

void OutroLevel::Update(float _Delta)
{
	ContentLevel::Update(_Delta);
}

void OutroLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	ContentLevel::LevelStart(_PrevLevel);

	Storybook = CreateActor<StoryBook>();
	Storybook->SetStoryBook(StoryType::Outro);
}

void OutroLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
}