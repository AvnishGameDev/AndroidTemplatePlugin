# Copyright (C) AvnishGameDev 2024.

import os
import shutil

def safe_file_read(file_path):
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            content = f.read()
        return content
    except UnicodeDecodeError:
        with open(file_path, 'r', errors='ignore') as f:
            content = f.read()
        return content

def rename_files_and_folders(folder_path, old_name, new_name):
    for root, dirs, files in os.walk(folder_path):
        # Rename folders
        for dir in dirs:
            dir_path = os.path.join(root, dir)
            new_dir_path = os.path.join(root, dir.replace(old_name, new_name))
            os.rename(dir_path, new_dir_path)

        # Rename files
        for file in files:
            file_path = os.path.join(root, file)
            content = safe_file_read(file_path)

            # Replace text in file content
            content = content.replace("%PLUGIN_NAME%", new_name)

            with open(file_path, 'w') as f:
                f.write(content)

            # Rename the file
            new_file_path = os.path.join(root, file.replace(old_name, new_name))
            os.rename(file_path, new_file_path)

def rename_plugin(template_path, plugin_name):
    old_name = "AndroidTemplate"
    new_name = plugin_name

    # Create a new folder for the generated plugin
    new_plugin_path = os.path.join(os.getcwd(), plugin_name)
    shutil.copytree(template_path, new_plugin_path)

    # Rename folders, files, and replace text in files
    rename_files_and_folders(new_plugin_path, old_name, new_name)
    rename_files_and_folders(f'{new_plugin_path}/Source/{plugin_name}', old_name, new_name)

if __name__ == "__main__":
    print("AndroidTemplate plugin made by AvnishGameDev.\n")
    # Assuming your plugin template is in the current working directory
    template_path = 'AndroidTemplate'

    # Get user input for the new plugin name
    plugin_name = input("Enter the new plugin name: ")

    # Call the function to rename the plugin
    rename_plugin(template_path, plugin_name)

    print("Plugin generated successfully.")