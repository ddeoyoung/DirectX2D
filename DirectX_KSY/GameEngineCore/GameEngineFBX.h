#pragma once

// Ό³Έν :
class GameEngineFBX
{
public:
	// constrcuter destructer
	GameEngineFBX();
	~GameEngineFBX();

	// delete Function
	GameEngineFBX(const GameEngineFBX& _Other) = delete;
	GameEngineFBX(GameEngineFBX&& _Other) noexcept = delete;
	GameEngineFBX& operator=(const GameEngineFBX& _Other) = delete;
	GameEngineFBX& operator=(GameEngineFBX&& _Other) noexcept = delete;

protected:

private:

};

