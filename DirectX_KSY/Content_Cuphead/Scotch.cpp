#include "PreCompile.h"
#include "Scotch.h"

Scotch::Scotch()
{
}

Scotch::~Scotch()
{
}

void Scotch::Start()
{
	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Scotch_Idle"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\TipsyTroop\\Boss\\Scotch");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();

	MainRenderer->CreateAnimation("Scotch_Idle", "Scotch_Idle", 0.07f);
	MainRenderer->CreateAnimation("Scotch_Attack", "Scotch_Attack", 0.07f);
	MainRenderer->CreateAnimation("Scotch_Death", "Scotch_Death", 0.05f);
	MainRenderer->ChangeAnimation("Scotch_Death");

	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetPivotType(PivotType::Bottom);

	Transform.SetLocalPosition({ 1150 , -700 });
}

void Scotch::Update(float _Delta)
{

}

void Scotch::ChangeState(ScotchState _State)
{

}

void Scotch::StateUpdate(float _Delta)
{

}

void Scotch::ChangeAnimationState(const std::string& _StateName)
{

}

void Scotch::IdleStart()
{

}

void Scotch::IdleUpdate(float _Delta)
{

}

void Scotch::AttackStart()
{

}

void Scotch::AttackUpdate(float _Delta)
{

}

void Scotch::DeathStart()
{

}

void Scotch::DeathUpdate(float _Delta)
{

}