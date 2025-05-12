#include "admin.h"
#include "properties.h"
#include <stdio.h>
using namespace std;
#include<map>
/*Edits:
1- property list type(unorderd map of id's and properties)

2- property atributes

3-add property at id 999 (admin's id)


 */


admin::admin() {

}

admin::~admin() {
}

void admin::add_prop(map<int, vector<properties>>& property_map) {
    int owner_id, price, rooms, area;
    bool furniture;
    string location, owner;
    char check, furnished;

    do {
        cout << "Enter owner ID: ";
        cin >> owner_id;
        cout << "Enter property price: ";
        cin >> price;
        cout << "Enter number of rooms: ";
        cin >> rooms;
        cout << "Enter area (sq ft): ";
        cin >> area;
        cout << "Is furnished? (Y/N): ";
        cin >> furnished;
        cout << "Enter property location: ";
        cin.ignore();
        getline(cin, location);
        cout << "Enter owner's name: ";
        getline(cin, owner);

        furniture = (toupper(furnished) == 'Y');
        bool valid = !owner.empty() && price > 0 && !location.empty()  && rooms > 0 && area > 0 && (toupper(furnished) == 'Y' || toupper(furnished) == 'N');

        if (!valid) {
            cout << "Invalid input! Please check values:\n"
                 << "- All text fields must be filled\n"
                 << "- Numeric values must be positive\n"
                 << "- Furnished must be Y/N\n";
            check = 'y';
        } else
        {

            properties p(price, rooms, area, furniture, owner, location);
            p.set_status(true);
            p.set_highlight(false);

            property_map[owner_id].push_back(p);
            cout << "\n✅ Property added successfully!"
                 << "\nProperty ID: " << property_map[owner_id].size()-1
                 << "\nAdd another? (Y/N): ";
            cin >> check;
        }
    } while (toupper(check) == 'Y');
}


void admin::delete_prop(map<int, vector<properties>>& property_map) {
    int owner_id, prop_id;
    cout << "Enter owner ID: ";
    cin >> owner_id;

    auto it = property_map.find(owner_id);
    if (it == property_map.end() || it->second.empty()) {
        cout << "No properties found!\n";
        return;
    }

    cout << "Properties for owner " << owner_id << ":\n";
    for (size_t i = 0; i < it->second.size(); i++) {
        cout << "[" << i << "] " << it->second[i].get_location()
             << " - $" << it->second[i].get_price() << "\n";
    }

    cout << "Enter property ID to delete: ";
    cin >> prop_id;

    if (prop_id >= 0 && prop_id < it->second.size())
    {
        it->second.erase(it->second.begin() + prop_id);
        cout << "✅ Property deleted!\n";
    }
    else {
        cout << "Invalid ID!\n";
    }
}


void admin::update_prop(map<int, vector<properties>>& property_map) {
    int owner_id, prop_id;
    cout << "Enter owner ID: ";
    cin >> owner_id;

    auto it = property_map.find(owner_id);
    if (it == property_map.end() || it->second.empty()) {
        cout << "No properties found!\n";
        return;
    }

    cout << "Available properties:\n";
    for (size_t i = 0; i < it->second.size(); i++) {
        const auto& prop = it->second[i];
        cout << "[" << i << "] " << prop.get_location()
             << " - $" << prop.get_price()
             << " - Rooms: " << prop.get_rooms()
             << " - Area: " << prop.get_area() << " sq ft"
             << " - Furnished: " << (prop.get_furniture() ? "Yes" : "No") << "\n";
    }

    cout << "Enter property ID to update: ";
    cin >> prop_id;

    if (prop_id < 0 || prop_id >= it->second.size()) {
        cout << "Invalid ID!\n";
        return;
    }

    properties& p = it->second[prop_id];
    cout << "Choose field to update:\n"
         << "1. Price\n"
         << "2. Location\n"
         << "3. Status\n"
         << "4. Rooms\n"
         << "5. Area\n"
         << "6. Furniture\n"
         << "Enter your choice: ";

    int choice;
    cin >> choice;

    if (cin.fail() || choice < 1 || choice > 6) {
        cout << "Invalid choice!\n";
        cin.clear();
        cin.ignore(256, '\n');
        return;
    }

    switch (choice) {
        case 1: {
            int new_price;
            cout << "Enter new price: ";
            cin >> new_price;
            if (new_price <= 0) {
                cout << "Price must be positive!\n";
                return;
            }
            p.set_price(new_price);
            break;
        }
        case 2: {
            string new_loc;
            cout << "Enter new location: ";
            cin.ignore();
            getline(cin, new_loc);
            if (new_loc.empty()) {
                cout << "Location can't be empty!\n";
                return;
            }
            p.set_location(new_loc);
            break;
        }
        case 3: {
            bool new_status;
            cout << "Enter new status (1 for available, 0 for sold): ";
            cin >> new_status;
            p.set_status(new_status);
            break;
        }
        case 4: {
            int new_rooms;
            cout << "Enter new number of rooms: ";
            cin >> new_rooms;
            if (new_rooms <= 0) {
                cout << "Rooms must be positive!\n";
                return;
            }
            p.set_rooms(new_rooms);
            break;
        }
        case 5: {
            int new_area;
            cout << "Enter new area (sq ft): ";
            cin >> new_area;
            if (new_area <= 0) {
                cout << "Area must be positive!\n";
                return;
            }
            p.set_area(new_area);
            break;
        }
        case 6: {
            char furnished;
            cout << "Is furnished? (Y/N): ";
            cin >> furnished;
            if (toupper(furnished) != 'Y' && toupper(furnished) != 'N') {
                cout << "Invalid input! Please enter Y or N.\n";
                return;
            }
            p.set_furniture(toupper(furnished) == 'Y');
            break;
        }
    }
    cout << "✅ Property updated successfully!\n";
}

void admin::all_prop(map<int, vector<properties>>& property_map) {
    vector<pair<int, size_t>> prop_indices;
    int display_number = 1;
    char choice;


    for (const auto& [owner_id, props] : property_map) {
        for (size_t i = 0; i < props.size(); i++) {
            const auto& p = props[i];
            cout << "════════════════════════════════════════\n"
                      << display_number++ << ":\n"
                      << "Owner ID: " << owner_id << "\n"
                      << "Property ID: " << i << "\n"
                      << "Price: $" << p.get_price() << "\n"
                      << "Location: " << p.get_location() << "\n"
                      << "Owner: " << p.get_owner() << "\n"
                      << "Status: " << (p.get_status() ? "Available" : "Sold") << "\n"
                      << "Highlighted: " << (p.get_highlight() ? "Yes" : "No") << "\n";


            prop_indices.emplace_back(owner_id, i);
        }
    }

    cout << "════════════════════════════════════════\n"
              << "Highlight a property? (Y/N): ";
    cin >> choice;

    while (toupper(choice) == 'Y') {
        int selected_num;
        cout << "Enter property number to highlight: ";
        cin >> selected_num;

        if (selected_num < 1 || selected_num > display_number - 1) {
            cout << "Invalid property number!\n";
        } else {

            const auto& [owner_id, prop_idx] = prop_indices[selected_num - 1];

            auto it = property_map.find(owner_id);
            if (it != property_map.end() && prop_idx < it->second.size()) {
                properties& p = it->second[prop_idx];
                p.set_highlight(true);
                cout << "✅ Property " << selected_num << " highlighted!\n";
            } else {
                cout << "Error: Property not found!\n";
            }
        }

        cout << "Highlight another property? (Y/N): ";
        cin >> choice;
    }
}