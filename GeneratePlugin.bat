@echo off
setlocal

REM Check if Python is installed
where python3 > nul 2>&1
if %errorlevel% neq 0 (
    echo Python3 is not installed. Please install Python and try again.
    pause
    exit /b
)

REM Check if required dependencies are installed
python3 -c "import shutil" > nul 2>&1
if %errorlevel% neq 0 (
    echo Required Python module 'shutil' is not installed. Please install it using 'pip install shutil' and try again.
    pause
    exit /b
)

REM Run the Python script
python3 Scripts/GeneratePlugin.py

:end
