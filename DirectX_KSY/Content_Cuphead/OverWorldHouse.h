#pragma once
#include "Portal.h"

// Ό³Έν :
class OverWorldHouse : public Portal
{
public:
	// constrcuter destructer
	OverWorldHouse();
	~OverWorldHouse();

	// delete Function
	OverWorldHouse(const OverWorldHouse& _Other) = delete;
	OverWorldHouse(OverWorldHouse&& _Other) noexcept = delete;
	OverWorldHouse& operator=(const OverWorldHouse& _Other) = delete;
	OverWorldHouse& operator=(OverWorldHouse&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineCollision> Collision = nullptr;
};

