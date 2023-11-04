#pragma once

enum class OverWorldCharacterState
{
	None,
	Idle,
	Walk,
	Win,
};

enum class OverWorldCharacterDir
{
	None,
	Left,
	Right,
	Up,
	Down,
	Left_Diagonal_Up,
	Left_Diagonal_Down,
	Right_Diagonal_Up,
	Right_Diagonal_Down,
};

// Ό³Έν :
class OverWorldCharacter : public ContentActor
{
public:
	// constrcuter destructer
	OverWorldCharacter();
	~OverWorldCharacter();

	// delete Function
	OverWorldCharacter(const OverWorldCharacter& _Other) = delete;
	OverWorldCharacter(OverWorldCharacter&& _Other) noexcept = delete;
	OverWorldCharacter& operator=(const OverWorldCharacter& _Other) = delete;
	OverWorldCharacter& operator=(OverWorldCharacter&& _Other) noexcept = delete;

protected:
	void ChangeState(OverWorldCharacterState _State);
	void StateUpdate(float _Delta);
	virtual void ChangeAnimationState(const std::string& _StateName);

	void IdleStart();
	void IdleUpdate(float _Delta);

	void WalkStart();
	void WalkUpdate(float _Delta);

	void WinStart();
	void WinUpdate(float _Delta);

	std::string CurState = "";
	OverWorldCharacterState State = OverWorldCharacterState::None;
	OverWorldCharacterDir Dir = OverWorldCharacterDir::None;

protected:
	void Start() override;
	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
	std::shared_ptr<class GameEngineCollision> PlayerCollision = nullptr;


	void DirCheck();


private:

};

