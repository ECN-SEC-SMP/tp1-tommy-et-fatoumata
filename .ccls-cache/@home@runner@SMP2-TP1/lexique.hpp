#ifndef lexique_hpp
#define lexique_hpp

#include <iostream>
#include <string>
#include <map>
#include <ostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class Lexique 
{
protected:
    std::string nom;
    std::map<std::string, int> mot_lexique; 
// Map pour stocker les mots et leurs occurrences

public:
    Lexique(std::string nom);
    void splitStringIntoWords(const string &str, vector<string> &tab);
    void save();
    void suppMot(const string &mot_lexique);
    int NombreDifferentMot();
    void affiche_lexique();
    int testerPresenceMot(const std::string &mot);
    void operator+=(const Lexique &a);
    void operator-=(const Lexique &a);
    friend ostream& operator<<(ostream &s, const Lexique &c);
};

#endif 