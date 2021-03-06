/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#ifndef COB_FILE_H
#define COB_FILE_H

#include <vector>
#include <string>

#include "Lua/LuaHashString.h"
#include "CobScriptNames.h"
#include "System/UnorderedMap.hpp"

class CFileHandler;

class CCobFile
{
public:
	CCobFile(CFileHandler& in, std::string name);
	~CCobFile();

	int GetFunctionId(const std::string& name);


	std::vector<std::string> scriptNames;
	std::vector<int> scriptOffsets;
	/// Assumes that the scripts are sorted by offset in the file
	std::vector<int> scriptLengths;
	std::vector<std::string> pieceNames;
	std::vector<int> scriptIndex;
	std::vector<int> sounds;
	std::vector<LuaHashString> luaScripts;
	spring::unordered_map<std::string, int> scriptMap;
	int* code;
	int numStaticVars;
	std::string name;
};

#endif // COB_FILE_H
