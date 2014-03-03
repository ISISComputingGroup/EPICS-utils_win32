@echo off
for /f "usebackq tokens=2 delims=:" %%f in (`ipconfig ^| findstr /c:"IPv4 Address" ^| findstr 130.246.`) do (
    set MYIP=%%f
    set ISISIP=%MYIP: =%
    goto :eof
)
