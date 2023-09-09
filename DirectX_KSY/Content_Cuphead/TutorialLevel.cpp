#include "PreCompile.h"
#include "TutorialLevel.h"

#include "TutorialMap.h"
#include "BaseCharacter.h"
#include "Cuphead.h"

TutorialLevel::TutorialLevel()
{
}

TutorialLevel::~TutorialLevel()
{
}

void TutorialLevel::Start()
{
	ContentLevel::Start();
}

void TutorialLevel::Update(float _Delta)
{
	ContentLevel::Update(_Delta);
}

void TutorialLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	Back = CreateActor<TutorialMap>();
	//Player = CreateActor<Cuphead>();
}

void TutorialLevel::LevelEnd(GameEngineLevel* _NextLevel)
{

}