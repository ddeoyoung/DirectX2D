#pragma once
#include <GameEngineCore\GameEngineActor.h>

#define LEFTCHECKPOS { -40.0f, 40.0f }
#define RIGHTCHECKPOS { 40.0f, 40.0f }
#define BOTTOMCHECKPOS { 0.0f, -2.0f }
#define TOPCHECKPOS { 0.0f, 2.0f }

#define RUNSPEED 500.0f
#define GRAVITYFORCE 2500.0f

#define SHOOT_INTERVAL 0.2f

// Ό³Έν :
class BaseCharacter : public ContentActor
{
public:
	static BaseCharacter* MainCharacter;

	// constrcuter destructer
	BaseCharacter();
	~BaseCharacter();

	// delete Function
	BaseCharacter(const BaseCharacter& _Other) = delete;
	BaseCharacter(BaseCharacter&& _Other) noexcept = delete;
	BaseCharacter& operator=(const BaseCharacter& _Other) = delete;
	BaseCharacter& operator=(BaseCharacter&& _Other) noexcept = delete;

	ActorDir GetPlayerDir()
	{
		return Dir;
	}

	AttackDir GetPlayerAttDir()
	{
		return AttDir;
	}

	bool GetIsParry()
	{
		return IsParry;
	}

protected:
	void ChangeState(CharacterState _State);
	void StateUpdate(float _Delta);
	virtual void ChangeAnimationState(const std::string& _StateName);

	void IdleStart();
	void IdleUpdate(float _Delta);

	void RunStart();
	void RunUpdate(float _Delta);

	void RunShootStart();
	void RunShootUpdate(float _Delta);

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

	void FallStart();
	void FallUpdate(float _Delta);

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

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

	void CreateRunDust();
	void CreateJumpDust();
	void CreateDashDust();
	void CreateParrySpark();
	void CreateHitEffect();

	void DirCheck();
	bool AimCheck();
	void GroundCheck();
	bool CollisionCheck();
	void ParryCollisionCheck();
	void Gravity(float _Delta);
	void LerpCamera(float _Delta);
	void PixelCheck(float _Delta);
	GameEngineColor GetPixelColor(float4 _Pos);

	bool IsGround = false;
	bool IsRun = false;
	bool IsRunShoot = false;
	bool IsJump = false;
	bool IsShoot = false;
	bool IsAim = false;
	bool IsParry = false;
	bool IsHit = false;

	ActorDir Dir = ActorDir::None;
	AttackDir AttDir = AttackDir::None;
	CharacterState State = CharacterState::None;

	std::string CurState = "";

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
	std::shared_ptr<class GameEngineCollision> PlayerCollision = nullptr;
	std::shared_ptr<class GameEngineCollision> PlayerParryCollision = nullptr;

	std::shared_ptr<class RunDust> RunEffect = nullptr;
	std::shared_ptr<class JumpDust> JumpEffect = nullptr;
	std::shared_ptr<class DashDust> DashEffect = nullptr;
	std::shared_ptr<class ParrySpark_Character> ParryEffect = nullptr;
	std::shared_ptr<class HitFX> HitEffect = nullptr;

private:
	int DashCount = 0;
	int ParryCount = 0;
	float RunDustTimer = 0.0f;
	float ShootInterval = 0.0f;
	float HitInterval = 0.0f;
	float UnScaleDeltaTime = 0.0f;
	float PauseTimer = 0.0f;

	float4 GravityForce = float4::ZERO;
	float4 JumpPower = float4::ZERO;
	float4 ParryPower = float4::ZERO;
};

