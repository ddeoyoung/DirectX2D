#pragma once

// Ό³Έν :
class Background_White
{
public:
	// constrcuter destructer
	Background_White();
	~Background_White();

	// delete Function
	Background_White(const Background_White& _Other) = delete;
	Background_White(Background_White&& _Other) noexcept = delete;
	Background_White& operator=(const Background_White& _Other) = delete;
	Background_White& operator=(Background_White&& _Other) noexcept = delete;

protected:

private:

};

