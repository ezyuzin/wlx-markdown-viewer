#include <Windows.h>
#include <msclr\auto_gcroot.h>

#define MAKEDLL TRUE
#include "markdown.h"

using namespace System::Runtime::InteropServices;

Markdown::Markdown() {
}

std::string __stdcall Markdown::Convert(std::string content) {
	System::String^ source = gcnew System::String(content.c_str());
	Markdig::MarkdownPipeline^ pipeline = nullptr;
	Markdig::MarkdownParserContext^ context = nullptr;

	System::String^ result = Markdig::Markdown::ToHtml(source, pipeline, context);
	System::IntPtr html = Marshal::StringToHGlobalAnsi(result);
	try {
		return std::string((char*)html.ToPointer());
	}
	finally {
		Marshal::FreeHGlobal(html);
	}
}

Markdown::~Markdown() {}
