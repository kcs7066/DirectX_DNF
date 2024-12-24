#pragma once
#include <vector>
#include "EnginePath.h"
 
class UEngineDirectory : public UEnginePath
{
public:

	ENGINEAPI UEngineDirectory();
	ENGINEAPI UEngineDirectory(std::string_view _Path);
	ENGINEAPI UEngineDirectory(std::filesystem::path _Path);
	ENGINEAPI ~UEngineDirectory();

	ENGINEAPI std::vector<class UEngineFile> GetAllFile(bool _IsRecursive, std::vector<std::string> _Exts);

	ENGINEAPI std::vector<class UEngineDirectory> GetAllDirectory();

	ENGINEAPI UEngineFile GetFile(std::string_view _FileName);

protected:

private:
	void GetAllFileRecursive(std::filesystem::path _Path, std::vector<class UEngineFile>& _Result);

};

