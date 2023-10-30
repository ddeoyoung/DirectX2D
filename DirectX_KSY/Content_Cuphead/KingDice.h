#pragma once
#include <GameEngineCore\GameEngineActor.h>

enum class KingDiceState 
{
	None,
	IntroHand,
	IntroBody,
	Idle,
	Wink,
	Curious,
	Reveal,
	CameraEat,
	Death,
};

// Ό³Έν :
class KingDice : public ContentActor
{
public:
	// constrcuter destructer
	KingDice();
	~KingDice();

	// delete Function
	KingDice(const KingDice& _Other) = delete;
	KingDice(KingDice&& _Other) noexcept = delete;
	KingDice& operator=(const KingDice& _Other) = delete;
	KingDice& operator=(KingDice&& _Other) noexcept = delete;

	std::string GetCurState()
	{
		return CurState;
	}

	void SetCurState(std::string _CurState)
	{
		CurState = _CurState;
	}

	void SetState(KingDiceState _State)
	{
		State = _State;
	}

	std::shared_ptr<class GameEngineSpriteRenderer> GetHeadRender()
	{
		return HeadRenderer;
	}

	bool IsBossAnimationEnd()
	{
		return MainRenderer->IsCurAnimationEnd();
	}

	void ChangeState(KingDiceState _State);

	void SetLevelChange()
	{
		IsLevelChange = true;
	}

	void SetLevelChange(bool _bool)
	{
		IsLevelChange = _bool;
	}

	bool GetLevelChange()
	{
		return IsLevelChange;
	}


protected:
	void StateUpdate(float _Delta);
	void ChangeAnimationState(const std::string& _StateName);

	void IntroHandStart();
	void IntroHandUpdate(float _Delta);

	void IntroBodyStart();
	void IntroBodyUpdate(float _Delta);

	void IdleStart();
	void IdleUpdate(float _Delta);

	void WinkStart();
	void WinkUpdate(float _Delta);

	void CuriousStart();
	void CuriousUpdate(float _Delta);

	void RevealStart();
	void RevealUpdate(float _Delta);

	void CameraEatStart();
	void CameraEatUpdate(float _Delta);

	void DeathStart();
	void DeathUpdate(float _Delta);

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::string CurState = "";
	KingDiceState State = KingDiceState::None;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
	std::shared_ptr<class GameEngineSpriteRenderer> HeadRenderer = nullptr;

	std::shared_ptr<class Dice> PinkDice = nullptr;

private:
	float IdleTimer = 0.0f;
	float CuriousTimer = 0.0f;
	float ShowDiceTimer = 0.0f;

	bool IsDiceOn = false;
	bool IsLevelChange = false;
};

