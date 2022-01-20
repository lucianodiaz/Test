#pragma once
#include <memory>
#include <iostream>
#include "Messenger.h"
#include "UserManagement.h"
#include "Options.h"

using namespace std;

class Menu
{
public:
	Menu();
	~Menu();
	void ShowMenu();
	bool IsRunning();

	void SetRunning(bool value) { running = value; }
private:
	void ProcessInput();
	int ValidateOption();
	bool running;
	
	shared_ptr<UserManagement> userManagement;
	shared_ptr<Messenger> messenger;
	vector<Invoker*> menuOptions;
	Receiver* receiver = new Receiver;
};
