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
	cout << "Message Send Option" << endl;
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
	cout << "Message Read Option" << endl;
	receiver->ReadAllMessages(messenger,userM);
}

QuitOption::QuitOption(Menu* m, string l)
{
	label = l;
	menu = m;
}

void QuitOption::Execute() 
{
	cout << "Quit Aplication" << endl;
	menu->SetRunning(false);
}

void Receiver::WriteAnMessage(shared_ptr<Messenger>& m, shared_ptr<UserManagement>& u)
{
	m->SendMessage(u);
}

void Receiver::ReadAllMessages(shared_ptr<Messenger>& m, shared_ptr<UserManagement>& u)
{
	m->ShowAllMessages(u);
}

string Invoker::ShowLabel()
{
	if (simpleOption)
	{
		return simpleOption->GetLabel();
	}
}

void Invoker::ExecuteTask()
{
	if (simpleOption)
	{
		simpleOption->Execute();
	}
}
