@echo off
echo started

set buildDir=%~dp0\build
 
if not exist %buildDir% mkdir %buildDir%
 
pushd %buildDir%
 
:: compiler input
set objDir=.\obj\
set outputExe=open_window
set libs=SDL2.lib SDL2main.lib
set files=..\main.cpp
 
:: compiler flags:
:: /Zi enable debugging information
:: /FC use full path in diagnostics
:: /Fo<path> the path to write object files
:: /Fe<path> the path to write the executable file
set compileFlags=/Zi /FC /Fo%objDir% /Fe%outputExe% 
 
:: linker flags:
:: /SUBSYSTEM specifies exe env - defines entry point symbol
set linkFlags=/link /SUBSYSTEM:CONSOLE
 
if not exist %objDir% mkdir %objDir%
 
cl %compileFlags% %files% %libs% %linkFlags%
 
:: Copy dependencies
xcopy /y ..\..\SDL2\lib\x64\SDL2.dll .
 
popd

echo ended build