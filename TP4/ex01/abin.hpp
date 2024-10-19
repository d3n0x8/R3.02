#ifndef ABIN_HPP
#define ABIN_HPP

#include <iostream>
#include <stdexcept>
using namespace std;

typedef int noeud;

typedef bool booleen;

class Abin {
private:
  struct Noeud {
    noeud valeur;
    Abin *gauche;
    Abin *droite;
  };

  Noeud *racineNoeud;

public:
  Abin() : racineNoeud(nullptr) {}

  static Abin arbnouv() { return Abin(); }

  static Abin enracine(noeud e, const Abin &ag, const Abin &ad) {
    Abin arbre;
    arbre.racineNoeud = new Noeud;
    arbre.racineNoeud->valeur = e;
    arbre.racineNoeud->gauche = new Abin(ag);
    arbre.racineNoeud->droite = new Abin(ad);
    return arbre;
  }
  Abin ag() const {
    if (est_vide()) {
      throw runtime_error("L'arbre est vide, pas de sous-arbre gauche.");
    }
    return *(racineNoeud->gauche);
  }

  Abin ad() const {
    if (est_vide()) {
      throw runtime_error("L'arbre est vide, pas de sous-arbre droit.");
    }
    return *(racineNoeud->droite);
  }

  noeud racine() const {
    if (est_vide()) {
      throw runtime_error("L'arbre est vide, pas de racine.");
    }
    return racineNoeud->valeur;
  }

  booleen est_vide() const { return racineNoeud == nullptr; }

  ~Abin() { delete racineNoeud; }

  void parcours_prefixe(const Abin &a) {
    if (!a.est_vide()) {
      cout << a.racine() << " ";
      parcours_prefixe(a.ag());
      parcours_prefixe(a.ad());
    }

  private:
    Abin(const Abin &autre) {
      if (autre.est_vide()) {
        racineNoeud = nullptr;
      } else {
        racineNoeud = new Noeud;
        racineNoeud->valeur = autre.racineNoeud->valeur;
        racineNoeud->gauche = new Abin(*(autre.racineNoeud->gauche));
        racineNoeud->droite = new Abin(*(autre.racineNoeud->droite));
      }
    }
  };

#endif