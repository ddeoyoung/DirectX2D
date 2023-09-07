#pragma once

// Ό³Έν :
class PhearLapLevel
{
public:
	// constrcuter destructer
	PhearLapLevel();
	~PhearLapLevel();

	// delete Function
	PhearLapLevel(const PhearLapLevel& _Other) = delete;
	PhearLapLevel(PhearLapLevel&& _Other) noexcept = delete;
	PhearLapLevel& operator=(const PhearLapLevel& _Other) = delete;
	PhearLapLevel& operator=(PhearLapLevel&& _Other) noexcept = delete;

protected:

private:

};

