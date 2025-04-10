#include "Aleynik_LR3-4_ClassMolecule.cpp"

using namespace std;

struct menuItem {
    string title;
    function<void()> action;
};

int main() {
    map <int, menuItem> menu = {
        {1, {"Create molecule constructor", addMolecule}},
        {2, {"Create random molecule constructor", addRandomMolecule}},
        {3, {"Display all molecules", displayMolecule}},
        {4, {""}}
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
