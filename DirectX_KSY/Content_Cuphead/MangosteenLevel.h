#pragma once

// Ό³Έν :
class MangosteenLevel
{
public:
	// constrcuter destructer
	MangosteenLevel();
	~MangosteenLevel();

	// delete Function
	MangosteenLevel(const MangosteenLevel& _Other) = delete;
	MangosteenLevel(MangosteenLevel&& _Other) noexcept = delete;
	MangosteenLevel& operator=(const MangosteenLevel& _Other) = delete;
	MangosteenLevel& operator=(MangosteenLevel&& _Other) noexcept = delete;

protected:

private:

};

