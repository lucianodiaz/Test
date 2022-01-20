#include "Messenger.h"
Messenger::Messenger()
{
	messageStore = make_unique<MessageStore>();
}

void Messenger::SendMessage(shared_ptr<UserManagement> u)
{
	/*Logic to receive message and verify if user exist then Send Message*/
	cout << "From: ";
	if (!CheckUser(from, u))
	{
		return;
	}
	cout << "To: ";
	if (!CheckUser(to, u))
	{
		return;
	}
	WriteMessage();
	messageStore->SetNewMessage(from, to, msg);
}

void Messenger::ShowAllMessages(shared_ptr<UserManagement> u)
{
	/*Logic to write user and verify if exist then Read all messages*/
	cout << "to: ";
	if (!CheckUser(to, u))
	{
		return;
	}
	messageStore->GetAllMessages(to);
}

void Messenger::WriteMessage()
{
	cout << "Message: ";
	string str;
	getline(cin >> ws, str);
	msg = str;
}

bool Messenger::CheckUser(string &usernameCheck, shared_ptr<UserManagement> u)
{
	
	string str;
	getline(cin>>ws, str);
	usernameCheck = str;
	if (!u->IsExistingUser(usernameCheck))
	{
		cout << "ERROR: User doesn't exist!" << endl;
		return false;;
	}
	else
	{
		return true;
	}
	
}
