#include<set>
#include "admin.h"
#include "properties.h"
#include "user.h"
#include <unordered_map>
#include <vector>
void showAdminMenu() {
    cout << "========================================\n";
    cout << "         🏠 Property Admin Panel         \n";
    cout << "========================================\n";
    cout << "Please choose an action from the list below:\n\n";
    cout << "  [1] ➕ Add New Property\n";
    cout << "  [2] ✏️  Edit Existing Property\n";
    cout << "  [3] ❌ Delete Property\n";
    cout << "  [4] 📋 Show All Properties\n";
    cout << "  [0] 🚪 Logout / Exit\n";
}
int main(int argc, char *argv[]) {
    //multi set that saves the properties sorted using pointer function
unordered_map<int, vector<properties> > listOfProperties;
   char n;
   bool check=false;
    int choice,id;
    user obj;
	int user_id;


/*int id_counter = 0;*/
   

    
  while (true)
  {
	
   while (true) {
       showAdminMenu();
       cin>>n;
       if (!(n>='0'&&n<='5')) {
           cout<<"Invalid input please try again"<<endl;
       }else{
           switch (n) {
            //    case '1':admin::add_prop(property_set);
            //    break;
            //    case '2':admin::update_prop();
            //    break;
            //    case '3':admin::delete_prop();
            //    break;
            //    case '4':admin::all_prop(property_set);
            //    break;
               case '0':
                   check=true;
                        break;
			   case '5':
               obj.filter_search(6, listOfProperties);
                    cout << "Choose Property to approve" << endl;
                    cout<<"enter the user id: \n";
					cin >> user_id;
					cout << "Enter The Property Id:" << endl;
					cin >> id;
                    for (auto it = listOfProperties.begin(); it != listOfProperties.end(); it++) {
						if (user_id == it->first) {
							it->second[id].set_approval(true);
							break;
						}
						else {
							cout << "There is no User with This id" << endl;
						}
                    }
					cout << "Approved Successfully!!" << endl;
                        break;
           }
           if (check) break;
       }
   }
   while (true)
{
	

	obj.ShowUserMenu();
	cin >> choice;
	if (choice == 1)
	{
		properties temp = obj.add_prop();

		/*id_counter++;*/
		/*if (listOfProperties[obj.get_id()].);*/

		listOfProperties[obj.get_id()].push_back(temp);

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
		//admin::all_prop(listOfProperties);
		obj.filter_search(filter, listOfProperties);

	}
	else
	{
		break;
	}
  }
  

}
return 0;
}

