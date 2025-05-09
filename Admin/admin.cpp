//
// Created by BoOdy on 19/04/2025.
//

#include "admin.h"
#include "properties.h"

/*Edits:
1- property list type(unorderd map of id's and properties)

2- property atributes

3-add property at id 999 (admin's id)


 */
admin::admin() {

}

admin::~admin() {
}

void admin::add_prop(multiset<properties,bool(*)(const properties& a,const  properties& b)>&property_set) {
    int price;
    string location,owner;
    char check;
    properties p;
    p.set_status(true);
    do {
        cout << "Enter property price: "<<endl;
        cin >> price;


        cout << "Enter property location: "<<endl;
        cin>>location;


        cout << "Enter owner's name: "<<endl;
        cin>>owner;

        if (owner==""||price<=0||location=="") {
            cout<<"please fill all inputs"<<endl;
           check='y';
        }else {
            p.set_price(price);
            p.set_location(location);
            p.set_owner(owner);
            property_set.insert(p);
            cout << "\n✅ Property added successfully!\n"<<"do you want to add Another one?Y/N\n";
            cin>>check;
        }
    }while (check=='y'||check=='Y');




}


void admin::update_prop() {
}

void admin::delete_prop() {
}



void admin::all_prop(multiset<properties,bool(*)(const properties& a,const  properties& b)>&property_set) {
    int count=1;
    char check;
  multiset<properties,bool(*)(const properties& a,const  properties& b)>::iterator it=property_set.begin();
    for (properties p :property_set) {
        cout << "========================================\n"<<count++<<":\n";
        cout << "Price   : " << p.get_price() << "$\n";
        cout << "Location: " << p.get_location() << "\n";
        cout << "Owner   : " << p.get_owner() << "\n";
        cout << "highlight?   : ";
        if (p.get_highlight())
            cout<<"Yes\n";
        else
            cout<<"No\n";
        cout << "========================================\n";
    }


    cout<<"Do you want to highlight a property?Y/N\n";
    cin>>check;
    while (check=='y'||check=='Y'){
        cout<<"Enter the number of property you want to highlight from the list above\u2191\n";
        cin>>count;
        advance(it,--count);
        properties p=*it;
        p.set_highlight(true);
        property_set.erase(it);
        property_set.insert(p);
        cout<<"✅ Property highlighted successfully!\n";
        cout<<"Do you want to highlight another property?Y/N\n";
        cin>>check;
    }



}
