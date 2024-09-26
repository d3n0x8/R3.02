#include "bibliotheque.hpp"
#include <iostream>

int menu() {
  int choix;
  cout << "1 - Afficher l'ensemble des livres de la bibliothèque" << endl;
  cout << "2 - Ajouter un nouveau livre" << endl;
  cout << "3 - Supprimer un livre" << endl;
  cout << "4 - Recherche un livre (par le titre)" << endl;
  cout << "5 - Quitter" << endl;
  cout << "Choisissez une option: ";
  cin >> choix;

  return choix;
}

int verifBiblioPleine(Bibliotheque bibliotheque) {
  if (bibliotheque.size() == 50) {
    cout << "La bibliothèque est pleine ! \n" << endl;
    return 0;
  }
  return 1;
}

int verifBilbioVide(Bibliotheque bibliotheque) {
  if (bibliotheque.size() == 0) {
    cout << "La bibliothèque est vide ! \n" << endl;
    return 0;
  }
  return 1;
}

int main() {
  Bibliotheque bibliotheque;
  string titre, auteur;
  int anneeParution, nbrPages;
  int choix = menu();
  while (choix != 5) {
    switch (choix) {
    case 1:
      bibliotheque.afficheLivre();
      break;
    case 2:
      if (!verifBiblioPleine(bibliotheque)) {
        break;
      }
      cout << "Saisissez le titre: ";
      cin >> titre;
      cout << "Saisissez l'auteur: ";
      cin >> auteur;
      cout << "Saisissez l'année de parution: ";
      cin >> anneeParution;
      cout << "Saisissez le nombre de pages: ";
      cin >> nbrPages;
      {
        Livre livre(titre, auteur, anneeParution, nbrPages);
        bibliotheque.ajouterLivre(livre);
        cout << "\n Le livre a bien été ajouté !\n " << endl;
      }
      break;

    case 3:
      if (!verifBilbioVide(bibliotheque)) {
        break;
      }
      cout << "Saisissez le titre: ";
      cin >> titre;
      cout << "Saisissez l'auteur: ";
      cin >> auteur;
      cout << "Saisissez l'année de parution: ";
      cin >> anneeParution;
      cout << "Saisissez le nombre de pages: ";
      cin >> nbrPages;
      {
        Livre livre(titre, auteur, anneeParution, nbrPages);
        bibliotheque.supprimerLivre(livre);
      }
      break;

    case 4:
      if (!verifBilbioVide(bibliotheque)) {
        break;
      }
      cout << "Saisissez le titre du livre à trouver: ";
      cin >> titre;
      bibliotheque.rechercherLivre(titre);
      break;

    case 5:
      cout << "Au revoir !" << endl;
      break;

    default:
      cout << "Choix invalide" << endl;
      break;
    }
    choix = menu();
  }
  return 0;
}