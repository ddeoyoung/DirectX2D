#pragma once

// Ό³Έν :
class CigSmoke
{
public:
	// constrcuter destructer
	CigSmoke();
	~CigSmoke();

	// delete Function
	CigSmoke(const CigSmoke& _Other) = delete;
	CigSmoke(CigSmoke&& _Other) noexcept = delete;
	CigSmoke& operator=(const CigSmoke& _Other) = delete;
	CigSmoke& operator=(CigSmoke&& _Other) noexcept = delete;

protected:

private:

};

