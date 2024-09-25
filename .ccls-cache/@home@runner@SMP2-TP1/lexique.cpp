#include <vector>
#include <algorithm>
#include "lexique.hpp"


Lexique::Lexique(std::string nom) : nom(nom) {}

void Lexique::splitStringIntoWords(const string &str, vector<string> &tab) {
    istringstream stream(str);
    string word;
    while (stream >> word) {
        tab.push_back(word);
        mot_lexique[word]++; // Incrementer l'occurrence du mot
    }
}

void Lexique::save() {
    std::ofstream myfile(nom);  // Utiliser le nom de fichier
    if (myfile.is_open()) {
        for (const auto &pair : mot_lexique) {
            myfile << pair.first << " " << pair.second << "\n";  // Écrire le mot et son nombre d'occurrences
        }
        myfile.close();
        std::cout << "Fichier créé et sauvegardé avec succès." << std::endl;
    } else {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
    }
}

void Lexique::suppMot(const string &mot_lexique) {
    this->mot_lexique.erase(mot_lexique); // Supprimer le mot du lexique
}

int Lexique::NombreDifferentMot() {
    return mot_lexique.size(); // Retourne le nombre de mots différents
}

void Lexique::affiche_lexique() {
    for (const auto &pair : mot_lexique) {
        cout << pair.first << ": " << pair.second << endl; // Affiche chaque mot et son nombre d'occurrences
    }
}

int Lexique::testerPresenceMot(const std::string &mot) {
    return mot_lexique[mot]; // Retourne le nombre d'occurrences du mot
}

void Lexique::operator+=(const Lexique &a) {
    for (const auto &pair : a.mot_lexique) {
        mot_lexique[pair.first] += pair.second; // Fusionner les occurrences
    }
}

void Lexique::operator-=(const Lexique &a) {
    for (const auto &pair : a.mot_lexique) {
        mot_lexique.erase(pair.first); // Supprimer les mots présents dans le second lexique
    }
}

ostream& operator<<(ostream &s, const Lexique &c) {
    for (const auto &pair : c.mot_lexique) {
        s << pair.first << ": " << pair.second << endl; // Afficher chaque mot et son nombre d'occurrences
    }
    return s;
}