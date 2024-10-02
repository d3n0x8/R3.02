#include "media.hpp"

using namespace std;

class Livre : public Media {

private:
  string titre;
  string auteur;
  int anneeParution;
  int nbrPages;

public:
  Livre() : titre(""), auteur(""), anneeParution(0), nbrPages(0) {}
  Livre(string &titre, string &auteur, int anneeParution, int nbrPages) {
    this->titre = titre;
    this->auteur = auteur;
    this->anneeParution = anneeParution;
    this->nbrPages = nbrPages;
  };
  ~Livre(){};

  string getTitre() const override { return this->titre; };
  string getAuteur() { return this->auteur; };
  string getInfo() const override {
    return "Livre: " + titre + ", Auteur: " + auteur +
           ", Annee de parution: " + to_string(anneeParution) +
           ", Nombre de pages: " + to_string(nbrPages);
  };
};