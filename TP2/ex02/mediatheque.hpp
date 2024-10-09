#ifndef MEDIATHEQUE_HPP
#define MEDIATHEQUE_HPP

#include "DVD.hpp"
#include "chaine.hpp"
#include "livre.hpp"
#include "media.hpp"
#include "vinyle.hpp"
#include <iostream>
class Mediatheque {

private:
  Chaine chaine;

public:
  Mediatheque() { Chaine chaine = Chaine(); };
  ~Mediatheque() { chaine.vide(); }

  int size() { return this->chaine.longueur(); };
  int getNbrMedias() { return this->chaine.longueur(); };
  void ajouterMedia(Media *media) { chaine.adjtete(*media); };

  void supprimerMedia(string media, string titre, string artiste, int annee) {
    for (int i = 0; i < this->chaine.longueur(); i++) {
      if (this->chaine.element(i)->getGenre() == media &&
          this->chaine.element(i)->getTitre() == titre &&
          this->chaine.element(i)->getArtiste() == artiste &&
          this->chaine.element(i)->getAnnee() == annee) {
        this->chaine.suppos(i);
        for (int j = i; j < this->chaine.longueur(); j++) {
          this->chaine.element(i)[j] = this->chaine.element(i)[j + 1];
        }
        cout << "Le media a bien été supprimé !" << endl;
        return;
      }
    }
    cout << "Le media demandé n'existe pas !" << endl;
  };

  void afficherMedia() {
    if (this->chaine.longueur() == 0) {
      cout << "\n------------------------------" << endl;
      cout << "  La bibliothèque est vide !" << endl;
      cout << "------------------------------\n" << endl;
      return;
    }
    cout << "\n------------------------------" << endl;
    cout << "      Liste des chaine.element(i) " << endl;
    cout << "------------------------------\n" << endl;
    for (int i = 0; i < this->chaine.longueur(); i++) {
      cout << chaine.element(i)->getInfo() << endl;
    }
    cout << endl;
  };

  void rechercherMedia(string media, string titre, string artiste, int annee) {
    for (int i = 0; i < this->chaine.longueur(); i++) {
      if (this->chaine.element(i)->getGenre() == media &&
          this->chaine.element(i)->getTitre() == titre &&
          this->chaine.element(i)->getArtiste() == artiste &&
          this->chaine.element(i)->getAnnee() == annee) {
        cout << "Le media demandé existe bien dans la bibliothèque: " << endl;
        cout << this->chaine.element(i)->getInfo() << endl;
        return;
      }
    }
    cout << "Le media demandé n'existe pas !" << endl;
  }
};

#endif