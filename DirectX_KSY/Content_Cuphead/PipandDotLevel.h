#pragma once

// Ό³Έν :
class PipandDotLevel
{
public:
	// constrcuter destructer
	PipandDotLevel();
	~PipandDotLevel();

	// delete Function
	PipandDotLevel(const PipandDotLevel& _Other) = delete;
	PipandDotLevel(PipandDotLevel&& _Other) noexcept = delete;
	PipandDotLevel& operator=(const PipandDotLevel& _Other) = delete;
	PipandDotLevel& operator=(PipandDotLevel&& _Other) noexcept = delete;

protected:

private:

};

