#include "livre.hpp"

Livre::Livre() : titre(""), auteur(""), anneeParution(0), nbrPages(0) {}

Livre::Livre(string titre, string auteur, int anneeParution, int nbrPages)
    : titre(titre), auteur(auteur), anneeParution(anneeParution),
      nbrPages(nbrPages) {}

string Livre::getTitre() { return titre; }
string Livre::getAuteur() { return auteur; }
int Livre::getAnneeParution() { return anneeParution; }
int Livre::getNbrPages() { return nbrPages; }
