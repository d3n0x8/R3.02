#include "livre.hpp"

// Default constructor
Livre::Livre() : titre(""), auteur(""), anneeParution(0), nbrPages(0) {}

// Parameterized constructor
Livre::Livre(string titre, string auteur, int anneeParution, int nbrPages)
    : titre(titre), auteur(auteur), anneeParution(anneeParution),
      nbrPages(nbrPages) {}

// Getter methods
string Livre::getTitre() { return titre; }
string Livre::getAuteur() { return auteur; }
int Livre::getAnneeParution() { return anneeParution; }
int Livre::getNbrPages() { return nbrPages; }
