#pragma once
#define WIN32_LEAN_AND_MEAN
#include <msclr\auto_gcroot.h>

#define MAKEDLL TRUE
#include "markdown.h"

using namespace System::Runtime::InteropServices;

static System::String^ MarkdownToHtml(
	System::String^ filename,
	System::String^ cssFile,
	System::String^ extensions
) {

	System::String^ source = System::IO::File::ReadAllText(filename);

	Markdig::MarkdownParserContext^ context = nullptr;
	Markdig::MarkdownPipelineBuilder^ builder = gcnew Markdig::MarkdownPipelineBuilder();
	Markdig::MarkdownExtensions::Configure(builder, extensions);

	System::Text::StringBuilder^ sb = gcnew System::Text::StringBuilder(1000);
	sb->AppendLine("<html><head>");
	sb->AppendLine("<meta charset='utf-8'>");
	sb->AppendLine("<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">");
	sb->Append("<base href=\"file:///")
		->Append(System::IO::Path::GetDirectoryName(filename)->Replace("\\", "/"))
		->AppendLine("/\"/>");

	sb->Append("<style>");
	sb->Append(System::IO::File::ReadAllText(cssFile));
	sb->Append("</style>");
	sb->AppendLine("</head>");
	sb->AppendLine("<body>");
	sb->AppendLine(Markdig::Markdown::ToHtml(source, builder->Build(), context));
	sb->AppendLine("</body>");
	sb->AppendLine("</html>");

	return sb->ToString();
}

Markdown::Markdown() {
}

std::string __stdcall Markdown::ConvertToHtmlAscii(
	std::string filename,
	std::string cssFile,
	std::string extensions
) {
	System::String^ result = MarkdownToHtml(
		gcnew System::String(filename.c_str()),
		gcnew System::String(cssFile.c_str()),
		gcnew System::String(extensions.c_str())
	);

	array<unsigned char>^ data = System::Text::Encoding::UTF8->GetBytes(result);
	pin_ptr<unsigned char> pp = &data[0];

	std::string str((char*)pp, data->Length);
	return str;
}

Markdown::~Markdown() {}
