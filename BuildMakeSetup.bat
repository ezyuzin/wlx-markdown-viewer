:: This script creates a release (setup) package using a prebuilt project.
@echo off
setlocal

rmdir /S /Q ReleaseWLX
mkdir ReleaseWLX
xcopy /s Build\ ReleaseWLX\
mkdir ReleaseWLX\doc
copy Readme.md ReleaseWLX\doc\

SET VCINSTALLDIR=d:\Program Files\Microsoft Visual Studio\2022\Professional
SET PATH=%PATH%;%VCINSTALLDIR%\MSBuild\Current\Bin

rmdir /S /Q bin\Release\
call "%VCINSTALLDIR%\VC\Auxiliary\Build\vcvars32.bat"
MSBUILD MarkdownView.sln /t:Build /p:Configuration=Release;Platform=Win32

rmdir /S /Q bin\Release\net8.0
del /Q bin\Release\*.lib
del /Q bin\Release\*.deps.json
del /Q bin\Release\*.pdb
del /Q bin\Release\*.exp
xcopy /s bin\Release\ ReleaseWLX\

call "%VCINSTALLDIR%\VC\Auxiliary\Build\vcvars64.bat"
msbuild MarkdownView.sln /t:Build /p:Configuration=Release;Platform=x64

rmdir /S /Q bin\Release\net8.0
del /Q bin\Release\*.lib
del /Q bin\Release\*.deps.json
del /Q bin\Release\*.pdb
del /Q bin\Release\*.exp
xcopy /S /Y bin\Release\ ReleaseWLX\

del /Q Release-*.zip
powershell.exe -nologo -noprofile -command "& { Add-Type -A 'System.IO.Compression.FileSystem'; [IO.Compression.ZipFile]::CreateFromDirectory('ReleaseWLX', 'Release-' + (get-date -Format yyyyMMdd) +'.zip'); }"

:end
