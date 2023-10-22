#pragma once

enum class DiceState
{
	None,
	Idle,
	Hit,
	Death,
};


// Ό³Έν :
class Dice : public ContentActor
{
public:
	// constrcuter destructer
	Dice();
	~Dice();

	// delete Function
	Dice(const Dice& _Other) = delete;
	Dice(Dice&& _Other) noexcept = delete;
	Dice& operator=(const Dice& _Other) = delete;
	Dice& operator=(Dice&& _Other) noexcept = delete;

	static int DiceCount;
	static bool IsHit;

protected:
	void ChangeState(DiceState _State);
	void StateUpdate(float _Delta);
	void ChangeAnimationState(const std::string& _StateName);

	void IdleStart();
	void IdleUpdate(float _Delta);

	void HitStart();
	void HitUpdate(float _Delta);

	void DeathStart();
	void DeathUpdate(float _Delta);

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
	std::shared_ptr<class GameEngineCollision> ParryCollision = nullptr;

	std::string CurState = "";
	DiceState State = DiceState::None;


private:
	float IdleTimer = 0.0f;
	float HitTimer = 0.0f;
	//bool IsHit = false;
	//int DiceCount = 0;
};

