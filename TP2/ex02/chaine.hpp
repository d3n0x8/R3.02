#ifndef CHAINE_H
#define CHAINE_H

#include "media.hpp"
#include <iostream>
#include <stdexcept>

// maillon est un media
struct maillon {
  maillon *suivant;
  Media *media;
};

class Chaine {

private:
  maillon *tete;
  maillon *queue;
  int nbrMaillons;

public:
  Chaine() {
    this->tete = nullptr;
    this->queue = nullptr;
    this->nbrMaillons = 0;
  };
  Chaine(const Chaine &chaine) {

    tete = nullptr;
    queue = nullptr;
    nbrMaillons = 0;

    maillon *nouveau = chaine.tete;
    while (nouveau != nullptr) {
      adjqueue(*(nouveau->media));
      nouveau = nouveau->suivant;
    }
  };

  ~Chaine() {
    while (tete != nullptr) {
      suptete();
    }
  };

  void adjtete(Media &media) {
    maillon *nouveau = new maillon;
    nouveau->media = &media;
    nouveau->suivant = tete;
    tete = nouveau;
    if (nbrMaillons == 0)
      queue = nouveau;
    nbrMaillons++;
  };

  void suptete() {
    if (nbrMaillons > 0) {
      maillon *mAsupprimer = tete;
      tete = tete->suivant;
      delete mAsupprimer;

      nbrMaillons--;
      if (nbrMaillons == 0)
        queue = nullptr;
    }
  };

  void adjqueue(Media &media) {
    if (nbrMaillons == 0)
      adjtete(media);
    else {
      maillon *nouveau = new maillon;
      nouveau->media = &media;
      queue->suivant = nouveau;
      queue = nouveau;
      nbrMaillons++;
    }
  };

  void supqueue() {
    maillon *mAsupprimer = tete;
    while (mAsupprimer->suivant->suivant != nullptr) {
      mAsupprimer = mAsupprimer->suivant;
    }
    delete mAsupprimer->suivant;
    mAsupprimer->suivant = nullptr;
    queue = mAsupprimer;
    nbrMaillons--;
  };
  int longueur() const { return nbrMaillons; };
  Media *element(int position) const {
    int index = 0;
    maillon *element = tete;
    while (index != position && element->suivant != nullptr) {
      element = element->suivant;
      index++;
    }
    if (element == nullptr) {
      throw std::out_of_range("Position invalide.");
    }
    return element->media;
  };

  void adjpos(Media &media, int position) {
    maillon *nouveau = new maillon;
    nouveau->media = &media;

    if (position == 0) {
      adjtete(media);
      nbrMaillons++;
      return;
    }
    maillon *element = tete;
    int index = 0;

    while (element != nullptr && index < position - 1) {
      element = element->suivant;
      index++;
    }

    if (element == nullptr) {
      throw std::out_of_range("Position invalide");
    } else {
      nouveau->suivant = element->suivant;
      element->suivant = nouveau;
      nbrMaillons++;
    }
  };

  void suppos(int position) {

    if (position == 0) {
      suptete();
      nbrMaillons--;
      return;
    }

    maillon *element = tete;
    int index = 0;

    while (element != nullptr && index < position - 1) {
      element = element->suivant;
      index++;
    }

    if (element == nullptr) {
      throw std::out_of_range("Position invalide");
    } else {
      maillon *mAsupprimer = element->suivant;
      element->suivant = mAsupprimer->suivant;
      delete mAsupprimer;
      nbrMaillons--;
    }
  };
  void vide() {
    while (tete != nullptr) {
      suptete();
      nbrMaillons--;
    }
  };

  bool est_vide() const { return tete == nullptr; };

  void affiche() const {
    maillon *mAafficher = tete;
    if (mAafficher == nullptr) {
      std::cout << "La chaine est vide !" << std::endl;
      return;
    }
    while (mAafficher != nullptr) {
      std::cout << mAafficher->media;
      if (mAafficher->suivant != nullptr) {
        std::cout << "-";
      }
      mAafficher = mAafficher->suivant;
    }
    std::cout << std::endl;
  }
};

#endif