#include "PreCompile.h"
#include "CigarFire.h"

CigarFire::CigarFire()
{
}

CigarFire::~CigarFire()
{
}


void CigarFire::Start()
{
	ContentActor::Start();

	if (nullptr == GameEngineSprite::Find("CigarFire_Back"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\MrWheezy\\StageObject\\CigarFire");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	//MainRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::Frontground);
	//MainRenderer->CreateAnimation("CigarFire_Back", "CigarFire_Back");
	//MainRenderer->CreateAnimation("CigarFire_Front", "CigarFire_Front");
	//MainRenderer->CreateAnimation("CigarFire_Middle", "CigarFire_Middle");
	//MainRenderer->ChangeAnimation("CigarFire_Front");
	//MainRenderer->AutoSpriteSizeOn();
	//MainRenderer->SetPivotType(PivotType::Bottom);
	//MainRenderer->Transform.SetLocalPosition({ 640.0f , -700.0f });
}

void CigarFire::Update(float _Delta)
{
	ContentActor::Update(_Delta);
}

void CigarFire::SetFireTypeAndPos(const std::string& _Type, float4 _Pos, int _Order)
{
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>(_Order);
	std::string Name = "CigarFire_" + _Type;
	MainRenderer->CreateAnimation(Name, Name);
	MainRenderer->ChangeAnimation(Name);
	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetPivotType(PivotType::Bottom);
	MainRenderer->Transform.SetLocalPosition(_Pos);
}