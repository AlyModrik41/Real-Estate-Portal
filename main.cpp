#include<set>
#include<map>
#include"user.h"
#include "admin.h"
#include "properties.h"

bool compare(const properties& a, const properties& b) {
	return a.get_price() < b.get_price();
}
void showAdminMenu() {
	cout << "========================================\n";
	cout << "         🏠 Property Admin Panel         \n";
	cout << "========================================\n";
	cout << "    Please choose an action from the list below:\n\n";
	cout << "  [1] ➕ Add New Property\n";
	cout << "  [2] ✏  Edit Existing Property\n";
	cout << "  [3] ❌ Delete Property\n";
	cout << "  [4] 📋 Show All Properties\n";
	cout << "  [5] Approve new Properties"<<endl;
	cout << "  [0] 🚪 Logout / Exit\n";
}
int main(int argc, char* argv[]) {
	char answer = 'f';
	map<int, properties> listOfProperties;
	user obj;
	multiset<properties, bool(*)(const properties& a, const  properties& b)> property_set(compare);
	while (answer == 'f') {
		//multi set that saves the properties sorted using pointer function

		char n;
		bool check = false;
		int id;
		while (true) {
			showAdminMenu();
			cin >> n;
			if (!(n >= '0' && n <= '5')) {
				cout << "Invalid input please try again" << endl;
			}
			else {
				switch (n) {
				case '1':admin::add_prop(property_set);
					break;
				case '2':admin::update_prop();
					break;
				case '3':admin::delete_prop();
					break;
				case '4':admin::all_prop(property_set);
					break;
				case '5':
					obj.filter_search(6, listOfProperties);
					cout << "Choose Property to approve" << endl;
					cin >> id;
					for (auto it = listOfProperties.begin(); it != listOfProperties.end(); it++) {
						if (id == it->first) {
							it->second.set_approval(true);
						}
					}
					break;
				case '0':
					check = true;
					break;
				}
				if (check) break;
			}
		}

		//BOODY {ADMIN MENU CODE}


		int choice;
		int id_counter = 0;
		while (true)
		{
			obj.ShowUserMenu();
			cin >> choice;
			if (choice == 1)
			{
				properties temp = obj.add_prop();
				id_counter++;
				listOfProperties.insert({ id_counter, temp });

			}
			else if (choice == 2)
			{
				int filter;
				while (true)
				{
					cout << "Choose Attribute you want to Search For Properties Using " << endl;
					cout << "------------------------------------------------------------" << endl;
					cout << " [0] NO FILTER" << endl;
					cout << " [1] Price" << endl;
					cout << " [2] Location" << endl;
					cout << " [3] Area" << endl;
					cout << " [4] Rooms" << endl;
					cout << " [5] Furniture" << endl;
					cin >> filter;
					if (filter > 5 || filter < 0)
					{
						cout << "!!INVALID FILTER OPTION!!" << endl;
					}
					else
					{
						break;
					}
				}
				admin::all_prop(property_set);
				obj.filter_search(filter, listOfProperties);

			}
			else
			{
				break;
			}
		}
		cout << "Continue??? (t/f)" << endl;
	}
	return 0;
}

	// ALI, SEIF{ USER MENU } "add property and search filters" /

		//