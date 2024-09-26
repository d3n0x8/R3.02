#include "livre.hpp"
#include <cstdlib>

Livre::Livre() : titre(""), auteur(""), anneeParution(0), nbrPages(0) {}

Livre::Livre(string titre, string auteur, int anneeParution, int nbrPages) {
  this->titre = titre;
  this->auteur = auteur;
  this->anneeParution = anneeParution;
  this->nbrPages = nbrPages;
}

Livre::~Livre() {}

string Livre::getTitre() { return this->titre; }
string Livre::getAuteur() { return this->auteur; }
int Livre::getAnneeParution() { return this->anneeParution; }
int Livre::getNbrPages() { return this->nbrPages; }
