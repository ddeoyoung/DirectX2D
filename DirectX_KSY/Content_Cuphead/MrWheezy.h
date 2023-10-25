#pragma once

enum class WheezyState
{
	None,
	Intro,
	Idle,
	Death,
};

// Ό³Έν :
class MrWheezy : public ContentActor
{
public:
	// constrcuter destructer
	MrWheezy();
	~MrWheezy();

	// delete Function
	MrWheezy(const MrWheezy& _Other) = delete;
	MrWheezy(MrWheezy&& _Other) noexcept = delete;
	MrWheezy& operator=(const MrWheezy& _Other) = delete;
	MrWheezy& operator=(MrWheezy&& _Other) noexcept = delete;

protected:
	void ChangeState(WheezyState _State);
	void StateUpdate(float _Delta);
	void ChangeAnimationState(const std::string& _StateName);

	void IntroStart();
	void IntroUpdate(float _Delta);

	void IdleStart();
	void IdleUpdate(float _Delta);

	void DeathStart();
	void DeathUpdate(float _Delta);

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::string CurState = "";
	WheezyState State = WheezyState::None;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
	std::shared_ptr<class GameEngineCollision> BossCollision = nullptr;

private:

};

