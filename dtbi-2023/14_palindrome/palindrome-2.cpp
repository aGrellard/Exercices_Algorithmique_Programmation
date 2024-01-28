#include <iostream>
#include <vector>


int main() {

    const std::string SAISIE_STOP = "#";
    const size_t TAILLE_MAX = 16;
    std::vector<std::string> lettres;
    std::string saisie = "";

    while (lettres.size() < TAILLE_MAX)
    {
        std::cout << "Saisissez une lettre (a-z), ou " << SAISIE_STOP << " pour terminer. "
                  << "Il vous reste : " << (TAILLE_MAX - lettres.size()) << " caractères disponibles." << std::endl;


        std::cin >> saisie;

        if (saisie == SAISIE_STOP) break;

        if (saisie.length() == 1 && std::islower(saisie[0])){
            lettres.push_back(saisie);
        } else {
            std::cout << "Veuillez saisir un caractère de a à z en minuscule sans accent." << std::endl;
        }
    }

    std::cout << "le mot :" << std::endl;
    for (const auto &lettre : lettres) {
        std::cout << lettre;
    }
    std::cout << std::endl;
    

    // 1: 1er position de la 1er sequence 2: dernierre postion de la 1er sequence, 3: 1er postion de la 2eme sequence
    bool isPalindrome = std::equal( 
        lettres.begin(), // itterateur qui pointe ver le 1er element du vecteur (deplacement avec ++) 
        lettres.begin() + lettres.size() / 2, // std::ptrdiff_t
        lettres.rbegin() // itterateur inversé  qui pointe ver le dernier element du vecteur (deplacement avec ++)
        );

    if (isPalindrome) {
        std::cout << "est un palindrome" << std::endl;
    } else {
        std::cout << "n'est pas un palindrome" << std::endl;
    }

    

    return 0;
}