#pragma once
#include "BaseWeapon.h"

// Ό³Έν :
class PeaShot : public BaseWeapon
{
public:
	// constrcuter destructer
	PeaShot();
	~PeaShot();

	// delete Function
	PeaShot(const PeaShot& _Other) = delete;
	PeaShot(PeaShot&& _Other) noexcept = delete;
	PeaShot& operator=(const PeaShot& _Other) = delete;
	PeaShot& operator=(PeaShot&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:

};

