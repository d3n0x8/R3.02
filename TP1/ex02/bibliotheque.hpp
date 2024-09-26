#include "livre.hpp"
using namespace std;
class Bibliotheque {

private:
  const static int nombreLivreMaximum = 50;
  Livre livres[nombreLivreMaximum];
  int nbrLivres;

public:
  Bibliotheque();
  int size();
  void ajouterLivre(Livre livre);
  void supprimerLivre(Livre livre);

  void afficheLivre();
  void rechercherLivre(string titre);
};
