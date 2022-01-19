#include "UserManagement.h"

UserManagement::UserManagement()
{
}

void UserManagement::CreateNewUser()
{
    string user;
    cout << "Please enter username: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, user);
    cout << endl;
   if (IsExistingUser(user))
    {
        cout << "ERROR: User already exists!" << endl;
    }
    else
    {
        AddNewUser(user);
    }
}

void UserManagement::AddNewUser(string u)
{
   // users.push_back(u);
    cout << "User: " << u << "added!" << endl;
    system("pause");
}

bool UserManagement::IsExistingUser(string u)
{
    return true;//(find(users.begin(), users.end(), u) != users.end());
}
