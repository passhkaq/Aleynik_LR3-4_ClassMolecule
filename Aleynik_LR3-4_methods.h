#ifndef _METHODS_H_
#define _METHODS_H_

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <numeric>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

vector<Molecule> vectorMolecule;

vector<pair<string, vector<pair<string, double>>>> randomMoleculeList = {
    { "H2O", {{"H", 2}, {"O", 1}} },
    { "CO2", {{"C", 1}, {"O", 2}} },
    { "Glucose", {{"C", 6}, {"H", 12}, {"O", 6}} },
    { "H2SO4", {{"H", 2}, {"S", 1}, {"O", 4}} },
    { "CH4", {{"C", 1}, {"H", 4}} }
};

// entr check
bool userInput(string input, const int& min, const int& max) {
    if (input.empty()) return false;

    try {
        int number = stoi(input);
        if (number < min) {
            cout << "Minimum valid number is " << min << endl;
            return false;
        } else if (number > max) {
            cout << "Maximum valid number is " << max << endl;
            return false;
        }
    } catch (const exception& e) {return false;};
    return true;
}

void enterInteger(int& variable, const string& prompt, const int& min, const int& max) {
    string input;
    cout << prompt;
    getline(cin, input);

    while(!(userInput(input, min, max))) {
        cout << prompt;
        getline(cin, input);
    }
    variable = stoi(input);
}

void enterFloat(double& variable, const string& prompt, const int& min, const int& max) {
    string input;
    cout << prompt;
    getline(cin, input);

    while(!(userInput(input, min, max))) {
        cout << prompt;
        getline(cin, input);
    }
    variable = stof(input);
}

void enterString(string& variable, const string& prompt) {
    cout << prompt;
    getline(cin, variable);
}

void Molecule::display() const {
    cout << "Molecule name is " << moleculeName << endl;
    cout << "It has " << atomList.size() << " atoms:" << endl;
    for (const auto& item : atomList) {
        cout << setw(5) << item.first << ": " << item.second << endl;
    }
}

void displayMolecule() {
    for (const auto item : vectorMolecule) {
        item.display();
    }
}

Molecule Molecule::input() {
    string name;
    enterString(name, "Enter molecule name: ");

    int numAtoms;
    enterInteger(numAtoms, "Enter number of atoms: ", 1, 100);

    vector<pair<string, double>> atoms;
    for (int i = 0; i < numAtoms; ++i) {
        string atomName;
        double count;
        enterString(atomName, "Enter atom name: ");
        enterFloat(count, "Enter atom count: ", 1, 100);
        atoms.push_back({atomName, count});
    }

    return Molecule(name, atoms);
}

void addMolecule() {
    vectorMolecule.emplace_back(Molecule::input());
}

Molecule createRandomMolecule() {
    int randomIndex = rand() % randomMoleculeList.size();
    const auto& [name, atoms] = randomMoleculeList[randomIndex];
    return Molecule(name, atoms);
}

void addRandomMolecule() {
    vectorMolecule.emplace_back(createRandomMolecule());
}


#endif //_METHODS_H_
