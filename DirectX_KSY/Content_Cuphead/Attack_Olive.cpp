#include "PreCompile.h"
#include "Attack_Olive.h"

Attack_Olive::Attack_Olive()
{
}

Attack_Olive::~Attack_Olive()
{
}

void Attack_Olive::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Olive_Idle"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\TipsyTroop\\Boss\\Martini\\Martini_Attack\\Olive");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();

	MainRenderer->CreateAnimation("Olive_Appear", "Olive_Appear", false);
	MainRenderer->SetEndEvent("Olive_Appear", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Olive_Idle");
		});
	MainRenderer->CreateAnimation("Olive_Idle", "Olive_Idle");
	MainRenderer->CreateAnimation("Olive_Attack", "Olive_Attack");
	MainRenderer->CreateAnimation("Olive_Death", "Olive_Death");

	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetPivotType(PivotType::Bottom);
}

void Attack_Olive::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	StateUpdate(_Delta);
}

void Attack_Olive::ChangeState(OliveState _State)
{

}

void Attack_Olive::StateUpdate(float _Delta)
{

}

void Attack_Olive::ChangeAnimationState(const std::string& _StateName)
{

}

void Attack_Olive::AppearStart(){ }
void Attack_Olive::AppearUpdate(float _Delta){ }

void Attack_Olive::IdleStart()
{

}

void Attack_Olive::IdleUpdate(float _Delta)
{

}

void Attack_Olive::AttackStart()
{

}

void Attack_Olive::AttackUpdate(float _Delta)
{

}

void Attack_Olive::DeathStart()
{

}

void Attack_Olive::DeathUpdate(float _Delta)
{

}