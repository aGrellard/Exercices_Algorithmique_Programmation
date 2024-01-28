#include <iostream>

int main() {
    const int TAILLE = 3;

    int tab2D[TAILLE][TAILLE];

    int val = 1;

    for (int i = 0; i <= TAILLE - 1; i++)
    {
        for (int j = 0; j <= TAILLE - 1 ; j++)
        {
            std::cout << "(" << i << "," << j << ") = " << val << std::endl;
            tab2D[i][j] = val;
            val++;        
        }
        std::cout << "---" << std::endl;
        
    }
    

    return 0;
}