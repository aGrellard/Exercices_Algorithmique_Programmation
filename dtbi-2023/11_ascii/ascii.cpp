#include <iostream>
#include <vector>

const int TAILLE = 9;


void dessinerMotif(int forme, std::string symbole);

int main() {

    std::string symbole = "# ";

    dessinerMotif(0, symbole);
    dessinerMotif(1, symbole);
    dessinerMotif(2, symbole);
    dessinerMotif(3, symbole);
    dessinerMotif(4, symbole);
    dessinerMotif(5, symbole);
    dessinerMotif(6, symbole);

    #ifdef _WIN32
        system("pause");
    #endif
    return 0;
}

void dessinerMotif(int forme, std::string symbole) {
    int reste = TAILLE % 2;
    for (size_t row = 0; row < TAILLE; row++)
    {
        for (size_t col = 0; col < TAILLE; col++)
        {
            switch (forme)
            {
            case 0:
                std::cout << symbole;
                break;
            case 1: 
                if (col == 0 || col == TAILLE-1 || row == 0 || row == TAILLE-1) {
                    std::cout << symbole;
                } else {
                    std::cout << "  ";
                } 
                break;
            case 2:
                if (col == row || row+col == TAILLE-1) {
                    std::cout << symbole;
                } else {
                    std::cout << "  ";
                } 
                break;
            case 3: 
                if (col == 0 || row == TAILLE-1 || row == col) {
                    std::cout << symbole;
                } else {
                    std::cout << "  ";
                } 
                break;
            case 4: 
                if (
                row+col+1 == (TAILLE+reste)/2 ||
                row+reste+col+1 ==  TAILLE + (TAILLE+reste)/2 ||
                row-col+reste == ((TAILLE+reste)/2) ||
                col+reste-row == ((TAILLE+reste)/2) 
                ) {
                    std::cout << symbole;
                } else {
                    std::cout << "  ";
                } 
                break;
            case 5: 
                if (
                col == TAILLE-1 && row >= (TAILLE+reste)/2 || row == TAILLE-1 && col >= (TAILLE+reste)/2 ||
                row ==(TAILLE)/2 || row+(reste?0:1) ==(TAILLE)/2 ||
                col == 0 && row < (TAILLE+reste)/2 || row == 0 && col < (TAILLE+reste)/2 ||
                row+col+1 == (TAILLE+reste)/2 ||
                row+reste+col+1 ==  TAILLE + (TAILLE+reste)/2 ||
                row-col+reste == ((TAILLE+reste)/2) ||
                col+reste-row == ((TAILLE+reste)/2) 
                ) {
                    std::cout << symbole;
                } else {
                    std::cout << "  ";
                } 
                break;  
            case 6: 
                if ((col+row)% 2 == 0) {
                    std::cout << symbole;
                } else {
                    std::cout << "  ";
                } 
                break;
            default:
                break;
            }
        }
        std::cout << std::endl;
    }  
    std::cout << std::endl;  
}

