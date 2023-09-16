#pragma once
#include "BaseWeapon.h"

// Ό³Έν :
class Peashot : public BaseWeapon
{
public:
	// constrcuter destructer
	Peashot();
	~Peashot();

	// delete Function
	Peashot(const Peashot& _Other) = delete;
	Peashot(Peashot&& _Other) noexcept = delete;
	Peashot& operator=(const Peashot& _Other) = delete;
	Peashot& operator=(Peashot&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	void ChangeAnimationState(const std::string& _StateName);

private:

};

