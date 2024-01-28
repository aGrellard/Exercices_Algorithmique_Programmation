#include <iostream>
#include <string>
#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#endif

int main() {

    #if defined(_WIN32) || defined(_WIN64)
        SetConsoleOutputCP(65001); // utf8 pour le terminal
    #endif

    std::string demander_cuisson = "Quelle cuisson souhaitez-vous : 1: Bleu, 2: A Point, 3: Cuit ? ";
    std::string demander_poids = "Combien de gramme de viande voulez-vous ? ";
    std::string demander_typeViande = "Que voulez-vous manger : 1: Boeuf ou 2: Agneau ?";
    
    int reponse_cuisson = 0, reponse_poids = 0, reponse_typeViande = 0;
    double resulta_duree = 0;

    while (reponse_cuisson < 1 || reponse_cuisson > 3) {
        std::cout << demander_cuisson;
        std::cin >> reponse_cuisson;
    }

    while (reponse_poids <= 0) {
        std::cout << demander_poids;
        std::cin >> reponse_poids;
    }

    while (reponse_typeViande < 1 || reponse_typeViande > 2) {
        std::cout << demander_typeViande;
        std::cin >> reponse_typeViande;
    }

    if (reponse_typeViande == 1) {
        switch (reponse_cuisson) {
        case 1:
            resulta_duree = 10.0 * (static_cast<double>(reponse_poids) / 500);
            break;
        case 2:
            resulta_duree = 17.0 * (static_cast<double>(reponse_poids) / 500);
            break;
        case 3:
            resulta_duree = 25.0 * (static_cast<double>(reponse_poids) / 500);
            break;
        }
    }
    else if (reponse_typeViande == 2) {
        switch (reponse_cuisson) {
        case 1:
            resulta_duree = 15.0 * (static_cast<double>(reponse_poids) / 400);
            break;
        case 2:
            resulta_duree = 25.0 * (static_cast<double>(reponse_poids) / 400);
            break;
        case 3:
            resulta_duree = 40.0 * (static_cast<double>(reponse_poids) / 400);
            break;
        }
    }

    resulta_duree *= 60;
    std::cout << "Vous serez servit dans : " << resulta_duree << " secondes" << std::endl;

    #ifdef _WIN32
        system("pause");
    #endif
    
    return 0;
}