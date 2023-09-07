#pragma once

// Ό³Έν :
class MrChimesLevel
{
public:
	// constrcuter destructer
	MrChimesLevel();
	~MrChimesLevel();

	// delete Function
	MrChimesLevel(const MrChimesLevel& _Other) = delete;
	MrChimesLevel(MrChimesLevel&& _Other) noexcept = delete;
	MrChimesLevel& operator=(const MrChimesLevel& _Other) = delete;
	MrChimesLevel& operator=(MrChimesLevel&& _Other) noexcept = delete;

protected:

private:

};

