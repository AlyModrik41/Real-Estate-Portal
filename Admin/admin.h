//
// Created by BoOdy on 19/04/2025.
//

#ifndef ADMIN_H
#define ADMIN_H
#include<set>
#include<iostream>
#include "properties.h"
using namespace std;
class admin {
  static const string username;
  static const string password;

public:
  static void add_prop(multiset<properties,bool(*)(const properties& a,const  properties& b)>&);
  static void update_prop();
  static void delete_prop();

  static void all_prop(multiset<properties, bool(*)(const properties &a, const properties &b)> &);

  admin();
  ~admin();
};




#endif //ADMIN_H
