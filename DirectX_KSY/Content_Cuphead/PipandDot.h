#pragma once

// Ό³Έν :
class PipandDot
{
public:
	// constrcuter destructer
	PipandDot();
	~PipandDot();

	// delete Function
	PipandDot(const PipandDot& _Other) = delete;
	PipandDot(PipandDot&& _Other) noexcept = delete;
	PipandDot& operator=(const PipandDot& _Other) = delete;
	PipandDot& operator=(PipandDot&& _Other) noexcept = delete;

protected:

private:

};

