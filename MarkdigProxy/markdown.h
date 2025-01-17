#pragma once

#include <string>
#include <iostream>

#ifdef MAKEDLL
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT __declspec(dllimport)
	#if _WIN64
	#pragma comment (lib, "MarkdigProxy-x64.lib")
	#else 
	#pragma comment (lib, "MarkdigProxy.lib")
	#endif
#endif

class EXPORT Markdown {
public:
	Markdown();
	~Markdown();

	std::string __stdcall ConvertToHtmlAscii(
		std::string filename,
		std::string cssFile,
		std::string extensions
	);
};