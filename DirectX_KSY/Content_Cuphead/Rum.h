#pragma once
#include <GameEngineCore\GameEngineActor.h>

// Ό³Έν :
class Rum : public GameEngineActor
{
public:
	// constrcuter destructer
	Rum();
	~Rum();

	// delete Function
	Rum(const Rum& _Other) = delete;
	Rum(Rum&& _Other) noexcept = delete;
	Rum& operator=(const Rum& _Other) = delete;
	Rum& operator=(Rum&& _Other) noexcept = delete;

protected:

private:

};

