#pragma once
#include "GameEnginePath.h"
#include "GameEngineSerializer.h"
#include <string>

// Ostream Istream

enum class FileOpenType
{
	Write,
	Read,
};

enum class FileDataType
{
	Binary,
	Text,
};

// 설명 :
class GameEngineFile : public GameEnginePath
{
public:
	// constrcuter destructer
	GameEngineFile();
	GameEngineFile(const std::string& _path);
	~GameEngineFile();

	//// delete Function
	//GameEngineFile(const GameEngineFile& _Other) = delete;
	//GameEngineFile(GameEngineFile&& _Other) noexcept = delete;
	//GameEngineFile& operator=(const GameEngineFile& _Other) = delete;
	//GameEngineFile& operator=(GameEngineFile&& _Other) noexcept = delete;

	void Open(FileOpenType _OpenType, FileDataType _DataType, bool _IsStartAllData = true);

	void Read(void* _Data, size_t _Size);

	void Write(void* _Data, size_t _Size);

	// 8바이트 정수형
	template<typename ReturnType>
	ReturnType GetFileSize()
	{
		return static_cast<ReturnType>(GetFileSize());
	}

	uintmax_t GetFileSize();

	std::string_view GetStringView();

protected:

private:
	FILE* FilePtr = nullptr;
	FileOpenType OpenType;
	FileDataType DataType;
	GameEngineSerializer Serializer;
};


