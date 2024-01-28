#include <iostream>
#include <string>

#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#endif

int main() {
    #if defined(_WIN32) || defined(_WIN64)
        SetConsoleOutputCP(65001); // utf8 pour le terminal
    #endif

    const std::string films_1 = "La cité de la peur";
    const std::string films_2 = "GoldenEye";
    const std::string films_3 = "La vie est un long fleuve tranquille";
    const std::string films_4 = "Star Wars - Épisode I : La Menace fantôme";
    const std::string replique = "Voici un réplique du film ";
    const std::string replique_1 = ": c’est une véritable boucherie !";
    const std::string replique_2 = ": Je m’appelle Bond, James Bond";
    const std::string replique_3 = ": J'vais mettre la viande dans le torchon.";
    const std::string replique_4 = ": Que la force soit avec toi.";
    const std::string choix_film_1 = "choix 1) ";
    const std::string choix_film_2 = "choix 2) ";
    const std::string choix_film_3 = "choix 3) ";
    const std::string choix_film_4 = "choix 4) ";
    const std::string choix_quitter = "choix 5) quitter";
    int choix_utilisateur = 0;

    do {
        std::cout << "\nAfficher une réplique du film : "<< std::endl;
        std::cout << choix_film_1 << films_1 << std::endl;
        std::cout << choix_film_2 << films_2 << std::endl;
        std::cout << choix_film_3 << films_3 << std::endl;
        std::cout << choix_film_4 << films_4 << std::endl;
        std::cout << choix_quitter << "\n\n";
        std::cin >> choix_utilisateur;

        switch (choix_utilisateur) {
            case 1:
                std::cout << replique << films_1 << replique_1 << std::endl;
                break;
            case 2:
                std::cout << replique << films_2 << replique_2 << std::endl;
                break;
            case 3:
                std::cout << replique << films_3 << replique_3 << std::endl;
                break;
            case 4:
                std::cout << replique << films_4 << replique_4 << std::endl;
                break;
            default:
                if (choix_utilisateur != 5) {
                    std::cout << "Aucun film ne correspond à la sélection !!" << std::endl;
                }
                break;
        }
    } while (choix_utilisateur != 5);

    std::cout << "Au revoir" << std::endl;

    #ifdef _WIN32
        system("pause");
    #endif
    
    return 0;
}