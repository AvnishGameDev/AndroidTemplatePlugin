#!/bin/bash

# Check if Python is installed
command -v python3 > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo "Python is not installed. Please install Python and try again."
    exit 1
fi

# Check if required dependencies are installed
python3 -c "import shutil" > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo "Required Python module 'shutil' is not installed. Please install it using 'pip install shutil' and try again."
    exit 1
fi

# Run the Python script
python3 Scripts/GeneratePlugin.py
