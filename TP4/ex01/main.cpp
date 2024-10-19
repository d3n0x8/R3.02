#include "abin.hpp"
#include <iostream>
using namespace std;

int main() {
  Abin a1 = Abin::enracine(7, Abin::arbnouv(), Abin::arbnouv());
  Abin a2 = Abin::enracine(1, Abin::arbnouv(), Abin::arbnouv());

  Abin a3 = Abin::enracine(8, a1, a2);

  Abin a4 = Abin::enracine(5, Abin::arbnouv(), Abin::arbnouv());

  Abin arbre = Abin::enracine(3, a4, a3);

  cout << "Parcours prefixe de l'arbre : ";

  arbre.parcours_prefixe(arbre);

  cout << endl;

  return 0;
}
