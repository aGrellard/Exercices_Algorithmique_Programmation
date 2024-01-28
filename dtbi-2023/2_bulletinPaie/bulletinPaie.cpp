// TP ###################################################
// Afficher le bulletin de paie simplifié d’un salarié à partir des informations saisies
// Le salaire de base
// 	Les 169 premières heures sont payées sans majoration
// 	Entre 169 et 180 heures, une majoration de 50% est appliquée
// 	Au-delà de 180 heures, la majoration passe à 60%
// La prime familiale
// 	1 enfant : 20 €
// 	2 enfants : 50€
// 	Au-delà de 2 enfants : 70€ + 20€ par enfant supplémentaire
// ALGO ################################################
// 1 afficher utilisateur demander nb heures
// 2 afficher utilisateur demander nb enfants
// 3 determiner T/h
// 4 test conditional du nb heures
// 	calcul de base															            <= 169 	nb_hrs * T/
//	calcul des 169hr + les heures supp majorées 									    <= 180 	169  * T/  + (nb_hrs - 169)  * T/ * 1.5
//	calcul des 169hr + les heures supp majorées a 50% + les heures supp majorées a 60%  > 180	180 * T/  +  (11 * T/ * 1.5)  + (nb_hrs - 180) * T/ * 1.6 
// 5 switch case pour appliquer la prime selon nb enfant
// 6 afficher résulta
//####################################################
// g++ -std=c++2a -Wall -Wextra -Wconversion -Wfloat-conversion -Wsign-conversion -Wpedantic -o bulletinPaie -g bulletinPaie.cpp


#include <string>
#include <iostream>
#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#endif


int main() {
    
    #if defined(_WIN32) || defined(_WIN64)
        SetConsoleOutputCP(65001); // utf8 pour le terminal
    #endif

    std::string demander_nb_heures = "Combien d'heures avez vous travailler ?";
    std::string demander_nb_efants = "Combien d'enfants avez vous ?";
    const double hrs_majoree_50 = 1.5;
    const double hrs_majoree_60 = 1.6;
    const double tarif_horaires = 12.0;
    const int prime_1 = 20;
    const int prime_2 = 50;
    double nb_hrs = 0.0, total_hors_prime = 0.0, salaire_total = 0.0;
    int nb_enfants = 0, prime = 0;

	std::cout << demander_nb_heures << std::endl;
	std::cin >> nb_hrs;
	std::cout << demander_nb_efants << std::endl;
	std::cin >> nb_enfants;
	
	if (nb_hrs <= 169) {
        total_hors_prime = nb_hrs * tarif_horaires;
    } else if (nb_hrs <= 180) {
		total_hors_prime = 169 * tarif_horaires;
		total_hors_prime += ((nb_hrs-169) * tarif_horaires) * hrs_majoree_50;
    } else {
        total_hors_prime = 180 * tarif_horaires;
        total_hors_prime += (11 * tarif_horaires) * hrs_majoree_50;
        total_hors_prime += ((nb_hrs-180) * tarif_horaires) * hrs_majoree_60;
    }
	if (nb_enfants > 0) {
		switch(nb_enfants) {
			case 1 : prime = prime_1; break;
			case 2 : prime = prime_2; break;
			default : prime = prime_1 + prime_2 + (nb_enfants-2) * prime_1;
        }
    }

    std::cout << "tarif horaire " << tarif_horaires << " euro/hr" << std::endl;
    std::cout << "total hors prime " << total_hors_prime << " euro" << std::endl;
    std::cout << "prime" << prime << " euro" << std::endl;

    salaire_total = total_hors_prime + static_cast<double>(prime) ;
    std::cout << "Salaire Total " << salaire_total << " euro" << std::endl;

    #ifdef _WIN32
        system("pause");
    #endif

    return 0;
}