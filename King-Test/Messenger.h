#pragma once
#include <string>
#include <memory>
#include "MessageStore.h"
#include "UserManagement.h"
using namespace std;
class Messenger
{
public:
	Messenger();

	void SendMessage(shared_ptr<UserManagement> u);

	void ShowAllMessages(shared_ptr<UserManagement> u);

private:
	
	void WriteMessage();
	bool CheckUser(string &usernameCheck, shared_ptr<UserManagement> u);
	string from,to,msg;

	unique_ptr<MessageStore> messageStore;
};

