@echo off
set MYDIR=%~dp0
rem set OLDDIR=%CD%
rem set PATH=C:\Program Files\Java\jre7\bin;C:\Program Files (x86)\Java\jre7\bin;%PATH%
rem cd /d %MYDIR%..\VisualDCT-dist-2.6.1274\2.6.1274
rem java -cp %MYDIR%target\VisualDCT-2.6.1280.jar -DEPICS_DB_INCLUDE_PATH=%EPICS_DB_INCLUDE_PATH% com.cosylab.vdct.VisualDCT %*
java -jar %MYDIR%..\..\..\extensions\master\src\VisualDCT\target\VisualDCT-2.6.1280.jar ^
    %MYDIR%..\..\..\vdctdbds\dbd\vdctdbds.dbd %*
rem cd /d %OLDDIR%
