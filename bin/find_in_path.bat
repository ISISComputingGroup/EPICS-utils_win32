@echo off
setlocal
for %%X in (%1) do ( set "FOUND=%%~$PATH:X" )
if exist "%FOUND%" (
    echo %FOUND%
) else (
    echo NOT_FOUND
)
