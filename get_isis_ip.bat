@echo off
set MYIP=127.0.0.1
for /f "usebackq tokens=2 delims=:" %%f in (`ipconfig ^| findstr /c:"IPv4 Address" ^| findstr 130.246.`) do (
    set MYIP=%%f
    goto :done
)
:done
set ISISIP=%MYIP: =%