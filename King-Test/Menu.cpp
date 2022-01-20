#include "Menu.h"

Menu::Menu()
{
    running = true;

    userManagement = make_shared<UserManagement>();
    messenger = make_shared<Messenger>();

    /*Initialize menu*/
    for (int i = 0; i < 4; i++)
    {
        menuOptions.push_back(new Invoker);
    }

    menuOptions[0]->SetSimpleOption(new UserOption(userManagement,"Create User: "));
    menuOptions[1]->SetSimpleOption(new MessageSendOption(receiver,userManagement,messenger, "Send Message: "));
    menuOptions[2]->SetSimpleOption(new MessageReadOption(receiver, userManagement, messenger, "Receive All messages for user: "));
    menuOptions[3]->SetSimpleOption(new QuitOption(this, "Quit: "));
}

Menu::~Menu()
{
    delete receiver;
    for (auto a : menuOptions)
    {
        delete a;
    }
}


void Menu::ShowMenu()
{  
    system("cls");
    for (int i = 0; i < menuOptions.size(); ++i)
    {
        cout << (i+1)<<".";
        cout <<menuOptions[i]->ShowLabel() << endl;
    }
    ProcessInput();
}

bool Menu::IsRunning()
{
	return running;
}

void Menu::ProcessInput()
{
    int option = ValidateOption()-1;

    if (option > menuOptions.size())
    {
        cout << "you entered wrong choice" << endl;
        system("pause");
    }
    else
    {
        menuOptions[option]->ExecuteTask();
        system("pause");
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
