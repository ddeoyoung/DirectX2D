#pragma once
#include <GameEngineCore\GameEngineActor.h>

// Ό³Έν :
class KingDice : public GameEngineActor
{
public:
	// constrcuter destructer
	KingDice();
	~KingDice();

	// delete Function
	KingDice(const KingDice& _Other) = delete;
	KingDice(KingDice&& _Other) noexcept = delete;
	KingDice& operator=(const KingDice& _Other) = delete;
	KingDice& operator=(KingDice&& _Other) noexcept = delete;

protected:

private:

};

