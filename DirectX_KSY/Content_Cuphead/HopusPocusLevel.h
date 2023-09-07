#pragma once

// Ό³Έν :
class HopusPocusLevel
{
public:
	// constrcuter destructer
	HopusPocusLevel();
	~HopusPocusLevel();

	// delete Function
	HopusPocusLevel(const HopusPocusLevel& _Other) = delete;
	HopusPocusLevel(HopusPocusLevel&& _Other) noexcept = delete;
	HopusPocusLevel& operator=(const HopusPocusLevel& _Other) = delete;
	HopusPocusLevel& operator=(HopusPocusLevel&& _Other) noexcept = delete;

protected:

private:

};

