#pragma once

// ���� :
class TopSmoke
{
public:
	// constrcuter destructer
	TopSmoke();
	~TopSmoke();

	// delete Function
	TopSmoke(const TopSmoke& _Other) = delete;
	TopSmoke(TopSmoke&& _Other) noexcept = delete;
	TopSmoke& operator=(const TopSmoke& _Other) = delete;
	TopSmoke& operator=(TopSmoke&& _Other) noexcept = delete;

protected:

private:

};

