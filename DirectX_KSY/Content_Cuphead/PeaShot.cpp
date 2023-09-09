#include "PreCompile.h"
#include "PeaShot.h"

PeaShot::PeaShot()
{
}

PeaShot::~PeaShot()
{
}

void PeaShot::Start()
{
	BaseWeapon::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Peashot_Spark"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Weapon\\Peashot");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	MainRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::PlayerShoot);

	MainRenderer->CreateAnimation("Peashot_Spark", "Peashot_Spark");
	MainRenderer->CreateAnimation("Peashot_Attack", "Peashot_Attack");
	MainRenderer->CreateAnimation("Peashot_Death", "Peashot_Death");
	MainRenderer->CreateAnimation("Peashot_EX", "Peashot_EX");
	MainRenderer->CreateAnimation("Peashot_EX_Death", "Peashot_EX_Death");

	MainRenderer->ChangeAnimation("Peashot_Attack");
	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->Transform.SetLocalPosition({ 500.0f, -300.0f });
}

void PeaShot::Update(float _Delta)
{

}