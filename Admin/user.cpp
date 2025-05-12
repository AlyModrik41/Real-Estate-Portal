#include "user.h"
#include<iostream>

#include<unordered_map>

using namespace std;

user::user()
{
	this->name = " ";
}

user::user(int id , string name)
{
	this->id = id;
	this->name = name;
}

int user::get_id()
{
	return id;
}

properties user::add_prop()
{
	int price, rooms, area;
	string location, answer;
	bool furniture = false;

	while (true) {
		cout << "Enter property price:" << endl;
		cout << "----------------------" << endl;
		cin >> price;
		if (price <= 0)
		{
			cout << "!!INVALID PRICE!!" << endl;
		}
		else
		{
			break;
		}
	}
	cout << "Enter property location:" << endl;
	cout << "-------------------------" << endl;
	cin >> location;
	while (true)
	{
		cout << "Enter property Area:" << endl;
		cout << "----------------------" << endl;
		cin >> area;
		if (area <= 0)
		{
			cout << "!!INVALID AREA!!" << endl;
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "Enter the number of rooms:" << endl;
		cout << "----------------------------" << endl;
		cin >> rooms;
		if (rooms <= 0)
		{
			cout << "!!INVALID NUMBER OF ROOOMS!!" << endl;
		}
		else
		{
			break;
		}
	}

	cout << " Is the property with furniture(Yes,No)?" << endl;
	cout << "-----------------------------------------" << endl;
	cin >> answer;
	if (answer == "yes" || answer == "Yes" || answer == "y" || answer == "Y")
	{
		furniture = true;
	}
	else if (answer == "no" || answer == "No" || answer == "n" || answer == "N")
	{
		furniture = false;
	}

	properties temp(price, rooms, area, furniture, this->name, location);
	temp.set_approval(true);
	return temp;
}


void user::filter_search(int filter, unordered_map<int, vector<properties>> listOfProperties)
{
	if (filter == 0)//no filter
	{
		for (auto it = listOfProperties.begin(); it != listOfProperties.end(); it++)
		{
			if (it->first != this->id)
			{
				for (int i = 0;i<it->second.size();i++)
				{
					if (it->second[i].get_approval())
					{
						display_property(it->first, it->second[i]);
					}
				}
			}
		}
	}
	else if (filter == 1)//price
	{
		multimap<int, properties> filter_map;
		unordered_map<int, int> prop_owner_id;

		int min, max;
		while (true)
		{
			cout << "Enter Minumum Price Range : " << endl;
			cout << "------------------------------" << endl;
			cin >> min;
			cout << "Enter maximum Price Range : " << endl;
			cout << "------------------------------" << endl;
			cin >> max;
			if (min >= max)
			{
				cout << "!! INVALID PRICE RANGE!!" << endl << endl;
			}
			else
			{
				break;
			}
		}

		for (auto it = listOfProperties.begin(); it != listOfProperties.end(); it++)
		{
			if (it->first != this->id)
			{
				for (int i = 0; i < it->second.size(); i++)
				{
					if (it ->second[i].get_price() >= min && it->second[i].get_approval() && it->second[i].get_price() <= max)
					{
						filter_map.insert({it->second[i].get_price() , it->second[i]});
						prop_owner_id.insert({ it->second[i].get_id() , it->first});
					}
				}
			}


			/*if (it->second.get_price() >= min && it->second.get_price() <= max)
			{
				filter_map.insert({ it->second.get_price() , it->second });
			}*/

		}

		for (auto it = filter_map.begin(); it != filter_map.end(); it++)
		{
			display_property(prop_owner_id[it->second.get_id()],it->second);
		}
	}
	else if (filter == 2)//location
	{

		string loc;

		cout << "Enter The Location You Want: " << endl;
		cout << "-------------------------------" << endl;
		cin >> loc;


		

		for (auto it = listOfProperties.begin(); it != listOfProperties.end(); it++)
		{
			if (it->first != this->id)
			{
				for (int i = 0; i < it->second.size(); i++)
				{
					if (it->second[i].get_approval() && it->second[i].get_location() == loc)
					{
						display_property(it->first, it->second[i]);
					}
				}
			}
			/*if (it->second.get_approval() == true) {
				if (it->second.get_location() == loc)
				{
					cout << "========================================\n" << count++ << ":\n";
					cout << "Price   : " << it->second.get_price() << "$\n";
					cout << "Location: " << it->second.get_location() << "\n";
					cout << "Area   : " << it->second.get_area() << " meters\n";
					cout << "Rooms   : " << it->second.get_rooms() << "\n";
					cout << "Owner   : " << it->second.get_owner() << "\n";
					cout << "Furniture   : ";
					if (it->second.get_furniture() == true)
					{
						cout << "YES" << "\n";
					}
					else
					{
						cout << "NO" << "\n";
					}
					cout << "========================================\n";
				}
			}*/
		}
	}
	else if (filter == 3)//area
	{
		multimap<int, properties> filter_map;
		unordered_map<int, int> prop_owner_id;

		int min, max;

		while (true)
		{
			cout << "Enter Minumum Area Value : " << endl;
			cout << "---------------------------" << endl;
			cin >> min;
			cout << "Enter maximum Area Value : " << endl;
			cout << "---------------------------" << endl;
			cin >> max;
			if (min >= max)
			{
				cout << "!! INVALID AREA RANGE!!" << endl << endl;
			}
			else
			{
				break;
			}
		}

		for (auto it = listOfProperties.begin(); it != listOfProperties.end(); it++)
		{
			if (it->first != this->id)
			{
				for (int i = 0; i < it->second.size(); i++)
				{
					if (it->second[i].get_area() >= min && it->second[i].get_approval() && it->second[i].get_area() <= max)
					{
						filter_map.insert({ it->second[i].get_area() , it->second[i] });
						prop_owner_id.insert({ it->second[i].get_id() , it->first });
					}
				}
			}

			/*if (it->second.get_area() >= min && it->second.get_area() <= max)
			{
				filter_map.insert({ it->second.get_area() , it->second });
			}*/

			for (auto it = filter_map.begin(); it != filter_map.end(); it++)
			{
				display_property(prop_owner_id[it->second.get_id()], it->second);
			}
		}

	}
	else if (filter == 4)//rooms
	{
		multimap<int, properties> filter_map;
		unordered_map<int, int> prop_owner_id;

		int min, max;

		while (true)
		{
			cout << "Enter Minumum Number Of Rooms : " << endl;
			cout << "---------------------------" << endl;
			cin >> min;
			cout << "Enter maximum Number Of Rooms : " << endl;
			cout << "---------------------------" << endl;
			cin >> max;
			if (min >= max)
			{
				cout << "!! INVALID INPUT RANGE!!" << endl << endl;
			}
			else
			{
				break;
			}
		}

		for (auto it = listOfProperties.begin(); it != listOfProperties.end(); it++)
		{
			if (it->first != this->id)
			{
				for (int i = 0; i < it->second.size(); i++)
				{
					if (it->second[i].get_rooms() >= min && it->second[i].get_approval() && it->second[i].get_rooms() <= max)
					{
						filter_map.insert({ it->second[i].get_rooms() , it->second[i] });
						prop_owner_id.insert({ it->second[i].get_id() , it->first });
					}
				}
			}

			/*if (it->second.get_rooms() >= min && it->second.get_rooms() <= max)
			{
				filter_map.insert({ it->second.get_rooms() , it->second });
			}*/

		}

		for (auto it = filter_map.begin(); it != filter_map.end(); it++)
		{
			display_property(prop_owner_id[it->second.get_id()], it->second);
		}

	}
	else if (filter == 5)//furniture
	{
		bool furn_bool;
		string furn;

		cout << "Do You Want The Properties to be Furnished ?(yes/no)" << endl;
		cout << "------------------------------------------------------" << endl;
		cin >> furn;
		if (furn == "yes" || furn == "Yes" || furn == "y" || furn == "Y")
		{
			furn_bool = true;
		}
		else if (furn == "no" || furn == "No" || furn == "n" || furn == "N")
		{
			furn_bool = false;
		}


		
		for (auto it = listOfProperties.begin(); it != listOfProperties.end(); it++)
		{
			if (it->first != this->id)
			{
				for (int i = 0; i < it->second.size(); i++)
				{
					if (it->second[i].get_approval() && it->second[i].get_furniture() == furn_bool)
					{
						display_property(it->first, it->second[i]);
					}
				}
			}
		}

	}
	// else if (filter == 6) {
	// 	int count = 1;
	// 	for (auto it = listOfProperties.begin(); it != listOfProperties.end(); it++)
	// 	{
	// 		if (it->second.get_approval() == false) {
	// 			cout << "========================================\n" << count++ << ":\n";
	// 			cout << "Price   : " << it->second.get_price() << "$\n";
	// 			cout << "Location: " << it->second.get_location() << "\n";
	// 			cout << "Area   : " << it->second.get_area() << " meters\n";
	// 			cout << "Rooms   : " << it->second.get_rooms() << "\n";
	// 			cout << "Owner   : " << it->second.get_owner() << "\n";
	// 			cout << "Furniture   : ";
	// 			if (it->second.get_furniture() == true)
	// 			{
	// 				cout << "YES" << "\n";
	// 			}
	// 			else
	// 			{
	// 				cout << "NO" << "\n";
	// 			}
	// 			cout << "========================================\n";
	// 		}
	// 	}
	// }

}


void user::display_property(int user_id, properties prop)
{
	cout << "========================================\n" << user_id << prop.get_id() << ":\n";
	cout << "Price   : " << prop.get_price() << "$\n";
	cout << "Location: " << prop.get_location() << "\n";
	cout << "Area   : " << prop.get_area() << " meters\n";
	cout << "Rooms   : " << prop.get_rooms() << "\n";
	cout << "Owner   : " << prop.get_owner() << "\n";
	cout << "Furniture   : ";
	if (prop.get_furniture() == true)
	{
		cout << "YES" << "\n";
	}
	else
	{
		cout << "NO" << "\n";
	}
	cout << "========================================\n";
}

void user::ShowUserMenu()
{
	cout << "========================================\n";
	cout << "          Property User Panel         \n";
	cout << "========================================\n";
	cout << "Please choose an action from the list below:\n\n";
	cout << "  [1] Add New Property\n";
	cout << "  [2] Search For Properties\n";
	cout << "  [0] Logout / Exit\n";
}