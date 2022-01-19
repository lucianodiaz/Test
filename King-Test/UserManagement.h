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

	
private:
//
	void AddNewUser(string u);
	bool IsExistingUser(string u);
//
	//vector<string> users;
};

