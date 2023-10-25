#pragma once

// Ό³Έν :
class MrWheezyLevel
{
public:
	// constrcuter destructer
	MrWheezyLevel();
	~MrWheezyLevel();

	// delete Function
	MrWheezyLevel(const MrWheezyLevel& _Other) = delete;
	MrWheezyLevel(MrWheezyLevel&& _Other) noexcept = delete;
	MrWheezyLevel& operator=(const MrWheezyLevel& _Other) = delete;
	MrWheezyLevel& operator=(MrWheezyLevel&& _Other) noexcept = delete;

protected:

private:

};

