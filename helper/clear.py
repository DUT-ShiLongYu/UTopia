import os
import shutil
import argparse
from pathlib import Path

def clean_directory(project_name):
    # Construct the target directory path based on the project name
    target_dir = f"/root/UTopia/exp/{project_name}/output/profiles"
    
    # Define patterns to delete
    patterns = ["corpus_*", "information_*", "*.profraw", "*.txt","*.profdata"]
    
    # Convert target_dir to Path object for easier manipulation
    target_path = Path(target_dir)
    
    if not target_path.exists():
        print(f"The directory {target_dir} does not exist.")
        return

    # Iterate over each pattern
    for pattern in patterns:
        # Use glob to find matching files or directories
        for item in target_path.glob(pattern):
            try:
                if item.is_dir():
                    # Remove directory
                    shutil.rmtree(item)
                    print(f"Deleted directory: {item}")
                elif item.is_file():
                    # Remove file
                    item.unlink()
                    print(f"Deleted file: {item}")
            except Exception as e:
                print(f"Error deleting {item}: {e}")

if __name__ == "__main__":
    # Set up argparse to accept the project name as an argument
    parser = argparse.ArgumentParser(description="Clean up project profile directory.")
    parser.add_argument("project_name", type=str, help="The name of the project to clean up.")
    
    # Parse arguments
    args = parser.parse_args()

    # Run the cleanup function with the provided project name
    clean_directory(args.project_name)
