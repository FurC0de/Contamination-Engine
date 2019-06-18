#include "fileUtilities.h"

std::string CNE::Utilities::LoadFileASCII(std::string path)
{
	std::ifstream t(path);
	t.seekg(0, std::ios::end);
	size_t size = t.tellg();
	std::string buffer(size, ' ');
	t.seekg(0);
	t.read(&buffer[0], size);
	return buffer;
}

std::string* CNE::Utilities::LoadFileUTF8(std::string path)
{
	std::ios::sync_with_stdio(false);

	std::locale loc(""); // You can also use "" for the default system locale

	std::wfstream file(path);
	file.imbue(loc); // Use it for file input
	std::wstring str;
	std::getline(file, str); // str.size() will be 6
	return &WStringToString(str);
}

std::wstring CNE::Utilities::StringToWString(const std::string& str)
{
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;

	return converterX.from_bytes(str);
}

std::string CNE::Utilities::WStringToString(const std::wstring& wstr)
{
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;

	return converterX.to_bytes(wstr);
}