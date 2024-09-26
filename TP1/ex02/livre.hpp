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
  string getTitre();
  string getAuteur();
  int getAnneeParution();
  int getNbrPages();
};