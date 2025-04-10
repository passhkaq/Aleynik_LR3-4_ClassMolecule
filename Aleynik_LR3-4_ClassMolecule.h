#ifndef _MOLECULE_H_
#define _MOLECULE_H_

class Molecule {
    private:
        string moleculeName;
        vector<pair<string, double>> atomList;
    public:
        //constructors
        Molecule();
        Molecule(string molName);
        Molecule(string molName, vector<pair<string, double>> atoms);
        Molecule(const Molecule& other);
        ~Molecule();

        //setters/getters
        void setMolName(string molName) { moleculeName = molName; };
        void setAtoms(vector<pair<string, double>> atoms) {
            this->atomList = atoms;
        };
        const string& getMolName() const { return moleculeName; };
        const vector<pair<string, double>>& getAtoms() const { return atomList; };

        //overloaded operators
        const bool operator > (const Molecule& other) const;
        const bool operator < (const Molecule& other) const;
        Molecule operator + (const Molecule& other) const;
        const Molecule& operator = (const Molecule& other);
        Molecule operator ++ ();
        Molecule operator -- ();
        friend ostream& operator << (ostream& mystream, const Molecule &obj);
        friend istream& operator >> (istream& mystream, Molecule &obj);

        //methods
        int calculateMolecularFormula(const Molecule& obj) const;
        void displayMolecularFormula();
};

#endif //_MOLECULE_H_
