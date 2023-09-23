#pragma once
#include <GameEngineCore\GameEngineActor.h>

// Ό³Έν :
class ChipsBettigan : public GameEngineActor
{
public:
	// constrcuter destructer
	ChipsBettigan();
	~ChipsBettigan();

	// delete Function
	ChipsBettigan(const ChipsBettigan& _Other) = delete;
	ChipsBettigan(ChipsBettigan&& _Other) noexcept = delete;
	ChipsBettigan& operator=(const ChipsBettigan& _Other) = delete;
	ChipsBettigan& operator=(ChipsBettigan&& _Other) noexcept = delete;

protected:

private:

};

