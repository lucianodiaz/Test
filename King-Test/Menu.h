#pragma once
#include <memory>
#include <iostream>
#include "Messenger.h"
#include "UserManagement.h"
using namespace std;

class Menu
{
public:
	Menu();
	void ShowMenu();

	bool IsRunning();

private:
	void ProcessInput();
	int ValidateOption();
	bool running;
	
	//execution with pointer finished
	//even with unique_ptr
	Messenger* m;
	//execution with pointer finished
	UserManagement* m;

};
