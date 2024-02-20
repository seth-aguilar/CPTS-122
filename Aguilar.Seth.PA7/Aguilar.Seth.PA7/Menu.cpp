#include "Menu.h"

void Menu::displayMenu()
{
    int choice;
    bool exit = false;

    List<Node<Data>>* masterList = nullptr;

    while (!exit) 
    {
        std::cout << "Menu options:" << std::endl;
        std::cout << "1. Import course list" << std::endl;
        std::cout << "2. Load master list" << std::endl;
        std::cout << "3. Store master list" << std::endl;
        std::cout << "4. Mark absences" << std::endl;
        std::cout << "5. Edit absences *NOT IMPLEMENTED*" << std::endl;
        std::cout << "6. Generate report" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) 
        {
        case 1:
            system("cls");

            importCourseList(masterList);
            break;
        case 2:
            system("cls");

            loadMasterList(masterList);
            break;
        case 3:
            system("cls");

            storeMasterList(masterList);
            break;
        case 4:
            system("cls");

            markAbsences(masterList);
            break;
        case 5:
            system("cls");

            editAbsences(masterList); // BONUS
            break;
        case 6:
            system("cls");

            generateReport(masterList);
            break;
        case 7:
            system("cls");

            std::cout << "Exiting program" << std::endl;
            system("pause");
            system("cls");

            exit = true;
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

void Menu::importCourseList(List<Node<Data>>* masterList)
{
    std::cout << "Importing course list" << std::endl;

    std::ifstream ifstream;
    ifstream.open("classList.csv", std::ios::in);
    std::string line;

    std::getline(ifstream, line);

    Data readData;

    while (std::getline(ifstream, line))
    {    
        std::istringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(ss, token, ','))
        {
            if (token.front() == '\"') {
                std::string quotedToken;
                std::getline(ss, quotedToken, '\"');
                token += ',' + quotedToken;
            }
            tokens.push_back(token);
        }

        readData.setID(std::stoi(tokens[1]));
        readData.setName(tokens[2]);
        readData.setEmail(tokens[0]);
        readData.setUnits(std::stoi(tokens[0]));
        readData.setProgram(tokens[0]);
        readData.setLevel(tokens[0]);

        masterList->getHead()->setPNext(masterList->getHead());
        masterList->getHead()->setData(readData);
    }

    ifstream.close();
    system("pause");
    system("cls");
}

void Menu::loadMasterList(List<Node<Data>>* masterList)
{
    std::cout << "Loading master list" << std::endl;
    system("pause");
    system("cls");
}

void Menu::storeMasterList(List<Node<Data>>* masterList)
{
    std::cout << "Storing master list" << std::endl;
    system("pause");
    system("cls");
}

void Menu::markAbsences(List<Node<Data>>* masterList)
{
    std::cout << "Cycling through list to mark absences" << std::endl;
    system("pause");
    system("cls");
}

void Menu::editAbsences(List<Node<Data>>* masterList)
{
    std::cout << "This function is not implentented" << std::endl;
    system("pause");
    system("cls");
}

void Menu::generateReport(List<Node<Data>>* masterList)
{
    std::cout << "Generating report" << std::endl;
    system("pause");
    system("cls");
}
