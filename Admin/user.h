#pragma once
#include <iostream>
#include<map>
#include<unordered_map>

#include"properties.h"
using namespace std;
class user
{
	int id;
	string name = "";

public:
	user();
	user(int id ,string name);
	properties add_prop();
	void filter_search(int, unordered_map<int, vector<properties>>);
	void display_property(int, properties);
	void ShowUserMenu();
	int get_id();
};