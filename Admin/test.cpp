#include<set>
#include "admin.h"
#include "properties.h"

bool compare(const properties& a,const properties& b) {
    return a.get_price() < b.get_price();
}
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
    multiset<properties,bool(*)(const properties& a,const  properties& b)> property_set(compare);
    char n;
    bool check=false;
    while (true) {
        showAdminMenu();
        cin>>n;
        if (!(n>='0'&&n<='4')) {
            cout<<"Invalid input please try again"<<endl;
        }else{
            switch (n) {
                case '1':admin::add_prop(property_set);
                break;
                case '2':admin::update_prop();
                break;
                case '3':admin::delete_prop();
                break;
                case '4':admin::all_prop(property_set);
                break;
                case '0':
                    check=true;
                         break;
            }
            if (check) break;
        }
    }
    return 0;
}

