import os

def create_project_structure(project_name):
    # Define the project structure
    project_structure = {
        'src': ['main', 'test'],
        'docs': ['design', 'api'],
        'config': [],
        'data': [],
    }

    # Create the project directory
    project_path = os.path.join(os.getcwd(), project_name)
    os.makedirs(project_path, exist_ok=True)

    # Create subdirectories based on the defined structure
    for directory, subdirectories in project_structure.items():
        directory_path = os.path.join(project_path, directory)
        os.makedirs(directory_path, exist_ok=True)
        
        for subdirectory in subdirectories:
            os.makedirs(os.path.join(directory_path, subdirectory), exist_ok=True)
            
    print(f"Project structure for '{project_name}' created successfully at {project_path}")

if __name__ == "__main__":
    # Get the project name from the user
    project_name = input("Enter the name of the new project: ")
    
    # Call the function to create the project structure
    create_project_structure(project_name)

