#include "Options.h"
#include "Menu.h"

Options::Options()
{
}

void Options::Execute()
{
}

UserOption::UserOption(shared_ptr<UserManagement>& us, string l)
{
	userM = us;
	label = l;
}

void UserOption::Execute()
{
	if (userM)
	{
		userM->CreateNewUser();
	}
}

MessageSendOption::MessageSendOption(Receiver* r,shared_ptr<UserManagement>& u, shared_ptr<Messenger>& m, string l)
{
	receiver = r;
	userM = u;
	messenger = m;
	label = l;
}

void MessageSendOption::Execute() 
{
	receiver->WriteAnMessage(messenger, userM);
}

MessageReadOption::MessageReadOption(Receiver* r, shared_ptr<UserManagement>& u,shared_ptr<Messenger>& m, string l)
{
	receiver = r;
	userM = u;
	messenger = m;
	label = l;
}

void MessageReadOption::Execute() 
{
	receiver->ReadAllMessages(messenger,userM);
}

QuitOption::QuitOption(Menu* m, string l)
{
	label = l;
	menu.reset(m);
}

void QuitOption::Execute() 
{
	cout << "Quit Aplication" << endl;
	menu->StopRunning();
}

void Receiver::WriteAnMessage(shared_ptr<Messenger>& m, shared_ptr<UserManagement>& u)
{
	m->SendMessage(u);
}

void Receiver::ReadAllMessages(shared_ptr<Messenger>& m, shared_ptr<UserManagement>& u)
{
	m->ShowAllMessages(u);
}

string Invoker::ShowLabel() const
{
	if (simpleOption)
	{
		return simpleOption->GetLabel();
	}
	return "";
}

void Invoker::ExecuteTask() const
{
	if (simpleOption)
	{
		simpleOption->Execute();
	}
}
