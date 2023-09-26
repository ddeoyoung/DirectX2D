#pragma once

// Ό³Έν :
class Scotch
{
public:
	// constrcuter destructer
	Scotch();
	~Scotch();

	// delete Function
	Scotch(const Scotch& _Other) = delete;
	Scotch(Scotch&& _Other) noexcept = delete;
	Scotch& operator=(const Scotch& _Other) = delete;
	Scotch& operator=(Scotch&& _Other) noexcept = delete;

protected:

private:

};

