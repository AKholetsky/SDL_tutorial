@echo off
echo started

set scriptsDir=%~dp0
echo %scriptsDir%
cd /d %scriptsDir%
 
:: uncomment the line below line to debug the vcvars
:: set VSCMD_DEBUG=1
:: call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x64
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" x64
 
set path=%scriptsDir%;%path%
 
:: Add dependencies to our include and lib paths (used by cl.exe)
set INCLUDE=%scriptsDir%..\SDL2\include;%INCLUDE%
set LIB=%scriptsDir%..\SDL2\lib\x64;%LIB%

echo ended