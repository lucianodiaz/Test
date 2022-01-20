#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

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

