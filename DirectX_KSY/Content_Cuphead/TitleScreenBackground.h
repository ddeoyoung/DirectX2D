#pragma once

// Ό³Έν :
class TitleScreenBackground
{
public:
	// constrcuter destructer
	TitleScreenBackground();
	~TitleScreenBackground();

	// delete Function
	TitleScreenBackground(const TitleScreenBackground& _Other) = delete;
	TitleScreenBackground(TitleScreenBackground&& _Other) noexcept = delete;
	TitleScreenBackground& operator=(const TitleScreenBackground& _Other) = delete;
	TitleScreenBackground& operator=(TitleScreenBackground&& _Other) noexcept = delete;

protected:

private:

};

