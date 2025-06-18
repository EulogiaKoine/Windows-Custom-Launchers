@echo off
REM 로컬 환경 설정(set~end)
setlocal

set "SCRIPT_DIR=.\scripts"
set "OUTPUT_DIR=."

echo Script 폴더에 있는 C/C++ 파일들을 컴파일합니다...
echo.

REM .c 파일 컴파일
echo --- C 파일 컴파일 중 ---
for %%f in ("%SCRIPT_DIR%\*.c") do (
    if exist "%%f" (
        echo Compiling C file: "%%~nxf"
        gcc "%%f" -o "%OUTPUT_DIR%\%%~nf.exe" -mwindows -lshell32
        if errorlevel 1 (
            echo ❌ERROR: Failed to compile "%%~nxf"
        ) else (
            echo ✔️SUCCESS: "%%~nf.exe" created.
        )
    )
)
echo.

REM .cpp 파일 컴파일
echo --- C++ 파일 컴파일 중 ---
for %%f in ("%SCRIPT_DIR%\*.cpp") do (
    if exist "%%f" (
        echo Compiling C++ file: "%%~nxf"
        g++ "%%f" -o "%OUTPUT_DIR%\%%~nf.exe" -mwindows -lshell32
        if errorlevel 1 (
            echo ❌ERROR: Failed to compile "%%~nxf"
        ) else (
            echo ✔️SUCCESS: "%%~nf.exe" created.
        )
    )
)
echo.

echo Every C/C++ Compiled Succeed.
echo 실행 파일들은 현재 폴더에 생성됩니다.
pause
endlocal