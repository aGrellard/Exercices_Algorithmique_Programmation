#include <iostream>
#include <string>

#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#endif

int main()
{

    #if defined(_WIN32) || defined(_WIN64)
        SetConsoleOutputCP(65001); // utf8 pour le terminal
    #endif

    const int MAX_TENTATIVES = 5;
    int nbTentative = 1;
    std::string saisireCapital = "";

    std::cout << "Quelle est la capitale de la France ?" << std::endl;
    std::cin >> saisireCapital;
    /*
        sortie de boucle 2 condition possible
            saisireCapital == paris
            ||
            nbTentative > MAX_TENTATIVES
    */
    while (saisireCapital != "Paris" && MAX_TENTATIVES > nbTentative)
    {
        std::cout << "Mauvaise réponse !" << std::endl;
        std::cout << "Plus que " << MAX_TENTATIVES - nbTentative << " tentative(s)" << std::endl;
        std::cout << "Quelle est la capitale de la France ?" << std::endl;
        std::cin >> saisireCapital;
        if (saisireCapital != "Paris")
            nbTentative++; // incrémentation uniquement si mauvaise réponse pour ne pas fausser le nb de tentative saisies
    }

    std::cout << "nb tentative " << nbTentative << std::endl;
    
    if (nbTentative >= MAX_TENTATIVES)
        std::cout << "Revoyez votre géographie !" << std::endl;
    else
        std::cout << "Bravo !" << std::endl;


    #ifdef _WIN32
        system("pause");
    #endif
    
    return 0;
}
