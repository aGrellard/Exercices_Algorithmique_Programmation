#include <iostream>
#include <cmath>
#include <array>
/*
int main() {
    int taille, choixDessin;
    char car;

    std::cout << "taille ? ";
    std::cin >> taille;

    std::cout << "caractère ? ";
    std::cin >> car;

    do {
        afficherMenu();
        std::cin >> choixDessin;
    } while (choixDessin < 1 || choixDessin > 6);

    for (int j = 1; j <= taille; ++j) {
        for (int i = 1; i <= taille; ++i) {
            switch (choixDessin) {
                case 1: // Rectangle plein
                    std::cout << car;
                    break;
                case 2: // Rectangle creux
                    if (i == 1 || i == taille || j == 1 || j == taille)
                        std::cout << car;
                    else
                        std::cout << " ";
                    break;
                case 3: // Croix
                    if (i == j || i + j == taille + 1)
                        std::cout << car;
                    else
                        std::cout << " ";
                    break;
                case 4: // Triangle rectangle
                    if (j == taille || i == 1 || i == j)
                        std::cout << car;
                    else
                        std::cout << " ";
                    break;
                case 5: // Losange
                    if (i + j == (taille + 1) / 2 || i + j == taille + (taille / 2) || i - j == taille / 2 || j - i == taille / 2)
                        std::cout << car;
                    else
                        std::cout << " ";
                    break;
                case 6: // Damier
                    if ((i + j) % 2 == 0)
                        std::cout << car;
                    else
                        std::cout << " ";
                    break;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}

*/

int main() {
    int taille = 8;
    std::string car = "*";
    std::string bg = " ";
    for (int j = 1; j <= taille; ++j) {
        for (int i = 1; i <= taille; ++i) {
            if ( i == (taille + 1) / 2 || i == (taille + 2) / 2 || j == (taille + 1) / 2 || j == (taille + 2) / 2)
                std::cout << car;
            else
                std::cout << bg;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for (int j = 1; j <= taille; ++j) {
        for (int i = 1; i <= taille; ++i) {
            if ( i == taille || i == j || j == 1)
                std::cout << car;
            else
                std::cout << bg;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for (int j = 1; j <= taille; ++j) {
        for (int i = 1; i <= taille; ++i) {
            if (j == 1 || (i == j && i <= taille /2) ||  (i + j == taille +1 && i > taille /2) )
                std::cout << car;
            else
                std::cout << bg;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for (int j = 1; j <= taille; ++j) {
        for (int i = 1; i <= taille; ++i) {
            if (j == 1 || j == taille || i == j ||  i + j == taille +1 )
                std::cout << car;
            else
                std::cout << bg;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for (int j = 1; j <= taille; ++j) {
        for (int i = 1; i <= taille; ++i) {
            if (
                i + (j -1) == (taille + 1) / 2 ||
                i + (j -1) == taille + (taille) / 2 ||
                i - j == taille /2 ||
                j - i == taille /2
            )
                std::cout << car;
            else
                std::cout << bg;
        }
        std::cout << std::endl;
    }
/*

    const int palindromeSize = 5;

    std::string tab[palindromeSize];

	tab[0] = "k";
	tab[1] = "a";
	tab[2] = "y";
	tab[3] = "a";
	tab[4] = "k";

    for (int i = 0; i < palindromeSize; ++i) {
        if (tab[i] != tab[palindromeSize - 1 - i]) {
            std::cout << "Ce n'est pas un palindrome" << std::endl;
            break;
        }
    }

    std::cout << "C'est un palindrome" << std::endl;
    
    const int radius = 9; // Rayon du cercle
    const int width = 2 * radius;
    const int height = 2 * radius;

    for (int y = 0; y <= height; y++) {
        for (int x = 0; x <= width; x++) {
            // Calculer la distance du point actuel au centre
            int dx = radius - x;
            int dy = radius - y;
            double distance = sqrt(dx * dx + dy * dy);

            // Dessiner '*' si le point est proche du rayon du cercle
            if (std::abs(distance - radius) < 1) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
*/
taille = 6;
    std::cout << std::endl;
    int reste = taille % 2;
    for (int j = 1; j <= taille; ++j) {
        for (int i = 1; i <= taille; ++i) {
            if ( (i == j  && i <= taille /2) ||  (i+j == taille+1 && i > taille /2) )
                std::cout << car;
            else if ( (i == j-1 && i <= taille /2) || ( i+j-1 == taille+1 && i > taille /2) ) 
                std::cout << "-";
            else if ( ( i == j-2 && i-1 <= (taille /2)-1) || ( i+j-2 == taille+1 && i > taille /2)    ) 
                std::cout << "*";
            else if ( ( i == j-3 && i-2 < (taille /2)-1) || ( i+j-3 == taille+1 && i > taille /2)    ) 
                std::cout << "-";
            else
                std::cout << bg;
        }
        std::cout << std::endl;
    }
    return 0;
}
