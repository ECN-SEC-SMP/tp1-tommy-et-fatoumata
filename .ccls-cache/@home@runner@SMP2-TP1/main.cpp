#include "lexique.hpp"
#include "utilitaire.hpp"
#include "lexiqueAvecLigne.hpp"
#include <iostream>
#include <vector>
using namespace std;
/*
int main() {
  vector<string> tab;
  string content;
  string motRecherche;
  string motSupp;

  Lexique lexique("lexique.txt");

  readFileIntoString("lesMiserables_A.txt", content);
  remove_punctuation(content);
  toLower(content);

  // Split the content into words and add to lexique
  lexique.splitStringIntoWords(content, tab);
  lexique.save();

  cout << "Entrez un mot à rechercher : " << endl;
  cin >> motRecherche;
  int occurrences = lexique.testerPresenceMot(motRecherche);
  cout << "Le nombre de fois où le mot '" << motRecherche
       << "' apparait dans le lexique est de : " << occurrences << endl;

  cout << "Entrez un mot à supprimer : " << endl;
  cin >> motSupp;
  lexique.suppMot(motSupp);
  cout << "Le mot : " << motSupp << " a été supprimé." << endl;

  lexique.affiche_lexique();

  cout << "Nombre de mots différents dans le lexique : "
       << lexique.NombreDifferentMot() << endl;

  // cout << "Contenu du lexique : " << lexique << std::endl;

  return 0;
}*/


//Jeux d'essais : 
/*int main() {
    // Créer des lexiques
    Lexique lexique1("lexique1.txt");
    Lexique lexique2("lexique2.txt");

   vector<string> tab;
   vector<string> tab2;

    string content1 = "apple banana apple orange banana";
    string content2 = "banana orange pear apple";

    // Remplir les lexiques
    lexique1.splitStringIntoWords(content1, tab);
    lexique2.splitStringIntoWords(content2, tab2);

    cout << "Lexique 1 avant fusion:\n" << lexique1 << endl;
    cout << "Lexique 2 avant fusion:\n" << lexique2 << endl;

    // Fusionner lexique1 et lexique2
    lexique1 += lexique2;
    cout << "Lexique 1 après fusion avec Lexique 2:\n" << lexique1 << endl;

    // Différence entre lexique1 et lexique2
    lexique1 -= lexique2;
    cout << "Lexique 1 après différence avec Lexique 2:\n" << lexique1 << endl;


    return 0;
}*/




int main() {
    LexiqueAvecLigne lexique("lexique_avec_lignes.txt");

    ifstream fichier("notreDameDeParis_A.txt");
    string ligne;
    int lineNumber = 0;

    while (getline(fichier, ligne)) {
        lineNumber++;
        lexique.splitStringIntoWords(ligne, lineNumber); // Ajouter des mots et numéro de ligne
    }

    cout << "Contenu du lexique avec lignes :\n";
    cout << lexique << endl; // Afficher le lexique

    string motRecherche;
    cout << "Entrez un mot pour afficher ses lignes : ";
    cin >> motRecherche;
    lexique.afficherLignesMot(motRecherche); // Afficher les lignes pour le mot donné

    return 0;
}