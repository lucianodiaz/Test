#pragma once
#include <string>
#include <memory>
#include "MessageStore.h"

using namespace std;
class Messenger
{
public:
	Messenger();

	void SendMessage(string from, string to, string msg);

	void ShowAllMessages(string to);

private:
	//execution with pointer finished
	MessageStore* messageStore;
};

