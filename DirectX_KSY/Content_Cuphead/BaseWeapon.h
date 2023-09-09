#pragma once
#include <GameEngineCore\GameEngineActor.h>

// Ό³Έν :
class BaseWeapon : public GameEngineActor
{
public:
	// constrcuter destructer
	BaseWeapon();
	~BaseWeapon();

	// delete Function
	BaseWeapon(const BaseWeapon& _Other) = delete;
	BaseWeapon(BaseWeapon&& _Other) noexcept = delete;
	BaseWeapon& operator=(const BaseWeapon& _Other) = delete;
	BaseWeapon& operator=(BaseWeapon&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;

private:
};

