#pragma once

enum class ShaderType
{
	None = 0, // �Ǿտ� None�� �־��ִ� ����� ������ üũ�Ϸ��� ������� ���� ����.
	Vertex, // �ʼ�
	Hull,
	Tessellator,
	Domain,
	Geometry,
	Pixel, // �ʼ�
	Max, // max�� for�������ų� �Ҷ� �ʿ��ϴϱ�.
};

// ���� :
class GameEngineShader
{
public:
	// constrcuter destructer
	GameEngineShader();
	~GameEngineShader();

	// delete Function
	GameEngineShader(const GameEngineShader& _Other) = delete;
	GameEngineShader(GameEngineShader&& _Other) noexcept = delete;
	GameEngineShader& operator=(const GameEngineShader& _Other) = delete;
	GameEngineShader& operator=(GameEngineShader&& _Other) noexcept = delete;

protected:

private:
	ShaderType ShaderTypeValue = ShaderType::None;
};

