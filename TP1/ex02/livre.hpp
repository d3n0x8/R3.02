#include <cstdlib>
#include <string>
using namespace std;

class Livre {

private:
  string titre;
  string auteur;
  int anneeParution;
  int nbrPages;

public:
  Livre();
  Livre(string titre, string auteur, int anneeParution, int nbrPages);
  ~Livre();
  string getTitre();
  string getAuteur();
  int getAnneeParution();
  int getNbrPages();
};