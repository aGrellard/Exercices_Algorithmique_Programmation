#include <iostream>


int main() {

    std::string saisi_stop = "#";
    const int TAILLE_MAX = 16;
    std::string lettres[TAILLE_MAX];
    size_t mot_pos = 0;

    do
    {
        std::cout << "saisissez une lettre, il vous reste : " << (TAILLE_MAX - mot_pos) << " caractérs disponnible." << std::endl;
        std::cout << "tapez: " << saisi_stop << " pour terminer la saisie" << "\n\n";
        std::cin >> lettres[mot_pos];
        if (lettres[mot_pos] >= "a" && lettres[mot_pos] <= "z" ) {
            mot_pos++;
        } else {
            if (lettres[mot_pos] != saisi_stop) {
                std::cout << "Saisissez un caractère en minuscule sans accent." << std::endl;
            }
        }
        if (mot_pos >= TAILLE_MAX) {
            std::cout << "taille max atteinte" << std::endl;
        }

    } while(lettres[mot_pos] != saisi_stop && mot_pos < TAILLE_MAX );

    std::cout << "le mot :" << std::endl;

    for (size_t i = 0; i < mot_pos; i++)
    {
        std::cout << lettres[mot_pos];
    }
    std::cout << std::endl;
    

    bool isPalindrome = true;
    for (size_t i = 0; i < mot_pos /2 ; i++)
    {
        if (lettres[i] != lettres[ mot_pos - 1 - i]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) {
        std::cout << "est un palindrome" << std::endl;
    } else {
        std::cout << "n'est pas un palindrome" << std::endl;
    }
    #ifdef _WIN32
        system("pause");
    #endif

    

    return 0;
}