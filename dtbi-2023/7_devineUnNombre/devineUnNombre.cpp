// TP : Créer un programme qui doit deviner un nombre choisi par l’utilisateur
// 
// L’utilisateur lui indique si le nombre est plus grand (+), plus petit (-) ou s’il a trouvé le nombre (=)
// Exemple d’affichage :
// 	Choisissez un nombre compris entre 1 et 100, puis appuyez sur une touche
// a
// Je tente 45, est-ce plus, moins ou est-ce le nombre (+/-/=) ?
// -
// Je tente 10, est-ce plus, moins ou est-ce le nombre (+/-/=) ?
// +
// Je tente 22, est-ce plus, moins ou est-ce le nombre (+/-/=) ?
// +
// je tente 27, est-ce plus, moins ou est-ce le nombre (+/-/=) ?
// =
// Super ! J’ai trouvé en 4 tentatives !
// 
// ALGO ###############################################
// int nbUtilisateur
// int nbOrdinateur
// int nbMin = 1
// int nbMax = 100
// string indicateur 
// string choix_nombre 
//
// saisir nbUtilisateur
// Répeter TantQue réponse != "="
// nbOrdinateur = Aléa(nbMin,nbMax) 
// demande si nbOrdinateur : < >
// test conditionel
// 	si > 	nbMax = nbOrdinateur
// 	si < 	nbMin = nbOrdinateur
//	si = exit
//####################################################
// Amélioration possible :
//  mettre en mémoire les nombres deja testé pour ne pas les retester
//      utiliser un vecteur pour stocker les nombres deja testé
//####################################################

#include <string>
#include <iostream>
#include <random>
#include <algorithm>

#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#endif

int main() {

    #if defined(_WIN32) || defined(_WIN64)
        SetConsoleOutputCP(65001); // utf8 pour le terminal
    #endif

	const std::string afficher_choixNbUtilisateur = "Choisissez le nombre enter 1 et 100 que je vais devoir deviner :";
	const std::string afficher_demandeOrdinateur = "Votre nombre est-il supérieur ou inférieur ou égale à : ";
	const std::string afficher_choix_1 = "pour  supérieur saisir : >";
	const std::string afficher_choix_2 = "pour  inférieur saisir : <";
	const std::string afficher_choix_3 = "pour  égale saisir : =";

	int nbMin = 1;
	int nbMax = 100;
	int nbUtilisateur = 0;
	int nbOrdinateur = 0;
	std::string indicateur = "";

	std::cout << afficher_choixNbUtilisateur;
	std::cin >> nbUtilisateur;

    std::random_device rd; // Valeurs initial pour démarer le processus de génération de nombre aléatoire 
    std::mt19937 gen(rd()); // le Moteur de génération de nombre aléatoire
    do
    {
        std::uniform_int_distribution<> distrib(nbMin, nbMax); // produit des nombres aléatoire sur une range [min->max] de manierre uniforme min et max inclu
        nbOrdinateur = distrib(gen); // afféctation du nb aléatoire

        std::cout << afficher_demandeOrdinateur << nbOrdinateur << std::endl;
        std::cout << afficher_choix_1 << std::endl;
        std::cout << afficher_choix_2 << std::endl;
        std::cout << afficher_choix_3 << std::endl;

        std::cin >> indicateur;

		if (indicateur == "<") {
            nbMax = nbOrdinateur;
        } else if (indicateur == ">"){
            nbMin = nbOrdinateur;
        } else {
            std::cout << "J'ais trouvé, votre nombre est : " << nbOrdinateur << std::endl;
        }

    } while (indicateur != "=");

    #ifdef _WIN32
        system("pause");
    #endif

    return 0;
}
