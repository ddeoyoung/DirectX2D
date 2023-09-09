#include "PreCompile.h"
#include "PlayLevel.h"

#include "KingDiceBackground.h"
#include "KingDiceTable.h"
#include "BaseCharacter.h"
#include "Cuphead.h"

#include "BaseWeapon.h"
#include "PeaShot.h"

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
	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	// Background
	std::shared_ptr<KingDiceBackground> Background = CreateActor<KingDiceBackground>();
	std::shared_ptr<KingDiceTable> Table = CreateActor<KingDiceTable>();

	// Player
	std::shared_ptr<BaseCharacter> Player = CreateActor<Cuphead>();
	Player->Transform.SetLocalPosition({ 250, -550});

	//std::shared_ptr<BaseWeapon> Weapon = CreateActor<PeaShot>();
}

void PlayLevel::LevelEnd(GameEngineLevel* _NextLevel)
{

}