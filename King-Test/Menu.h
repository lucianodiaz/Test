#pragma once
#include <memory>
#include <iostream>
#include "Messenger.h"
#include "UserManagement.h"
#include "Options.h"

using namespace std;

class Menu
{
	const int nOptions = 4;
public:
	Menu();
	~Menu();
	void ShowMenu() const;
	bool IsRunning() const;
	void ProcessInput();
	void SetRunning(bool value) { running = value; }
private:
	
	int ValidateOption() const;
	void MenuInitialize();
	bool running;
	shared_ptr<UserManagement> userManagement;
	shared_ptr<Messenger> messenger;
	vector<Invoker*> menuOptions;
	Receiver* receiver = new Receiver;
};
