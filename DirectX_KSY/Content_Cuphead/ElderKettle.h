#pragma once

enum class ElderKettleState
{
	None,
	Idle,
	PopOut,
};

// Ό³Έν :
class ElderKettle : public ContentActor
{
public:
	// constrcuter destructer
	ElderKettle();
	~ElderKettle();

	// delete Function
	ElderKettle(const ElderKettle& _Other) = delete;
	ElderKettle(ElderKettle&& _Other) noexcept = delete;
	ElderKettle& operator=(const ElderKettle& _Other) = delete;
	ElderKettle& operator=(ElderKettle&& _Other) noexcept = delete;

protected:
	void ChangeState(ElderKettleState _State);
	void StateUpdate(float _Delta);
	void ChangeAnimationState(const std::string& _StateName);

	void IdleStart();
	void IdleUpdate(float _Delta);

	void PopOutStart();
	void PopOutUpdate(float _Delta);

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::string CurState = "";
	ElderKettleState State = ElderKettleState::None;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
	std::shared_ptr<class GameEngineCollision> NPCCollision = nullptr;

};
