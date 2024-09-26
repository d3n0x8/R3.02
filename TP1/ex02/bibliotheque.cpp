#include "bibliotheque.hpp"
#include <iostream>

Bibliotheque::Bibliotheque() : nbrLivres() {}

Bibliotheque::~Bibliotheque() {
  for (Livre livre : livres) {
    livre.~Livre();
  }
}

int Bibliotheque::size() { return this->nbrLivres; }

void Bibliotheque::ajouterLivre(Livre livre) {
  if (this->nbrLivres < nombreLivreMaximum) {
    this->livres[this->nbrLivres] = livre;
    this->nbrLivres++;
  }
}

void Bibliotheque::supprimerLivre(Livre livre) {
  for (int i = 0; i < this->nbrLivres; i++) {
    if (this->livres[i].getTitre() == livre.getTitre()) {
      if (this->livres[i].getAuteur() == livre.getAuteur()) {
        if ((livre.getAnneeParution(), this->livres[i].getAnneeParution())) {
          if (this->livres[i].getNbrPages() == livre.getNbrPages()) {
            for (int j = i; j < this->nbrLivres - 1; j++) {
              this->livres[j] = this->livres[j + 1];
            }
            this->nbrLivres--;
            cout << "Le livre a bien été supprimé !" << endl;
            return;
          }
        }
      }
    }
    cout << "Le livre n'a pas été supprimé !" << endl;
  }
}

void Bibliotheque::afficheLivre() {
  cout << "\nListe des livres de la bibliothèque : " << endl;
  if (this->nbrLivres == 0) {
    cout << "\nAucun livre dans la bibliothèque !\n" << endl;
  }
  for (int i = 0; i < this->nbrLivres; i++) {
    cout << "Titre: " << this->livres[i].getTitre()
         << " ; auteur: " << this->livres[i].getAuteur()
         << " ; date de parution: " << this->livres[i].getAnneeParution()
         << " ; nombre de pages: " << this->livres[i].getNbrPages() << endl;
  }
  cout << endl;
}

void Bibliotheque::rechercherLivre(string titre) {
  for (int i = 0; i < this->nbrLivres; i++) {
    if (livres[i].getTitre() == titre) {
      cout << "Titre: " << this->livres[i].getTitre()
           << " ; auteur: " << this->livres[i].getAuteur()
           << " ; date de parution: " << this->livres[i].getAnneeParution()
           << " ; nombre de pages: " << this->livres[i].getNbrPages() << endl;
      return;
    }
  }
  cout << "Le livre demandé n'existe pas !" << endl;
}
