#include "Menu.h"

Menu::Menu()
{
}


void Menu::ShowMenu()
{
    system("cls");
    cout << "Please select an option: " << endl;
    cout << "1. Create User: " << endl;
    cout << "2. Send Message: " << endl;
    cout << "3. Receive All Messages for User: " << endl;
    cout << "4. Quit: " << endl;
    ProcessInput();
}

bool Menu::IsRunning()
{
	return running;
}

void Menu::ProcessInput()
{
    int option = ValidateOption();

    switch (option)
    {
    case 1:
        //call user manager
        cout << "You choice option: " << option << endl;
    /*    if (userManagement)
        {
            userManagement->CreateNewUser();
        }*/
        system("pause");
        break;
    case 2:
        //call message sender
        cout << "You choice option: " << option << endl;
        system("pause");
        break;
    case 3:
        //call receiver manager
        cout << "You choice option: " << option << endl;
        system("pause");
        break;
    case 4:
        //quit
        cout << "You choice option: " << option << endl;
        running = false;
        getchar();
        break;
    default:
        cout << "you entered wrong choice" << endl;
        system("pause");
        break;
    }
}

int Menu::ValidateOption()
{
    int option;
    cout << "\n Your option: ";
    while (!(cin >> option))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Input. Try again: ";
    }
    system("cls");
    return option;
}
