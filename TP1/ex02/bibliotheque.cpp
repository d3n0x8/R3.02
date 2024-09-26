#include "bibliotheque.hpp"
#include <iostream>

Bibliotheque::Bibliotheque() : nbrLivres() {}

int Bibliotheque::size() { return nbrLivres; }

void Bibliotheque::ajouterLivre(Livre livre) {
  if (nbrLivres < nombreLivreMaximum) {
    livres[nbrLivres] = livre;
    nbrLivres++;
  }
}

void Bibliotheque::supprimerLivre(Livre livre) {
  for (int i = 0; i < nbrLivres; i++) {
    if (livres[i].getTitre() == livre.getTitre()) {
      for (int j = i; j < nbrLivres - 1; j++) {
        livres[j] = livres[j + 1];
      }
      nbrLivres--;
      cout << "Le livre a bien été supprimé !" << endl;
      break;
    }
  }
  cout << "Le livre demandé n'existe pas !" << endl;
}

void Bibliotheque::afficheLivre() {
  cout << "\nListe des livres de la bibliothèque : " << endl;
  if (nbrLivres == 0) {
    cout << "\nAucun livre dans la bibliothèque !\n" << endl;
  }
  for (int i = 0; i < nbrLivres; i++) {
    cout << "Titre: " << livres[i].getTitre()
         << " ; auteur: " << livres[i].getAuteur()
         << " ; date de parution: " << livres[i].getAnneeParution()
         << " ; nombre de pages: " << livres[i].getNbrPages() << endl;
  }
  cout << endl;
}

void Bibliotheque::rechercherLivre(string titre) {
  for (int i = 0; i < nbrLivres; i++) {
    if (livres[i].getTitre() == titre) {
      cout << "Titre: " << livres[i].getTitre()
           << " ; auteur: " << livres[i].getAuteur()
           << " ; date de parution: " << livres[i].getAnneeParution()
           << " ; nombre de pages: " << livres[i].getNbrPages() << endl;
      return;
    }
  }
  cout << "Le livre demandé n'existe pas !" << endl;
}
