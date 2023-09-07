#pragma once

// Ό³Έν :
class PiroulettaLevel
{
public:
	// constrcuter destructer
	PiroulettaLevel();
	~PiroulettaLevel();

	// delete Function
	PiroulettaLevel(const PiroulettaLevel& _Other) = delete;
	PiroulettaLevel(PiroulettaLevel&& _Other) noexcept = delete;
	PiroulettaLevel& operator=(const PiroulettaLevel& _Other) = delete;
	PiroulettaLevel& operator=(PiroulettaLevel&& _Other) noexcept = delete;

protected:

private:

};

