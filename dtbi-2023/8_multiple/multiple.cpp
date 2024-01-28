#include <iostream>
#include <string>

#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#endif

int main() {

    #if defined(_WIN32) || defined(_WIN64)
        SetConsoleOutputCP(65001); // utf8 pour le terminal
    #endif

    const std::string afficher_choixNbUtilisateur = "Entrez un entier multiple de 3: ";
    const std::string afficher_resultaTrue = " est bien un multiple de 3";
    const std::string afficher_resultaFalse = " n'est pas un multiple de 3";

    int nbUtilisateur = 0;
    int resulta = 0;

    do {


        std::cout << afficher_choixNbUtilisateur;
        std::cin >> nbUtilisateur; 

        resulta = 0;
        
        // méthode pour fair la somme des chiffres d'un nombre de type entier sans convertion
        // récuperation du dernier chiffre du nombre en divisant par 10 et en récupérant le reste de la division
        // puis on divise le nombre par 10 pour supprimer le dernier chiffre
        // on répète l'opération jusqu'à ce que le nombre soit égale à 0
        int nbr = nbUtilisateur;
        while (nbr > 0) {
            resulta += nbr % 10;
            nbr /= 10;
        }

        float division = static_cast<float>(resulta) / 3;
        std::cout << "La somme des chiffres de " << nbUtilisateur << " est de: " << resulta << std::endl;
        std::cout << "La division de: " << resulta << "/3 est de: " << division << std::endl;

        if (resulta % 3 != 0) {
            std::cout << resulta << afficher_resultaFalse << std::endl;
        }
    } while (resulta % 3 != 0);

    std::cout << resulta << afficher_resultaTrue << std::endl;

    #ifdef _WIN32
        system("pause");
    #endif

    return 0;
}
