#include <string>
#include <sstream>
#include <fstream>
#include <streambuf>
#include <iostream>
#include <locale>
#include <codecvt>

#ifndef FILE_UTIL_H
#define FILE_UTIL_H

namespace CNE {

	struct Sources_t
	{
		std::string* srcA;
		std::string* srcB;
	};

	namespace Utilities {
		std::string LoadFileASCII(std::string path);
		std::string* LoadFileUTF8(std::string path);
		std::wstring StringToWString(const std::string& str);
		std::string WStringToString(const std::wstring& wstr);
	}
}

#endif