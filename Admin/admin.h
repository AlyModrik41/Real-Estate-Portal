//
// Created by BoOdy on 19/04/2025.
//
#ifndef ADMIN_H
#define ADMIN_H

#include <map>
#include <vector>
#include "properties.h"
using namespace std;
class admin {
  static const string username;
  static const string password;

public:



  static void add_prop(map<int,vector<properties> >& property_map);
  static void delete_prop(map<int, vector<properties>>& property_map);
  static void update_prop(map<int,  vector<properties>>& property_map);
  static void all_prop(map<int,    vector<properties>>& property_map);

  admin();
  ~admin();
};

#endif // ADMIN_H
