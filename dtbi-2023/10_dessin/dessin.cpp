#include <iostream>


int main() {

    int largeur = 8;
    int hauteur = 5;
    std::string caracter = "#";

    std::cout << "Saisir la largeur" << std::endl;
    std::cin >> largeur;
    std::cout << "Saisir la hauteur" << std::endl;
    std::cin >> hauteur;
    std::cout << "Saisir le caractére" << std::endl;
    std::cin >> caracter;
    std::cout << std::endl;
    
    for (int i = 0; i < hauteur; i++)
    {
        for (int i = 0; i < largeur; i++)
        {
            std::cout << caracter;
        }
        std::cout << std::endl;
    }
    
    #ifdef _WIN32
        system("pause");
    #endif

    return 0;
}