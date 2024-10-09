#ifndef CHAINE_H
#define CHAINE_H

#include <iostream>
#include <stdexcept>

struct maillon {
  maillon *suivant;
  int valeur;
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
      adjqueue(nouveau->valeur);
      nouveau = nouveau->suivant;
    }
  };

  ~Chaine() {
    while (tete != nullptr) {
      suptete();
    }
  };

  void adjtete(int valeur) {
    maillon *nouveau = new maillon;
    nouveau->valeur = valeur;
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

  void adjqueue(int valeur) {
    if (nbrMaillons == 0)
      adjtete(valeur);
    else {
      maillon *nouveau = new maillon;
      nouveau->valeur = valeur;
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
  int element(int position) const {
    int index = 0;
    maillon *element = tete;
    while (index != position && element->suivant != nullptr) {
      element = element->suivant;
      index++;
    }
    if (element == nullptr) {
      throw std::out_of_range("Position invalide.");
    }
    return element->valeur;
  };

  void adjpos(int valeur, int position) {
    maillon *nouveau = new maillon;
    nouveau->valeur = valeur;

    if (position == 0) {
      adjtete(valeur);
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
      std::cout << mAafficher->valeur;
      if (mAafficher->suivant != nullptr) {
        std::cout << "-";
      }
      mAafficher = mAafficher->suivant;
    }
    std::cout << std::endl;
  }
};

#endif