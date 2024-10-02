#include "mediatheque.hpp"
#include <algorithm>
#include <cstdio>
#include <iostream>

int menu() {
  int choix;
  cout << "1 - Afficher l'ensemble des media de la bibliothèque" << endl;
  cout << "2 - Ajouter un nouveau media" << endl;
  cout << "3 - Supprimer un media" << endl;
  cout << "4 - Recherche un media (par le titre)" << endl;
  cout << "5 - Quitter" << endl;
  cout << "Choisissez une option: ";
  cin >> choix;

  return choix;
}

int menuAjout() {
  int choix;
  cout << "1 - Ajouter un Livre" << endl;
  cout << "2 - Ajouter un DVD" << endl;
  cout << "3 - Ajouter un Vinyle" << endl;
  cout << "Choisissez une option: ";
  cin >> choix;

  return choix;
}

int verifChoix(int choix, int limit, int limit2) {
  if (!(choix <= limit2 && choix >= limit)) {
    int choix = menuAjout();
    verifChoix(choix, 1, 3);
  }
  return choix;
}

int verifBiblioPleine(Mediatheque &mediatheque) {
  if (mediatheque.size() == 50) {
    cout << "La bibliothèque est pleine ! \n" << endl;
    return 0;
  }
  return 1;
}

int verifBilbioVide(Mediatheque &mediatheque) {
  if (mediatheque.size() == 0) {
    cout << "\nLa bibliothèque est vide ! \n" << endl;
    return 0;
  }
  return 1;
}

string formaterMedia(string media) {
  std::transform(media.begin(), media.end(), media.begin(), ::tolower);

  if (!media.empty()) {
    media[0] = toupper(media[0]);
  }

  return media;
}

int main() {
  Mediatheque mediatheque = Mediatheque();
  string titre, auteur, realisateur, chanteur, media, artiste;
  int anneeParution, nbrPages, nbrTitres, duree;
  int choix = menu();
  while (choix != 5) {
    switch (choix) {
    case 1:
      mediatheque.afficherMedia();
      break;
    case 2:
      if (!verifBiblioPleine(mediatheque)) {
        break;
      }
      {
        int choixAjout = menuAjout();
        switch (choixAjout) {
        case 1:
          cout << "Saisissez le titre: ";
          cin >> titre;
          cout << "Saisissez l'auteur: ";
          cin >> auteur;
          cout << "Saisissez l'année de parution: ";
          cin >> anneeParution;
          cout << "Saisissez le nombre de pages: ";
          cin >> nbrPages;
          {
            Livre *livre = new Livre(titre, auteur, anneeParution, nbrPages);
            mediatheque.ajouterMedia(livre);
            cout << "\n Le livre a bien été ajouté !\n " << endl;
          }
          break;
        case 2:
          cout << "Saisissez le titre: ";
          cin >> titre;
          cout << "Saisissez le réalisateur: ";
          cin >> realisateur;
          cout << "Saisissez l'année de sortie: ";
          cin >> anneeParution;
          cout << "Saisissez la durée (en minutes): ";
          cin >> duree;
          {
            DVD *dvd = new DVD(titre, realisateur, anneeParution, duree);
            mediatheque.ajouterMedia(dvd);
            cout << "\n Le dvd a bien été ajouté !\n " << endl;
          }
          break;
        case 3:
          cout << "Saisissez le titre: ";
          cin >> titre;
          cout << "Saisissez le chanteur: ";
          cin >> chanteur;
          cout << "Saisissez l'année de sortie: ";
          cin >> anneeParution;
          cout << "Saisissez le nombre de titres: ";
          cin >> nbrTitres;
          {
            Vinyle *vinyle =
                new Vinyle(titre, chanteur, anneeParution, nbrTitres);
            mediatheque.ajouterMedia(vinyle);
            cout << "\n Le vinyle a bien été ajouté !\n " << endl;
          }
          break;
        default:
          cout << "Choix invalide" << endl;
          break;
        }
      }
      break;

    case 3:
      if (!verifBilbioVide(mediatheque)) {
        break;
      }
      cout
          << "Saisissez le type de media à supprimer: (Livre / DVD / Vinyle): ";
      cin >> media;
      cout << "Saisissez le titre: ";
      cin >> titre;
      cout << "Saisissez l'artiste: ";
      cin >> artiste;
      cout << "Saisissez l'annee de parution: ";
      cin >> anneeParution;
      media = formaterMedia(media);
      mediatheque.supprimerMedia(media, titre, artiste, anneeParution);
      break;

    case 4:
      if (!verifBilbioVide(mediatheque)) {
        break;
      }
      cout << "Saisissez le titre du livre à trouver: ";
      cin >> titre;
      mediatheque.rechercherMedia(titre);
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