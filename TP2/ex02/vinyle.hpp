#include "media.hpp"

using namespace std;

class Vinyle : public Media {

private:
  string titre;
  string chanteur;
  int anneeParution;
  int nbrTitres;

public:
  Vinyle() : titre(""), chanteur(""), anneeParution(0), nbrTitres(0) {}
  Vinyle(string &titre, string &chanteur, int anneeParution, int nbrTitres) {
    this->titre = titre;
    this->chanteur = chanteur;
    this->anneeParution = anneeParution;
    this->nbrTitres = nbrTitres;
  };
  ~Vinyle(){};

  string getTitre() const override { return this->titre; };
  string getArtiste() const override { return this->chanteur; };
  int getAnnee() const override { return this->anneeParution; };
  string getGenre() const override { return "Vinyle"; };

  string getInfo() const override {
    return "Media: " + getGenre() + ", Titre: " + titre +
           ", Chanteur: " + chanteur +
           ", Annee de parution: " + to_string(anneeParution) +
           ", Nombre de titres: " + to_string(nbrTitres);
  };
};