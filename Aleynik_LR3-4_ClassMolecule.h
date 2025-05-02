#ifndef _MOLECULE_H_
#define _MOLECULE_H_

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <numeric>
#include <fstream>
#include <sstream>

using namespace std;

class Molecule {
    private:
        string moleculeName;
        vector<pair<string, double>> atomList;
        int moleculeMass;
    public:
        //constructors
        Molecule();
        Molecule(string molName);
        Molecule(string molName, vector<pair<string, double>> atoms, int molMass);
        Molecule(const Molecule& other);
        ~Molecule();

        //setters/getters
        void setMolName(string molName) { moleculeName = molName; }
        void setAtoms(vector<pair<string, double>> atoms) {
            this->atomList = atoms;
        }
        void setMolMass(vector<pair<string, double>> atoms) {
            int result = 0;
            for (const auto& item : atomList) {
                result += item.second;
            }
            moleculeMass = result / atomList.size();

        }
        const string& getMolName() const { return moleculeName; }
        const vector<pair<string, double>>& getAtoms() const { return atomList; }
        const int& getMolMass() const { return moleculeMass; }

        //overloaded operators
        const bool operator > (const Molecule& other) const;
        const bool operator < (const Molecule& other) const;
        Molecule operator + (const Molecule& other) const;
        const Molecule& operator = (const Molecule& other);
        Molecule operator ++ ();
        Molecule operator -- ();
        Molecule operator ++ (int);
        Molecule operator -- (int);
        friend ostream& operator << (ostream& mystream, const Molecule &obj);
        friend istream& operator >> (istream& mystream, Molecule &obj);

        //methods

};

#endif //_MOLECULE_H_
