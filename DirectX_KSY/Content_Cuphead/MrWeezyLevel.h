#pragma once

// Ό³Έν :
class MrWeezyLevel
{
public:
	// constrcuter destructer
	MrWeezyLevel();
	~MrWeezyLevel();

	// delete Function
	MrWeezyLevel(const MrWeezyLevel& _Other) = delete;
	MrWeezyLevel(MrWeezyLevel&& _Other) noexcept = delete;
	MrWeezyLevel& operator=(const MrWeezyLevel& _Other) = delete;
	MrWeezyLevel& operator=(MrWeezyLevel&& _Other) noexcept = delete;

protected:

private:

};

