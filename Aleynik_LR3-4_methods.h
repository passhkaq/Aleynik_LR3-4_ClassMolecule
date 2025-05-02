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

void enterInteger(int& variable, const string& prompt, const int& min = 0, const int& max = 10000000, istream& is = cin) {
    string input;
    cout << prompt;
    getline(is, input);

    while(!(userInput(input, min, max))) {
        cout << prompt;
        getline(is, input);
    }
    variable = stoi(input);
}

void enterFloat(double& variable, const string& prompt, const int& min, const int& max, istream& is = cin) {
    string input;
    cout << prompt;
    getline(is, input);

    while(!(userInput(input, min, max))) {
        cout << prompt;
        getline(is, input);
    }
    variable = stof(input);
}

void enterString(string& variable, const string& prompt, istream& is = cin) {
    cout << prompt;
    string input;
    getline(is, input);
    variable = input;
}

void displayMolecule() {
    for (const auto item : vectorMolecule) {
        cout << item;
    }
}

void addMolecule() {
    Molecule Molecule_1;
    cin >> Molecule_1;
    vectorMolecule.emplace_back(Molecule_1);
}

Molecule createRandomMolecule() {
    int randomIndex = rand() % randomMoleculeList.size();
    const auto& [name, atoms] = randomMoleculeList[randomIndex];
    return Molecule(name, atoms, 0);
}

void addRandomMolecule() {
    vectorMolecule.emplace_back(createRandomMolecule());
}

void displayMolecularFormula() {
    cout << "The molecular formula is an average of all the atoms in a molecule." << endl;
}

void postInkr() {
    for (auto& item : vectorMolecule) {
        item++;
    }
}

void prefInkr() {
    for (auto& item : vectorMolecule) {
        ++item;
    }
}

void postDekr() {
    for (auto& item : vectorMolecule) {
        item--;
    }
}

void prefDekr() {
    for (auto& item : vectorMolecule) {
        --item;
    }
}

void plus() {
    if (sizeof(vectorMolecule) < 1) {return;}
    int choice = 0, choice2 = 0;
    enterInteger(choice, "Enter num: ", 0, sizeof(vectorMolecule));
    enterInteger(choice2, "Enter num 2: ", 0, sizeof(vectorMolecule));
    Molecule result = vectorMolecule[choice] + vectorMolecule[choice2];
    vectorMolecule.emplace_back(result);
}

void ravno() {
    int choice = 0, choice2 = 0;
    enterInteger(choice, "Enter num: ", 0, sizeof(vectorMolecule));
    Molecule result;
    result = vectorMolecule[choice];
    vectorMolecule.emplace_back(result);
}

void bolshe() {
    int choice = 0, choice2 = 0;
    enterInteger(choice, "Enter num: ", 0, sizeof(vectorMolecule));
    enterInteger(choice, "Enter num 2: ", 0, sizeof(vectorMolecule));
    bool result = vectorMolecule[choice] > vectorMolecule[choice2];
    cout << "Molecule: " << choice << " > Molecule: " << choice2 << " - " << result << endl;
}

void menshe() {
    int choice = 0, choice2 = 0;
    enterInteger(choice, "Enter num: ", 0, sizeof(vectorMolecule));
    enterInteger(choice, "Enter num 2: ", 0, sizeof(vectorMolecule));
    bool result = vectorMolecule[choice] < vectorMolecule[choice2];
    cout << "Molecule: " << choice << " < Molecule: " << choice2 << " - " << result << endl;
}

#endif //_METHODS_H_
