//
// Created by BoOdy on 19/04/2025.
//

#include "properties.h"

properties::properties():price(0),status(false),owner("company"),highlighted(false){

}

properties::properties(int price):price(price),status(false),owner("company"),highlighted(false){

}

properties::~properties() {
}

void properties::set_price(int price) {
    this->price=price;
}

void properties::set_highlight(bool H) {
 highlighted=H;
}
void properties::set_status(bool status){
this->status=status;
}

void properties::set_owner(string owner) {
    this->owner=owner;
}

void properties::set_location(string location) {
    this->location=location;
}

int properties::get_price() const{
  return price;
}

string properties::get_owner() const{
    return owner;
}
string properties::get_location() const{
    return location;
}

bool properties::get_highlight() const{
    return highlighted;
}
