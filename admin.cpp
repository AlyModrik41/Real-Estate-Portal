//
// Created by BoOdy on 09/05/2025.
//

#include "admin.h"
#include "admin.h"
#include "properties.h"


admin::admin() {

}

admin::~admin() {
}

void admin::add_prop(multiset<properties, bool(*)(const properties& a, const  properties& b)>& property_set) {
    int price;
    string location, owner;
    char check;
    properties p;
    bool approved = true;
    p.set_status(true);
    do {

        cout << "Enter property price: " << endl;
        cin >> price;


        cout << "Enter property location: " << endl;
        cin >> location;


        cout << "Enter owner's name: " << endl;
        cin >> owner;

        if (owner == "" || price <= 0 || location == "") {
            cout << "please fill all inputs" << endl;

        }
        else {
            p.set_price(price);
            p.set_location(location);
            p.set_owner(owner);
            property_set.insert(p);
            cout << "\n✅ Property added successfully!\n" << "do you want to add Another one?Y/N\n";
            cin >> check;
        }
    } while (check == 'y' || check == 'Y');




}
void admin::approve_prop() {

}


void admin::update_prop() {
}

void admin::delete_prop() {
}
void admin::all_prop(multiset<properties, bool(*)(const properties& a, const  properties& b)>& property_set) {
    int count = 1;
    for (properties p : property_set) {
        cout << "========================================\n" << count++ << ":\n";
        cout << "Price   : " << p.get_price() << "$\n";
        cout << "Location: " << p.get_location() << "\n";
        cout << "Owner   : " << p.get_owner() << "\n";
        cout << "========================================\n";
    }
}