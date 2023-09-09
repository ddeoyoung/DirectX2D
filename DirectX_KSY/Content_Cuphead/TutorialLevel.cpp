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
}

void TutorialLevel::Update(float _Delta)
{

}

void TutorialLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	GetMainCamera()->Transform.SetLocalPosition({ 0.0f, 0.0f, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	Back = CreateActor<TutorialMap>();
	//Player = CreateActor<Cuphead>();
}

void TutorialLevel::LevelEnd(GameEngineLevel* _NextLevel)
{

}