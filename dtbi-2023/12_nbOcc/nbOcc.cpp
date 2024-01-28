/*
Algo nbOcc
	Constante demander_valeur_1 : texte <- "Entrer une valeur entre 0 et 9, -1 pour terminer la saisie"
	Constante demander_valeur_2 : texte <- "Autre valeur, SVP"
	Variable tab : entier[10] 
	Variable tab_taille : endtier <- 10
	Variable saisi_utilisateur : entier <- 0
	Pour i : entier <- 0 à tab_taille
		tab[i] <- 0
	FPour
	
	
	écrire(demander_valeur_1)
	Répéter
		saisi_utilisateur <- saisir()
		Si (saisi_utilisateur >= 0 et saisi_utilisateur < tab_taille) Alors 
			Pour i : entier <- 0 à tab_taille
				Si (i==saisi_utilisateur) Alors
					tab[i] <- tab[i] + 1
				FSi
			FPour
		FSi
		Si (saisi_utilisateur != -1) Alors
			écrire(demander_valeur_2)
		FSi
	TantQue (saisi_utilisateur != -1) FRépéter
	
	Pour i : entier <- 0 à tab_taille
		écrire("Nombre de " & i & " : " & tab[i])
	FPour

Fin
*/

#include <iostream>
int main() {
  
  const int tab_taille = 10;
  int tab[10] = {0};
  int saisi_utilisateur = 0;

  std::cout << "Entrer une valeur entre 0 et 9, -1 pour terminer la saisie" << std::endl;

  do {
    std::cin >> saisi_utilisateur;
    if (saisi_utilisateur >= 0 && saisi_utilisateur < tab_taille) {
      for (int i = 0; i < tab_taille; i++) {
        if (i == saisi_utilisateur) {
            tab[i]++;
        }
      }
    }
    if (saisi_utilisateur != -1) {
      std::cout << "Autre valeur, SVP" << std::endl;
    }
  } while (saisi_utilisateur != -1);

  for (int i = 0; i < tab_taille; i++)
  {
    std::cout << "Nombre de " << i << " : " << tab[i] << std::endl;
  }

  #ifdef _WIN32
  system("pause");
  #endif

}