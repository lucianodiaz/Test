#pragma once

#include <memory>
#include <string>
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
	
	bool CheckUser(string& usernameCheck, shared_ptr<UserManagement> u) const;

	void WriteMessage(string& m);

	unique_ptr<MessageStore> messageStore;
};

