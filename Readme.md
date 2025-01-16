# WLX Markdown Viewer

HTML + Markdown lister plugin for Total Commander (32/64-bit version)

Based on [wlx-markdown-viewer plugin](https://github.com/rg-software/wlx-markdown-viewer), 
and upgraded for displays Markdown files via [Markdig Markdown Processor](https://github.com/xoofx/markdig), which support modern markdown syntax.

Markdown rendering should work reliably for UTF-8 and UTF-16 encoded files (file format is detected with [text-encoding-detect](https://github.com/AutoItConsulting/text-encoding-detect)). For other encodings, Internet Explorer-based autodetection is used, so results may vary.

[Markdig Markdown Processor](https://github.com/xoofx/markdig) is dotnet library, so dotnet core 8.0 is required to be installed.

## Fine Tuning

Plugin configuration is specified in `MarkdownView.ini`. Markdown-related settings are:

* `MarkdownExtensions`: file extensions recognized by the plugin as markdown files.
* `CustomCSS`: a path to a CSS sheet for customizing the resulting look of the document. A collection of four sheets from [Markdown CSS](https://markdowncss.github.io/) and six Github-inspired sheets courtesy of S.&nbsp;Kuznetsov is included into the package.

## Internet Explorer Update

The plugin is based on an obsolete Internet Explorer engine, which can be upgraded via [registry hacks](https://github.com/rg-software/wlx-markdown-viewer/raw/master/ie_upgrade_registry.zip) (check [MSDN](https://learn.microsoft.com/en-us/previous-versions/windows/internet-explorer/ie-developer/general-info/ee330730(v=vs.85)?redirectedfrom=MSDN#browser-emulation) for details.)

## Setup

The binary plugin archive comes with the setup script. Just enter the archive, and confirm installation.
