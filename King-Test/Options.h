#pragma once
#include "Messenger.h"
#include "UserManagement.h"
#include <iostream>
#include <memory>
#include <string>
#include <map>

class Menu;

using namespace std;
/*Command*/
class Options
{
public:
	Options();

	virtual void Execute();

	string GetLabel() const { return label; };

protected:
	string label;
};

/*Simple Commands*/
class UserOption : public Options
{
public:
	UserOption(shared_ptr<UserManagement>& us, string l);

	void Execute() override;

protected:
	shared_ptr<UserManagement> userM;
};


/*Receiver class for Complex Commands*/
class Receiver
{
public:
	void WriteAnMessage(shared_ptr<Messenger>& m,shared_ptr<UserManagement>&u);

	void ReadAllMessages(shared_ptr<Messenger>& m, shared_ptr<UserManagement>& u);
};

/*Complex Command*/
class MessageSendOption : public Options
{
	Receiver* receiver;
	shared_ptr<UserManagement> userM;
	shared_ptr<Messenger> messenger;
public:
	MessageSendOption(Receiver* r, shared_ptr<UserManagement>& u, shared_ptr<Messenger>& m, string l);
	~MessageSendOption() { delete receiver; }
	void Execute() override;
};

class MessageReadOption :public Options
{
	Receiver* receiver;
	shared_ptr<UserManagement> userM;
	shared_ptr<Messenger> messenger;
public:
	MessageReadOption(Receiver *r, shared_ptr<UserManagement>& u,shared_ptr<Messenger>& m, string l);
	~MessageReadOption() { delete receiver; };
	void Execute() override;
};

//Simple Command
class QuitOption :public Options
{
	Menu* menu;
public:
	QuitOption(Menu* m, string l);
	~QuitOption() { delete menu; }
	void Execute() override;


};

class Invoker
{
	Options* simpleOption;


public:
	~Invoker() { delete simpleOption;}
	
	bool HasOption() { return simpleOption != nullptr ; }

	void SetSimpleOption(Options* option) { simpleOption = option; }

	string ShowLabel();
	
	void ExecuteTask();
};