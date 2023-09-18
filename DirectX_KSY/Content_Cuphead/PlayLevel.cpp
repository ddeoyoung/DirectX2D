#include "PreCompile.h"
#include "PlayLevel.h"

#include "BaseCharacter.h"
#include "Cuphead.h"

#include "BaseWeapon.h"
#include "Peashot.h"

PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
}

void PlayLevel::Start()
{
	ContentLevel::Start();
}

void PlayLevel::Update(float _Delta)
{
	ContentLevel::Update(_Delta); 
}

void PlayLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	// Player
	std::shared_ptr<BaseCharacter> Player = CreateActor<Cuphead>();
	Player->Transform.SetLocalPosition({ 250, -550});
}

void PlayLevel::LevelEnd(GameEngineLevel* _NextLevel)
{

}