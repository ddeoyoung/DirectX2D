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
class KingDice : public GameEngineActor
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

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;

protected:
	void ChangeState(KingDiceState _State);
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

private:
	KingDiceState State = KingDiceState::None;
};

