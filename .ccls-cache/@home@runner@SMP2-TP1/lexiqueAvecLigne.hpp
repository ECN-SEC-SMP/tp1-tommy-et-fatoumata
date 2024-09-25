#ifndef lexiqueAvecLigne_hpp
#define lexiqueAvecLigne_hpp

#include "lexique.hpp"
#include <map>
#include <vector>

class LexiqueAvecLigne : public Lexique {
private:
    std::map<std::string, std::vector<int>> lignes; // Pour stocker les lignes où chaque mot a été rencontré

public:
    LexiqueAvecLigne(std::string nom) : Lexique(nom) {}

    void splitStringIntoWords(const std::string &str, int lineNumber); // Override to track line numbers
    void afficherLignesMot(const std::string &mot) const; // Afficher les lignes pour un mot donné
    friend std::ostream &operator<<(std::ostream &s, const LexiqueAvecLigne &c); // Surcharge pour afficher
};

#endif /* lexiqueAvecLigne_hpp */
