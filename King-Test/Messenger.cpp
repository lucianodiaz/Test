#include "Messenger.h"
Messenger::Messenger()
{
	messageStore = new MessageStore();
}

void Messenger::SendMessage(string from, string to, string msg)
{
	messageStore->SetNewMessage(from, to, msg);
}

void Messenger::ShowAllMessages(string to)
{
	messageStore->GetAllMessages(to);
}
