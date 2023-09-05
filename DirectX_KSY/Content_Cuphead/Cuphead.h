#pragma once
#include "BaseCharacter.h"

// Ό³Έν :
class Cuphead : public BaseCharacter
{
public:
	// constrcuter destructer
	Cuphead();
	~Cuphead();

	// delete Function
	Cuphead(const Cuphead& _Other) = delete;
	Cuphead(Cuphead&& _Other) noexcept = delete;
	Cuphead& operator=(const Cuphead& _Other) = delete;
	Cuphead& operator=(Cuphead&& _Other) noexcept = delete;

protected:
	void ChangeAnimationState(const std::string& _StateName) override;

private:
	void Start() override;
};

