#pragma once

#include <iostream>
#include <memory>
#include "Messenger.h"
#include "Options.h"
#include "UserManagement.h"

using namespace std;

class Menu
{

private:
	static constexpr int c_numberOptions = 4;

public:
	Menu();
	~Menu();

	void ShowMenu() const;
	bool IsRunning() const;

	void StopRunning() { running = false; }

	void ProcessInput();
	

private:
	
	int ValidateOption() const;
	void MenuInitialize();

	shared_ptr<UserManagement> userManagement;
	shared_ptr<Messenger> messenger;
	vector<Invoker*> menuOptions;
	Receiver* receiver = new Receiver;

	bool running;
	
};
