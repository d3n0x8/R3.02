#include "chaine.hpp"

int main() {
  Chaine chaine = Chaine();
  chaine.adjtete(1);
  chaine.adjtete(2);
  chaine.adjtete(3);
  chaine.adjtete(4);
  chaine.affiche();
  chaine.adjqueue(5);
  chaine.affiche();
  chaine.adjpos(3, 3);
  chaine.affiche();
  chaine.suppos(2);
  chaine.affiche();

  return 0;
}