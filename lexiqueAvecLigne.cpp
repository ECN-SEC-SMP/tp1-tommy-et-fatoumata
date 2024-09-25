#include <sstream>
#include "lexiqueAvecLigne.hpp"
#include <iostream>

void LexiqueAvecLigne::splitStringIntoWords(const std::string &str,int lineNumber) {
  std::istringstream stream(str);
  std::string word;
  while (stream >> word) {
    mot_lexique[word]++;                // Compter les occurrences
    lignes[word].push_back(lineNumber); // Ajouter le numéro de ligne
  }
}

void LexiqueAvecLigne::afficherLignesMot(const std::string &mot) const {
  auto it = lignes.find(mot);
  if (it != lignes.end()) {
    std::cout << "Le mot '" << mot << "' a été trouvé aux lignes : ";
    for (const auto &line : it->second) {
      std::cout << line << " ";
    }
    std::cout << std::endl;
  } else {
    std::cout << "Le mot '" << mot << "' n'a pas été trouvé." << std::endl;
  }
}

std::ostream &operator<<(std::ostream &s, const LexiqueAvecLigne &c) {
  for (const auto &pair : c.mot_lexique) {
    s << pair.first << ": " << pair.second << " (lignes: ";
    for (const auto &line : c.lignes.at(pair.first)) {
      s << line << " ";
    }
    s << ")\n";
  }
  return s;
}
