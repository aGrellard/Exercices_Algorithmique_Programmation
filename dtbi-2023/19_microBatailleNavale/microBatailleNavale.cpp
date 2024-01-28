#include <iostream>
#include <vector>
#include <random>

int main() {
    const std::string demander_col = "Quelle colonne ?";
    const std::string demander_row = "Quelle ligne ?";
    const size_t TAILLE  = 4;

    std::vector<std::vector<int>> matrix_user(TAILLE, std::vector<int>(TAILLE, 0));

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, TAILLE);
    size_t ligne_alea  = static_cast<size_t>(distrib(gen)); // de 1 à 4 
    size_t col_alea  = static_cast<size_t>(distrib(gen)); // de 1 à 4 

    int saisi_ligne = 0, saisi_col = 0;
    bool bonneReponse = false;
    std::cout << "l: " << ligne_alea << " - c: " << col_alea << std::endl;
    while (!bonneReponse)
    {
        // system("cls");
        for (size_t i = 0; i < TAILLE; ++i)
        {
            for (size_t j = 0; j < TAILLE; ++j)
            {
                if (matrix_user[i][j] == 1) {
                    std::cout << "x ";
                } else {
                    std::cout << "? ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << demander_row << std::endl;
        std::cin >> saisi_ligne;
        std::cout << demander_col << std::endl;
        std::cin >> saisi_col;

        saisi_ligne -= 1;
        saisi_col -= 1;

        std::cout << "sl: " << saisi_ligne << " - sc: " << saisi_col << std::endl;

        if ((saisi_col >= 0  && saisi_col < 4) && (saisi_ligne >= 0  && saisi_ligne < 4)) {
            matrix_user[static_cast<size_t>(saisi_ligne)][static_cast<size_t>(saisi_col)] = 1;
            if (static_cast<size_t>(saisi_col+1) == col_alea && static_cast<size_t>(saisi_ligne+1) == ligne_alea) {
                bonneReponse = true;
                system("cls");
                std::cout << "Plouf coule" << std::endl;
            }
        }  
    }
    #ifdef _WIN32
        system("pause");
    #endif
    return 0;
}