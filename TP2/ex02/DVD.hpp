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
  string getArtiste() const override { return this->realisateur; };
  int getAnnee() const override { return this->anneeParution; };
  string getGenre() const override { return "DVD"; };
  string getInfo() const override {
    return "Media: " + getGenre() + ", Titre: " + titre +
           ", Realisateur: " + realisateur +
           ", Annee de parution: " + to_string(anneeParution) +
           ", Durée du film: " + to_string(duree) + " minutes";
  };
};