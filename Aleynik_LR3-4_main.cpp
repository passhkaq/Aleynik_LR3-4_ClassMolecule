#include "Aleynik_LR3-4_ClassMolecule.cpp"

using namespace std;

struct menuItem {
    string title;
    function<void()> action;
};

int main() {
    map <int, menuItem> menu = {

    };

    int choice = 0;

    while (true) {
        cout << "Menu: " << endl;

        for (const auto& item : menu) {
            cout << item.first << ". " << item.second.title << endl;
        }
        cout << "0. Exit" << endl;


    }




    return 0;
}
