#pragma once
#include <iostream>
#include<map>

#include"properties.h"
using namespace std;
class user
{
    string name = "";

public:
    user();
    user(string name);
    properties add_prop();
    void filter_search(int, map<int, properties>);
    void ShowUserMenu();
};