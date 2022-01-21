#include <iostream>
#include <memory>
#include "Menu.h"
#include "Messenger.h"
#include "UserManagement.h"

using namespace std;
int main(int argc, char* argv[])
{
	unique_ptr<Menu> app = make_unique<Menu>();

	while (app->IsRunning())
	{
		app->ShowMenu();
		app->ProcessInput();
	}
	return 0;
};
