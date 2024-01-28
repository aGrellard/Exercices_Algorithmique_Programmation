#include <random>
#include <string>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <windows.h>


int main() {

    const size_t TAILLE_X = 20;
    const size_t TAILLE_Y = 70;

    std::string katakana = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789@#$%^&*()*&^%+-/";
    for (char c = 'A'; c <= 'Z'; ++c) {
        katakana += c;
    }
    for (char c = '1'; c <= '9'; ++c) {
        katakana += c;
    }
    std::string caracs = "@#$%^&*()*&^%+-/";
    katakana += caracs;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> katakana_alea(0,static_cast<int>(katakana.size()) - 1);
    std::vector<std::vector<char>> matrix(TAILLE_X, std::vector<char>(TAILLE_Y));



    for (size_t i = 0; i < TAILLE_X; ++i)
    {
        for (size_t j = 0; j < TAILLE_Y; ++j)
        {
            char random_char = katakana[static_cast<size_t>(katakana_alea(gen))];
            matrix[i][j] = random_char;
            if (j>0) std::cout <<  " ";
            std::cout << random_char;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // ALGO POUR LE FUN 
    // MATRIX IN THE CONSOLE 
    /*
        generation d'une postion aléatoire sur la 1er ligne
            rnd = 0 to end width of string
            row[0][rnd] placer un caractér dans une string de la lrageur de la ligne TAILLE_Y
        afficher toutes les lignes du vecteur avec un \n
        ensuite fair défiler ver le ba 
            ecraser chaque ligne par la ligne précédente
        réinitialiser la 1er ligne  
        remonter en haut de lécran

        gestion du temps avec chrono
        voir pdcurses    

        chaque ligne descend d'une postion, puis on efface la precedente, on remote ne haut
        sa doit donner un efet ou on voit les les lettre descendre ve le bas

    */
    std::vector<std::string> MatrixAnnime(TAILLE_X, std::string(TAILLE_Y, ' '));
    std::uniform_int_distribution<> ligne_1(0, TAILLE_Y - 1);

    auto last_time = std::chrono::steady_clock::now();
    while (true)
    {
        auto current_time = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - last_time);

        
        char random_char = katakana[static_cast<size_t>(katakana_alea(gen))];
        int x = ligne_1(gen);
        MatrixAnnime[0][static_cast<size_t>(x)] = random_char;

 

        for (const auto& line : MatrixAnnime) {
            std::cout << line << std::endl;
        }      
        
        /*
        for (size_t i = 0; i < TAILLE_X; ++i)
        {
            auto befor = MatrixAnnime[i];
            MatrixAnnime[i] = MatrixAnnime[i + 1];
            std::cout << "(" << i << "," << i+1 << ") = " << befor << " after: " << MatrixAnnime.at(i) << std::endl;
        }
        */
        
        for (size_t i = TAILLE_X - 1; i > 0; --i) {
            // auto befor = MatrixAnnime[i];
            MatrixAnnime[i] = MatrixAnnime[i - 1];
            // std::cout << "(" << i << "," << i-1 << ") = " << befor << " after: " << MatrixAnnime.at(i) << std::endl;
        }
        
        // effecer la ligne
        // effacer de manierre progrssive
        if (elapsed.count() > rand() % 80) { 
            last_time = current_time; 
            MatrixAnnime[0] = std::string(TAILLE_Y, ' ');
        }

        // sleep(ms)
        // voir avec chrono pour un timer
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        // std::cout << "[2J[H";
        std::cout << "\x1B[H";

        // std::cout<<"----------\n";


    }

    return 0;
}
/*
https://www.cse.psu.edu/~kxc104/class/cse472/09f/hw/hw7/vt100ansi.htm

<ESC> represents the ASCII "escape" character, 0x1B. Bracketed tags represent modifiable decimal parameters; eg. {ROW} would be replaced by a row number. 

Erasing Text

Erase End of Line	<ESC>[K

    Erases from the current cursor position to the end of the current line.

Erase Start of Line	<ESC>[1K

    Erases from the current cursor position to the start of the current line.

Erase Line		<ESC>[2K

    Erases the entire current line.

Erase Down		<ESC>[J

    Erases the screen from the current line down to the bottom of the screen.

Erase Up		<ESC>[1J

    Erases the screen from the current line up to the top of the screen.

Erase Screen		<ESC>[2J <<<<<<<<<<<<<<<<<<<<<<


Cursor Control

Cursor Home 		<ESC>[{ROW};{COLUMN}H

    Sets the cursor position where subsequent text will begin. If no row/column parameters are provided (ie. <ESC>[H), the cursor will move to the home position, at the upper left of the screen.


    [2J[H

*/ 