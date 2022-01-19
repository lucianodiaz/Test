#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;
struct Message
{
	string from;
	string to;
	string msg;
};
class MessageStore
{
public:
	MessageStore();

	void SetNewMessage(string from,string to,string msg);
	void GetAllMessages(string to);

private:
	bool ValidateMessage(string from, string to, string msg) const;
	Message* AddNewMessage(string from, string to, string msg);
	//execution with pointer finished
	vector<Message*> messages;
	
};

