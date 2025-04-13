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
        {4, {"Display molecular formula", displayMolecularFormula}},
    };

    int choice = 0;

    while (true) {
        cout << "Menu: " << endl;

        for (const auto& item : menu) {
            cout << item.first << ". " << item.second.title << endl;
        }
        cout << "0. Exit" << endl;

        enterInteger(choice, "Enter your choice: ", 0, 4);

        if (choice == 0) {
            cout << "Poka Poka" << endl;
            break;
        } else {
            menu[choice].action();
        }

        cout << endl << endl;
    }




    return 0;
}
