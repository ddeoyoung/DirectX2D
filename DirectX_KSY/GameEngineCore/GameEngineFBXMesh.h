#pragma once

// Ό³Έν :
class GameEngineFBXMesh
{
public:
	// constrcuter destructer
	GameEngineFBXMesh();
	~GameEngineFBXMesh();

	// delete Function
	GameEngineFBXMesh(const GameEngineFBXMesh& _Other) = delete;
	GameEngineFBXMesh(GameEngineFBXMesh&& _Other) noexcept = delete;
	GameEngineFBXMesh& operator=(const GameEngineFBXMesh& _Other) = delete;
	GameEngineFBXMesh& operator=(GameEngineFBXMesh&& _Other) noexcept = delete;

protected:

private:

};

