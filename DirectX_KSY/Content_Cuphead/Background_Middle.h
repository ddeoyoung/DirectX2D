#pragma once

// Ό³Έν :
class Background_Middle
{
public:
	// constrcuter destructer
	Background_Middle();
	~Background_Middle();

	// delete Function
	Background_Middle(const Background_Middle& _Other) = delete;
	Background_Middle(Background_Middle&& _Other) noexcept = delete;
	Background_Middle& operator=(const Background_Middle& _Other) = delete;
	Background_Middle& operator=(Background_Middle&& _Other) noexcept = delete;

protected:

private:

};

