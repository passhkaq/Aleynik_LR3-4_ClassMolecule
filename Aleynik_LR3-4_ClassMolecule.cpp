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
Molecule::~Molecule() {};
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

Molecule Molecule::operator++(int) {
    Molecule temp = *this;
    ++(*this);
    return temp;
}

Molecule Molecule::operator--(int) {
    Molecule temp = *this;
    --(*this);
    return temp;
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
        moleculeMass = other.moleculeMass;
    }
    return *this;
}

ostream& operator << (ostream& os, const Molecule &obj) {
    os << "Molecule: " << obj.moleculeName << endl;
    os << "Atoms: " << endl;
    for (const auto& atom : obj.atomList) {
        os << "  " << atom.first << ": " << atom.second << endl;
    }
    os << "Molecular mass: " << obj.moleculeMass << endl;
    return os;
}

istream& operator >> (istream& is, Molecule &obj) {
    string name;
    int numAtoms;
    enterString(name, "Enter molecule name: ", is);
    obj.setMolName(name);

    enterInteger(numAtoms, "Enter number of atoms: ", 0, 100, is);

    vector<pair<string, double>> atoms;
    for (int i = 0; i < numAtoms; ++i) {
        string atomName;
        int count;
        enterString(atomName, "Enter atom name " + to_string(i + 1) + ": ", is);
        enterInteger(count, "Enter count for " + atomName + ": ", 0, 100, is);
        atoms.push_back({atomName, count});
    }

    obj.setAtoms(atoms);
    obj.setMolMass(atoms);
    return is;
}

//methods



