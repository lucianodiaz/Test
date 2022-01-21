#pragma once

#include <iostream>
#include <map>
#include <memory>
#include <string>
#include "Messenger.h"
#include "UserManagement.h"

class Menu;

using namespace std;

/*Abstract Command*/
class Options
{
public:
	Options();

	virtual void Execute();

	string GetLabel() const { return label; };

protected:

	string label;
};

/*concrete Commands*/
class UserOption : public Options
{
public:

	UserOption(shared_ptr<UserManagement>& us, string l);

	void Execute() override;

protected:

	shared_ptr<UserManagement> userM;
};


class QuitOption :public Options
{

	bool running;
	unique_ptr<Menu> menu;

public:
	QuitOption(Menu* m, string l);

	void Execute() override;

};



/*Receiver class for concrete Complex Commands*/
class Receiver
{
public:
	void WriteAnMessage(shared_ptr<Messenger>& m,shared_ptr<UserManagement>&u);

	void ReadAllMessages(shared_ptr<Messenger>& m, shared_ptr<UserManagement>& u);
};

/*concrete Complex Command*/
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

class Invoker
{

	Options* simpleOption;

public:
	~Invoker() { delete simpleOption;}
	
	void ExecuteTask() const;

	bool HasOption() const { return simpleOption != nullptr ; }

	void SetSimpleOption(Options* option) { simpleOption = option; }

	string ShowLabel()const;
	
	
};