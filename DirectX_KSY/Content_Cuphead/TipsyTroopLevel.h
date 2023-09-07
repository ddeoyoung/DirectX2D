#pragma once

// Ό³Έν :
class TipsyTroopLevel
{
public:
	// constrcuter destructer
	TipsyTroopLevel();
	~TipsyTroopLevel();

	// delete Function
	TipsyTroopLevel(const TipsyTroopLevel& _Other) = delete;
	TipsyTroopLevel(TipsyTroopLevel&& _Other) noexcept = delete;
	TipsyTroopLevel& operator=(const TipsyTroopLevel& _Other) = delete;
	TipsyTroopLevel& operator=(TipsyTroopLevel&& _Other) noexcept = delete;

protected:

private:

};

