#include "media.hpp"

using namespace std;

class DVD : public Media {

private:
  string titre;
  string realisateur;
  int anneeParution;
  int duree;

public:
  DVD() : titre(""), realisateur(""), anneeParution(0), duree(0) {}
  DVD(string &titre, string &realisateur, int anneeParution, int duree) {
    this->titre = titre;
    this->realisateur = realisateur;
    this->anneeParution = anneeParution;
    this->duree = duree;
  };
  ~DVD(){};

  string getTitre() const override { return this->titre; };
  string getInfo() const override {
    return "Film: " + titre + ", Realisateur: " + realisateur +
           ", Annee de parution: " + to_string(anneeParution) +
           ", Durée du film: " + to_string(duree);
  };
};