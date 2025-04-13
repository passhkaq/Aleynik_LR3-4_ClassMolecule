#include "Aleynik_LR3-4_ClassMolecule.h"
#include "Aleynik_LR3-4_methods.h"

//constructors
Molecule::Molecule() : moleculeName("Unknown"), atomList({}), moleculeMass(0) {}

Molecule::Molecule(string molName) : moleculeName(molName), atomList({}), moleculeMass(0) {}

Molecule::Molecule(string molName, vector<pair<string, double>> atoms, int molMass)
    : moleculeName(molName), atomList(atoms) {
    setMolMass(atoms);
}
Molecule::Molecule(const Molecule& other)
    : moleculeName(other.moleculeName), atomList(other.atomList), moleculeMass(other.moleculeMass) {}

//overloaded operators
const bool Molecule::operator > (const Molecule& other) const { return other.moleculeMass > this->moleculeMass; }

const bool Molecule::operator < (const Molecule& other) const { return other.moleculeMass < this->moleculeMass; }

Molecule Molecule::operator ++ () {
    ++moleculeMass;
    return *this;
}

Molecule Molecule::operator -- () {
    --moleculeMass;
    return *this;
}

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
    mystream << "Molecular mass: " << obj.moleculeMass << endl;
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



