@echo off
 
set buildDir=%~dp0\build
set objDir=.\obj\
set vscodeDir=.\.vscode\
set res=.\images\
 
if exist %buildDir% (  
  pushd %buildDir%
  del /q /s *.exe *.pdb *.ilk *.dll *.bmp
  rd /s /q %objDir%
  if exist %vscodeDir% (
    rd /s /q %vscodeDir%
  )
  if exist %res% (
    rd /s /q %res%
  )
  popd
  rd /s /q %buildDir%
)