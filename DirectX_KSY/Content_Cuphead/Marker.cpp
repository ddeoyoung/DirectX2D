#include "PreCompile.h"
#include "Marker.h"
#include "Dice.h"
#include "KingDice.h"

Marker::Marker()
{
}

Marker::~Marker()
{
}

bool Marker::IsSpinEnd = false;

void Marker::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Marker_Idle"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\KingDice\\StageObject\\Marker");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();
	MainRenderer->CreateAnimation("Marker_Idle", "Marker_Idle");
	MainRenderer->CreateAnimation("Marker_Spin", "Marker_Spin", 0.05f);
	MainRenderer->AutoSpriteSizeOn();

	//Transform.SetLocalPosition({ 220, -300 });

	ChangeState(MarkerState::Idle);
	SetRouletteMarker();
	CurRouletteSpace = 0;
	Transform.SetLocalPosition(RouletteSpace[0]);
}

void Marker::Update(float _Delta)
{
	ContentActor::Update(_Delta);
	StateUpdate(_Delta);
}

void Marker::ChangeState(MarkerState _State)
{
	if (_State != State)
	{
		switch (_State)
		{
		case MarkerState::None:
			break;
		case MarkerState::Idle:
			IdleStart();
			break;
		case MarkerState::Spin:
			SpinStart();
			break;
		default:
			break;
		}
	}

	State = _State;
}

void Marker::StateUpdate(float _Delta)
{
	switch (State)
	{
	case MarkerState::None:
		break;
	case MarkerState::Idle:
		return IdleUpdate(_Delta);
	case MarkerState::Spin:
		return SpinUpdate(_Delta);
	default:
		break;
	}
}

void Marker::ChangeAnimationState(const std::string& _StateName)
{
	std::string AnimationName = "Marker_";
	AnimationName += _StateName;

	CurState = _StateName;
	MainRenderer->ChangeAnimation(AnimationName);
}

void Marker::IdleStart()
{
	ChangeAnimationState("Idle");
	IsSpinEnd = false;
}

void Marker::IdleUpdate(float _Delta)
{
	// 시작
	// Dice Hit Check
	if (true == Dice::IsHit && false == IsSpinStart)
	{
		IsSpinStart = true;
		CurCount = 0;
		SpinCount = Dice::DiceCount;
		ChangeState(MarkerState::Spin);
		return;
	}

	// 반복
	if (true == IsSpinStart && CurCount != SpinCount)
	{
		ChangeState(MarkerState::Spin);
		return;
	}

	// 주사위 수만큼 이동 완료
	if (true == IsSpinStart && CurCount == SpinCount)
	{
		// 킹다이스로 리턴해야 할 것들
		IsSpinEnd = true;
	}
}

void Marker::SpinStart()
{
	ChangeAnimationState("Spin");
	CurRouletteSpace += 1;
}

void Marker::SpinUpdate(float _Delta)
{
	float4 MovePos = float4::ZERO;
	float4 StartPos = Transform.GetLocalPosition();
	float4 EndPos = RouletteSpace[CurRouletteSpace];

	MovePos = EndPos - StartPos;

	Transform.AddLocalPosition(MovePos * _Delta * SPINSPEED);

	if (true == MainRenderer->IsCurAnimationEnd())
	{
		CurCount += 1;
		ChangeState(MarkerState::Idle);
		return;
	}
}

void Marker::SetRouletteMarker()
{
	float4 SpaceStart = { 204, -300 };
	float4 Space1 = { 245, -374 };
	float4 Space2 = { 295, -444 };
	float4 Space3 = { 362, -500 };
	float4 SpaceSafe1 = { 437, -540 };
	float4 Space4 = { 516, -568 };
	float4 Space5 = { 600, -580 };
	float4 Space6 = { 678, -584 };
	float4 SpaceSafe2 = { 757, -582 };
	float4 Space7 = { 837, -565 };
	float4 Space8 = { 910, -538 };
	float4 Space9 = { 980, -492 };
	float4 SpaceSafe3 = { 1034, -442 };
	float4 SpaceStartOver = { 1077, -377 };
	float4 SpaceFinish = { 1106, -307 };

	RouletteSpace.clear();
	RouletteSpace.reserve(20);

	RouletteSpace.push_back(SpaceStart);
	RouletteSpace.push_back(Space1);
	RouletteSpace.push_back(Space2);
	RouletteSpace.push_back(Space3);
	RouletteSpace.push_back(SpaceSafe1);
	RouletteSpace.push_back(Space4);
	RouletteSpace.push_back(Space5);
	RouletteSpace.push_back(Space6);
	RouletteSpace.push_back(SpaceSafe2);
	RouletteSpace.push_back(Space7);
	RouletteSpace.push_back(Space8);
	RouletteSpace.push_back(Space9);
	RouletteSpace.push_back(SpaceSafe3);
	RouletteSpace.push_back(SpaceStartOver);
	RouletteSpace.push_back(SpaceFinish);
}

void Marker::MoveMarker(float4 _Delta)
{

}