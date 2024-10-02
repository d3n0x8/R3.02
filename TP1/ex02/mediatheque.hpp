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
        this->medias[i] = nullptr;
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

  /*
    void supprimerMedia(Media media) {
      for (int i = 0; i < this->nbrMedias; i++) {
        if (this->medias[i].getTitre() == livre.getTitre()) {
          if (this->medias[i].getAuteur() == livre.getAuteur()) {
            if ((livre.getAnneeParution(), this->medias[i].getAnneeParution()))
    { if (this->medias[i].getNbrPages() == livre.getNbrPages()) { for (int j =
    i; j < this->nbrMedias - 1; j++) { this->medias[j] = this->medias[j + 1];
                }
                this->nbrMedias--;
                cout << "Le livre a bien été supprimé !" << endl;
                return;
              }
            }
          }
        }
        cout << "Le livre n'a pas été supprimé !" << endl;
      }
    };
  */

  void afficherMedia() {
    for (int i = 0; i < this->nbrMedias; i++) {
      cout << medias[i]->getInfo() << endl;
    }
  };

  void rechercherMedia(string titre) {
    for (int i = 0; i < this->nbrMedias; i++) {
      if (medias[i]->getTitre() == titre) {
        cout << medias[i]->getInfo() << endl;
        return;
      }
    }
    cout << "Le livre demandé n'existe pas !" << endl;
  };
};

#endif
