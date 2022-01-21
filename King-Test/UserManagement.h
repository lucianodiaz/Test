#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class UserManagement
{

public:
	UserManagement();

	void CreateNewUser();

	bool IsExistingUser(string u)const;
private:

	void AddNewUser(string u);
	
	vector<string> users;
};

