#include "MessageStore.h"

MessageStore::MessageStore()
{
	messages.reserve(10);
}

void MessageStore::SendNewMessage(string from, string to, string msg)
{
	if (ValidateMessage(from, to, msg))
	{
		messages.push_back(AddNewMessage(from, to, msg));
		cout << "Message Sent!" << endl;
	}
	else
	{
		cout << "ERROR: Message Incomplete" << endl;
	}
}

void MessageStore::GetAllMessages(string to)
{
	cout << endl << "======= BEGIN MESSAGES =========" << endl;
	int num = 0;
	bool moreMessages;
	do
	{
		moreMessages = false;
		for (unsigned int i = 0; i < messages.size(); ++i)
		{
			auto& m = messages[i];
			
			if (m->to == to)
			{
				cout << "Message " << ++num << endl;
				cout << "From: " << m->from << endl;
				cout << "Content: " << m->msg << endl;
				messages.erase(messages.begin() + i);
				moreMessages = true;
			}
		}
	} while (moreMessages);
	if (num == 0)
	{
		cout << "The user has no received messages" << endl;
	}
	cout << endl << "======= END MESSAGES =========" << endl;
}

bool MessageStore::ValidateMessage(string from, string to, string msg) const
{
	const bool isValid = !from.empty() && !to.empty() && !msg.empty();
	return isValid;
}

unique_ptr<Message> MessageStore::AddNewMessage(string from, string to, string msg)
{
	unique_ptr<Message> msgTemp = make_unique<Message>();

	msgTemp->from = from;
	msgTemp->to = to;
	msgTemp->msg = msg;

	return msgTemp;
}
