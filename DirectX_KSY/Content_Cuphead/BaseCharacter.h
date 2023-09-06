#pragma once
#include <GameEngineCore\GameEngineActor.h>

// Ό³Έν :
class BaseCharacter : public GameEngineActor
{
public:
	// constrcuter destructer
	BaseCharacter();
	~BaseCharacter();

	// delete Function
	BaseCharacter(const BaseCharacter& _Other) = delete;
	BaseCharacter(BaseCharacter&& _Other) noexcept = delete;
	BaseCharacter& operator=(const BaseCharacter& _Other) = delete;
	BaseCharacter& operator=(BaseCharacter&& _Other) noexcept = delete;

protected:
	void ChangeState(CharacterState _State);
	void StateUpdate(float _Delta);
	virtual void ChangeAnimationState(const std::string& _StateName);

	void IdleStart();
	void IdleUpdate(float _Delta);

	void RunStart();
	void RunUpdate(float _Delta);

	void AimStart();
	void AimUpdate(float _Delta);

	void ShootStart();
	void ShootUpdate(float _Delta);

	void DuckStart();
	void DuckUpdate(float _Delta);

	void DuckIdleStart();
	void DuckIdleUpdate(float _Delta);

	void DuckShootStart();
	void DuckShootUpdate(float _Delta);

	void HitStart();
	void HitUpdate(float _Delta);

	void DashStart();
	void DashUpdate(float _Delta);

	void JumpStart();
	void JumpUpdate(float _Delta);

	void ParryStart();
	void ParryUpdate(float _Delta);

	void IntroStart();
	void IntroUpdate(float _Delta);

	void GhostStart();
	void GhostUpdate(float _Delta);

	void DeathStart();
	void DeathUpdate(float _Delta);

protected:
	void Start() override;
	void Update(float _Delta) override;

	void DirCheck();

	ActorDir Dir = ActorDir::None;
	CharacterState State = CharacterState::None;
	std::string CurState = "";
	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;

private:
};

