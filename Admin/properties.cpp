//
// Created by BoOdy on 19/04/2025.
//

#include "properties.h"



properties::properties() :price(0), status(false), owner("company") {

}

properties::properties(int price) : price(price), status(false), owner("company") {

}

properties::properties(int price, int rooms, int area, bool furniture, string owner, string location)
{
    this->price = price;
    this->rooms = rooms;
    this->area = area;
    this->furniture = furniture;
    this->owner = owner;
    this->location = location;
    this->status = false;
}

properties::~properties() {
}

void properties::set_price(int price) {
    this->price = price;
}

void properties::set_status(bool status) {
    this->status = status;
}

void properties::set_owner(string owner) {
    this->owner = owner;
}

void properties::set_location(string location) {
    this->location = location;
}

void properties::set_area(int area)
{
    this->area = area;
}

void properties::set_rooms(int rooms)
{
    this->rooms = rooms;
}

void properties::set_furniture(bool furniture)
{
    this->furniture = furniture;
}
void properties::set_approval(bool approval ) {
    approved = approval;
}
void properties::set_highlight(bool h) {
    highlighted=h;
}


int properties::get_price() const {
    return price;
}
bool properties::get_status() const
{
    return status;
}
string properties::get_owner() const {
    return owner;
}
bool properties::get_highlight() const {
    return highlighted;
}
string properties::get_location() const {
    return location;
}
bool properties::get_furniture() const
{
    return furniture;
}
int properties::get_area() const
{
    return area;
}
int properties::get_rooms()const
{
    return rooms;
}
bool properties::get_approval() const{
    return approved;
}
int properties::get_id() const{
    return id;
}