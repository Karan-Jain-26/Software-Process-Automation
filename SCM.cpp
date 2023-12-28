/* Python Equivalent of the C++ Code

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

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sys/stat.h>

void createProjectStructure(const std::string& projectName) {
    // Define the project structure
    std::vector<std::string> directories = {"src/main", "src/test", "docs/design", "docs/api", "config", "data"};

    // Create the project directory
    std::string projectPath = "./" + projectName;
    mkdir(projectPath.c_str(), 0777);

    // Create subdirectories based on the defined structure
    for (const std::string& dir : directories) {
        std::string fullPath = projectPath + "/" + dir;
        mkdir(fullPath.c_str(), 0777);
        std::cout << "Created directory: " << fullPath << std::endl;
    }

    std::cout << "Project structure for '" << projectName << "' created successfully at " << projectPath << std::endl;
}

int main() {
    // Get the project name from the user
    std::string projectName;
    std::cout << "Enter the name of the new project: ";
    std::cin >> projectName;

    // Call the function to create the project structure
    createProjectStructure(projectName);

    return 0;
}
