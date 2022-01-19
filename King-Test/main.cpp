#include "Menu.h"
#include <iostream>
#include <memory>
#include "Messenger.h"
#include "UserManagement.h"
using namespace std;
int main(int argc, char* argv[])
{
	unique_ptr<Menu> store = make_unique<Menu>();
	/*If I declared pointer here, program stil work*/
	unique_ptr<Messenger> m = make_unique<Messenger>();
	unique_ptr<UserManagement> u = make_unique<UserManagement>();
	
	while (store->IsRunning())
	{
		store->ShowMenu();
	}
	return 0;
};
