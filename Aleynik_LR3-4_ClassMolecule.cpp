#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <numeric>
#include <fstream>
#include <sstream>
#include "Aleynik_LR3-4_ClassMolecule.h"
#include "Aleynik_LR3-4_methods.h"

using namespace std;


//constructors
Molecule::Molecule() : Molecule("Unknown", {}) {};
Molecule::Molecule(string molName) : Molecule(molName, {}) {};
Molecule::Molecule(string molName, vector<pair<string, double>> atoms) : Molecule(molName) {
    setAtoms(atoms);
}
Molecule::Molecule(const Molecule& other)
    : moleculeName(other.moleculeName), atomList(other.atomList) {};

//overloaded operators
// const bool Molecule::operator > (const Molecule& other) const { return  }
// const bool Molecule::operator < (const Molecule& other) const { return  }

Molecule Molecule::operator + (const Molecule& other) const {
    Molecule result(moleculeName + "+" + other.moleculeName);
    map<string, double> combinedAtoms;

    for (const auto& atom : atomList) {
        combinedAtoms[atom.first] += atom.second;
    }

    for (const auto& atom : other.atomList) {
        combinedAtoms[atom.first] += atom.second;
    }

    vector<pair<string, double>> resultAtoms;
    for (const auto& [atom, count] : combinedAtoms) {
        resultAtoms.push_back({atom, count});
    }

    result.setAtoms(resultAtoms);
    return result;
}

const Molecule& Molecule::operator = (const Molecule& other) {
    if (this != &other) {
        moleculeName = other.moleculeName;
        atomList = other.atomList;
    }
    return *this;
}

ostream& operator << (ostream& mystream, const Molecule &obj) {
    mystream << "Molecule: " << obj.moleculeName << endl;
    mystream << "Atoms: " << endl;
    for (const auto& atom : obj.atomList) {
        mystream << "  " << atom.first << ": " << atom.second << endl;
    }
    return mystream;
}

istream& operator >> (istream& mystream, Molecule &obj) {
    string name;
    int numAtoms;
    cout << "Enter molecule name: ";
    mystream >> name;
    obj.setMolName(name);

    cout << "Enter number of atoms: ";
    mystream >> numAtoms;

    vector<pair<string, double>> atoms;
    for (int i = 0; i < numAtoms; ++i) {
        string atomName;
        int count;
        cout << "Enter atom name " << i + 1 << ": ";
        mystream >> atomName;
        cout << "Enter count for " << atomName << ": ";
        mystream >> count;
        atoms.push_back({atomName, count});
    }

    obj.setAtoms(atoms);
    return mystream;
}

//methods
int Molecule::calculateMolecularFormula(const Molecule& obj) const {
    int result = 0;
    for (const auto& item : atomList) {
        result += item.second;
    }
    result /= atomList.size();
    return result;
}

void Molecule::displayMolecularFormula() {
    cout << "The molecular formula is an average of all the atoms in a molecule." << endl;
}



