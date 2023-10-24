#include "PreCompile.h"
#include "KingDiceLevel.h"

#include "ContentBackground.h"
#include "BaseCharacter.h"
#include "Cuphead.h"
#include "KingDice.h"
#include "Marker.h"

#include "FadeAnimation.h"

KingDiceLevel::KingDiceLevel()
{
}

KingDiceLevel::~KingDiceLevel()
{
}

void KingDiceLevel::Start()
{
	ContentLevel::Start();
}

void KingDiceLevel::Update(float _Delta)
{
	ContentLevel::Update(_Delta);
}

void KingDiceLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	ContentLevel::LevelStart(_PrevLevel);

	LevelStartTextureLoad();
	LevelStartTextureSet();

	// Marker
	Roulette_Marker = CreateActor<Marker>();
	
	// Boss
	Boss = CreateActor<KingDice>();

	// Player
	CurLevelPlayer = CreateActor<Cuphead>();
	CurLevelPlayer->Transform.SetLocalPosition({ 250, -550 });
}

void KingDiceLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
}