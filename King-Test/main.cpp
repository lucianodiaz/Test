#include "Menu.h"
#include <iostream>
#include <memory>
#include "Messenger.h"
#include "UserManagement.h"

using namespace std;
int main(int argc, char* argv[])
{
	unique_ptr<Menu> store = make_unique<Menu>();

	while (store->IsRunning())
	{
		store->ShowMenu();
		store->ProcessInput();
	}
	return 0;
};
