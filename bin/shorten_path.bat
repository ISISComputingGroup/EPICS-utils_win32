@echo off
REM
REM this will shorten the passed PATH variable by turning everything into its "DOS" name
REM It will also remove folders that do not exist
REM
REM arg is a variable name like PATH
REM

if "%1" == "" (
    @echo shorten_path: no path given
    exit/b 1
)
SET "VarName=%%%~1%%"
call set "OrigPath=%VarName%"

setlocal EnableDelayedExpansion

SET TempPath="%OrigPath:;=";"%"
SET var=
FOR %%a IN (%TempPath%) DO (
    IF exist %%~sa (
        SET "var=!var!;%%~sa"
    ) ELSE (
        IF /I "%2" NEQ "strip" (
            SET "var=!var!;%%~sa"
        ) else (
            echo Removing %%a from %~1 as it does not exist
        )
    )
)

endlocal & set "%~1=%var:~1%"
