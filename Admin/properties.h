//
// Created by BoOdy on 19/04/2025.
//

#ifndef PROPERTIES_H
#define PROPERTIES_H
#include <iostream>
using namespace std;


class properties {
int price;
bool status;
  bool highlighted;
string owner;
  string location;
public:
  properties();
  properties(int);
  ~properties();
  void set_price(int);
  void set_status(bool);
  void set_owner(string);
  void set_location(string);
  void set_highlight(bool );
  int get_price() const;
  bool get_status() const;
  bool get_highlight() const;
  string get_owner() const;
  string get_location() const;

};



#endif //PROPERTIES_H
