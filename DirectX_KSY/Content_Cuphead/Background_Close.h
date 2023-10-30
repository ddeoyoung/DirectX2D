#pragma once

// Ό³Έν :
class Background_Close
{
public:
	// constrcuter destructer
	Background_Close();
	~Background_Close();

	// delete Function
	Background_Close(const Background_Close& _Other) = delete;
	Background_Close(Background_Close&& _Other) noexcept = delete;
	Background_Close& operator=(const Background_Close& _Other) = delete;
	Background_Close& operator=(Background_Close&& _Other) noexcept = delete;

protected:

private:

};

