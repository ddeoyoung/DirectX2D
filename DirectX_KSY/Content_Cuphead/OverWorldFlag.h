#pragma once
#include "Portal.h"

// Ό³Έν :
class OverWorldFlag : public Portal
{
public:
	// constrcuter destructer
	OverWorldFlag();
	~OverWorldFlag();

	// delete Function
	OverWorldFlag(const OverWorldFlag& _Other) = delete;
	OverWorldFlag(OverWorldFlag&& _Other) noexcept = delete;
	OverWorldFlag& operator=(const OverWorldFlag& _Other) = delete;
	OverWorldFlag& operator=(OverWorldFlag&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineCollision> Collision = nullptr;

	bool IsFlagUp = false;
};

