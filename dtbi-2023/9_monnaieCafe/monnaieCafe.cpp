#include <iostream>
#include <string>
#include <iomanip> // pour std::setprecision
/*
    << std::fixed << std::setprecision(2) << float
    utilisé dans un flux pour définir le nombre de chiffre à afficher aprés la virgule
    semblable à printf("%.2f", var); en c
    avec c++20 possible d'utiliser std::format
*/
#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#endif

int main() {

    #if defined(_WIN32) || defined(_WIN64)
        SetConsoleOutputCP(65001); // utf8 pour le terminal
    #endif

    const std::string afficher_bonjour = "Bonjour, vous avez selectionne un expresso sans sucre";
    const std::string afficher_prixCafe = "Prix du cafe : ";
    const std::string afficher_pieces = "Pieces acceptee : 2€ 1€ 0.50€ 0.20€ 0.10€ 0.05€";
    const std::string afficher_refuPiece = "Votre piece n'est pas acceptee ";
    const std::string afficher_renduPiece = "Veuillez recuperer votre monnaie : ";
    const std::string afficher_cafe = "Votre cafe est en cours de preparation";
    const std::string afficher_reste = "Il vous reste a payer : ";

    const std::string afficher_credits = "Vous disposez de : ";
    const std::string afficher_inserer = "Veuillez inserer une piece";

    const double prix_cafe = 0.60;
    double credit_actuel = 0.0;
    double saisie = 0.0;
    double calcul = 0.0;

    std::cout << afficher_bonjour << std::endl;
    std::cout << afficher_prixCafe << std::fixed << std::setprecision(2) << prix_cafe << "€" << std::endl;
    std::cout << afficher_pieces << std::endl;

    while (credit_actuel < prix_cafe) {
        std::cout << afficher_credits << std::fixed << std::setprecision(2) << credit_actuel << " €" << std::endl;
        std::cout << afficher_inserer << std::endl;
        std::cin >> saisie;

        switch (static_cast<int>(saisie * 100)) {
            case 200: // 2€
            case 100: // 1€
            case 50:  // 0.50€
            case 20:  // 0.20€
            case 10:  // 0.10€
            case 5:   // 0.05€
                credit_actuel += saisie;
                break;
            default:
                std::cout << afficher_refuPiece << std::endl;
                std::cout << afficher_pieces << std::endl;
                break;
        }

        if (credit_actuel >= prix_cafe) {
            std::cout << afficher_cafe << std::endl;
            calcul = credit_actuel - prix_cafe;
            std::cout << afficher_renduPiece << std::fixed << std::setprecision(2) << calcul << " €" << std::endl;
        } else {
            calcul = prix_cafe - credit_actuel;
            std::cout << afficher_reste << std::fixed << std::setprecision(2) << calcul << " €" << std::endl;
        }
    }

    #ifdef _WIN32
        system("pause");
    #endif

    return 0;
}
