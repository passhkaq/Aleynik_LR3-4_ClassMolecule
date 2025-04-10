#ifndef _MOLECULE_H_
#define _MOLECULE_H_

class Molecule {
    private:
        string moleculeName;
        vector<map<string, int>> atomList;
    public:
        //constructors
        Molecule();
        Molecule(string molName);
        Molecule(string molName, vector<map<string, int>> atoms);
        Molecule(const Molecule& other);
        ~Molecule();
        //setters/getters
        void setMolName(string molName);
        void setAtoms(vector<map<string, int>> atomList);
        const string& getMolName() const;
        const vector<map<string, int>>& getAtoms() const;
        //overloaded operators
        const bool operator > (const Molecule& other) const;
        const bool operator < (const Molecule& other) const;
        Molecule operator + (const Molecule& other) const;
        const Molecule& operator = (const Molecule& other);
        Molecule operator ++ ();
        Molecule operator -- ();
        friend ostream& operator >> (ostream& mystream, Molecule &obj);
        friend ostream& operator << (ostream& mystream, const Molecule &obj);
};

#endif //_MOLECULE_H_
