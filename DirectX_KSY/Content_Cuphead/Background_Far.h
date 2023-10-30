#pragma once

// Ό³Έν :
class Background_Far
{
public:
	// constrcuter destructer
	Background_Far();
	~Background_Far();

	// delete Function
	Background_Far(const Background_Far& _Other) = delete;
	Background_Far(Background_Far&& _Other) noexcept = delete;
	Background_Far& operator=(const Background_Far& _Other) = delete;
	Background_Far& operator=(Background_Far&& _Other) noexcept = delete;

protected:

private:

};

