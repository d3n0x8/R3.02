#ifndef MEDIATHEQUE_HPP
#define MEDIATHEQUE_HPP

#include "DVD.hpp"
#include "livre.hpp"
#include "media.hpp"
#include "vinyle.hpp"
#include <iostream>
class Mediatheque {

private:
  const static int nombreMaximumMedia = 50;
  Media *medias[nombreMaximumMedia];
  int nbrMedias;

public:
  Mediatheque() : nbrMedias(0) {
    for (int i = 0; i < nombreMaximumMedia; i++) {
      this->medias[i] = nullptr;
    }
  };
  ~Mediatheque() {
    for (int i = 0; i < this->nbrMedias; i++) {
      if (this->medias[i] != nullptr) {
        cout << "Destruction de " << this->medias[i]->getInfo() << endl;
        delete this->medias[i];
      }
    }
  }

  int size() { return this->nbrMedias; };
  int getNbrMedias() { return this->nbrMedias; };
  void ajouterMedia(Media *media) {
    if (this->nbrMedias < nombreMaximumMedia) {
      this->medias[this->nbrMedias] = media;
      this->nbrMedias++;
    }
  };

  void supprimerMedia(string media, string titre, string artiste, int annee) {
    for (int i = 0; i < this->nbrMedias; i++) {
      if (this->medias[i]->getGenre() == media &&
          this->medias[i]->getTitre() == titre &&
          this->medias[i]->getArtiste() == artiste &&
          this->medias[i]->getAnnee() == annee) {
        delete this->medias[i];
        this->nbrMedias--;
        for (int j = i; j < this->nbrMedias; j++) {
          this->medias[j] = this->medias[j + 1];
        }
        cout << "Le media a bien été supprimé !" << endl;
        return;
      }
    }
    cout << "Le media demandé n'existe pas !" << endl;
  };

  void afficherMedia() {
    if (this->nbrMedias == 0) {
      cout << "\n------------------------------" << endl;
      cout << "  La bibliothèque est vide !" << endl;
      cout << "------------------------------\n" << endl;
      return;
    }
    cout << "\n------------------------------" << endl;
    cout << "      Liste des medias " << endl;
    cout << "------------------------------\n" << endl;
    for (int i = 0; i < this->nbrMedias; i++) {
      cout << medias[i]->getInfo() << endl;
    }
    cout << endl;
  };

  void rechercherMedia(string media, string titre, string artiste, int annee) {
    for (int i = 0; i < this->nbrMedias; i++) {
      if (this->medias[i]->getGenre() == media &&
          this->medias[i]->getTitre() == titre &&
          this->medias[i]->getArtiste() == artiste &&
          this->medias[i]->getAnnee() == annee) {
        cout << "Le media demandé existe bien dans la bibliothèque: " << endl;
        cout << this->medias[i]->getInfo() << endl;
        return;
      }
    }
    cout << "Le media demandé n'existe pas !" << endl;
  }
};

#endif