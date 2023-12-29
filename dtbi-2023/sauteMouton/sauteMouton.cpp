#include <iostream>
#include <vector>
#include <format> 
#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h> // HANDLE, DWORD, ENABLE_ECHO_INPUT, GetStdHandle, GetConsoleMode, SetConsoleMode
#endif

enum class Direction { DROITE, GAUCHE };
enum class Action { AVANCER, SAUTER, AVANCERSAUTER };
enum class Etat { OCCUPE, LIBRE };

auto resetResult(std::vector<int> & vec) {
    for (size_t i = 0; i < vec.size(); i++)
    {
        vec.at(i) = -1;
    }
};
auto checkResult(const std::vector<int> & vec) {
    if (vec.at(0) == 0 && vec.at(1) == 0 ) {
        std::cout << "Le mouton ne peut pas avancer ni sauter" << std::endl;
    }
};
auto checkReturn(int check, const std::vector<std::vector<int>> & tab) {
    switch (check)
    {
    case 1:
        std::cout << "La séléction est supérieur aux nombres de mouton disponnible: 0/" << tab.size() -1 << std::endl;
        break;
    case 2:
        std::cout << "La séléction n'est pas occupé par un mounton" << std::endl;
        break;
    case 3:
        std::cout << "Le mouton ne posséde pas de sens pour avancer" << std::endl;
        break;
    default:
        break;
    }
};
auto checkDeplacement(int check) {
    switch (check)
    {
    case 1:
        std::cout << "Vous n'avez pas saisi la bonne action (0: Avancer) (1: Sauter)" << std::endl;
        break;
    case 2:
        std::cout << "La destination n'a pas été définie" << std::endl;
        break;
    default:
        break;
    }
};

auto actionToString(int action) {
    switch (action)
    {
    case 0:
        return "AVANCER";
        break;
    case 1:
        return "SAUTER";
        break;
    default:
        return "ERREUR";
        break;
    }
};

auto directionToString(int dir) {
    switch (dir)
    {
    case 0:
        return "DROITE";
        break;
    case 1:
        return "GAUCHE";
        break;
    default:
        return "ERREUR";
        break;
    }
};

int deplacerMouton(size_t mSel, Action action, const std::vector<int> & result, std::vector<std::vector<int>> & tab) {
    if (action != Action::AVANCER && action != Action::SAUTER) return 1;

    int destination = -1;

    int myDir = tab.at(mSel).at(1);

    switch(action) {
        case Action::AVANCER:
            if (result.at(0)==1) {
                if (myDir == 0) {
                    destination = static_cast<int>(mSel + 1);
                } else if (myDir == 1) {
                    destination = static_cast<int>(mSel - 1);
                } else {}
            }
        break;
        case Action::SAUTER:
            if (result.at(1)==1) {
                if (myDir == 0) {
                    destination = static_cast<int>(mSel + 2);
                } else if (myDir == 1) {
                    destination = static_cast<int>(mSel - 2);
                } else {}
            }
        break;
        default:
        break;
    }

    std::cout << "Mouton(" << mSel << ") => " << directionToString(myDir) << " " << actionToString(static_cast<int>(action)) << " => " << destination << std::endl;

    if (destination == -1) {
        return 2;
    }

    tab.at(mSel).at(0) = 0;
    tab.at(mSel).at(1) = 0;

    tab.at(static_cast<size_t>(destination)).at(0) = 1;
    tab.at(static_cast<size_t>(destination)).at(1) = myDir;

    return 0;
}

int checkPostion(size_t mSel, const std::vector<std::vector<int>> & tab, std::vector<int> & result) {
    if (mSel > tab.size() -1 ) return 1;
    if (tab.at(mSel).at(0) == 0) return 2;

    Direction dir = Direction::DROITE;
    if (tab.at(mSel).at(1) == 0 ) {
        dir = Direction::DROITE;
    } else if (tab.at(mSel).at(1) == 1 ) {
        dir = Direction::GAUCHE;
    } else {
        return 3;
    }
    
    bool avancer = false;
    bool sauter = false;
    int checkSel = (int)mSel;
    switch (dir)
    {
    case Direction::DROITE:
        if (static_cast<size_t>(checkSel+2) <= tab.size() -1) {
            if (tab.at(mSel+2).at(0) == 0) {
                sauter = true;
            } else {
                sauter = false;
            }
        }
        if (static_cast<size_t>(checkSel+1) <= tab.size() -1) {
            if (tab.at(mSel+1).at(0) == 0) {
                avancer = true;
            } else {
                avancer = false;
            }
        }
        break;
    case Direction::GAUCHE:
        if (checkSel-2 >= 0) {
            if (tab.at(mSel-2).at(0) == 0) {
                sauter = true;
            } else {
                sauter = false;
            }
        }
        if (checkSel-1 >= 0) {
            if (tab.at(mSel-1).at(0) == 0) {
                avancer = true;
            } else {
                avancer = false;
            }
        }
        break;
    default:
        break;
    }

    result.at(0) = static_cast<int>(avancer);
    result.at(1) = static_cast<int>(sauter);
    result.at(2) = static_cast<int>(dir);

    return 0;
}

void afficherGrille(const std::vector<std::vector<int>> & pos_moutons) {
    std::vector<int> result({-1, -1, -1});

    std::cout << std::endl;
    for (size_t i = 0; i < pos_moutons.size(); i++)
    {
        std::string str = std::format(" {:<2}", i);
        std::cout << "|" << str;
    }
    std::cout << std::endl;
    for (size_t i = 0; i < pos_moutons.size(); i++)
    {
        resetResult(result);
        checkPostion(i, pos_moutons, result);

        std::string direction;
        if (result.at(2) == 0) {
            direction = ">";
        } else if (result.at(2) == 1) {
            direction = "<";
        } else {
            direction = " ";
        }

        std::string str = std::format(" {:<2}", direction);
        std::cout << "|" << str;
    }
}

void ordinateur_jouer(size_t mSel, std::vector<int> & result, std::vector<std::vector<int>> & tab) {
    resetResult(result);
    int check = checkPostion(mSel, tab, result);
    if (check == 0) {
        if (deplacerMouton(mSel, Action::AVANCER, result, tab) != 0) {
            deplacerMouton(mSel, Action::SAUTER, result, tab);
        }
    }    
}

bool partie_gagner(const std::vector<std::vector<int>> & pos_moutons) {
    size_t goodDir = 0;
    for (size_t i = 0; i < pos_moutons.size(); i++)
    {
        if ( i < (pos_moutons.size()-1)/2) {
            if (pos_moutons.at(i).at(1) == 1 && pos_moutons.at(i).at(0) == 1) {
                goodDir++;
            }
        } else if (i > (pos_moutons.size())/2) {
            if (pos_moutons.at(i).at(1) == 0 && pos_moutons.at(i).at(0) == 1) {
                goodDir++;
            }
        }
    }
    return (goodDir == pos_moutons.size()-1);
}
bool partie_perdu(const std::vector<std::vector<int>> & tab) {
    std::vector<int> result({-1, -1, -1});
    int finPartie = 0;
    for (size_t i = 0; i < tab.size(); i++)
    {
        resetResult(result);
        int checkPos = checkPostion(i, tab, result);
        if (checkPos == 0 && (result.at(0) == 1 || result.at(1) == 1)) {
            finPartie++;
        }
    }
    return (finPartie == 0);
}

void ordinateur_route(std::vector<int> & result, std::vector<std::vector<int>> & tab) {
    std::vector<size_t> route({2, 4, 5, 3, 1, 0, 2, 4, 6, 5, 3, 1, 2, 4, 3});
    for (size_t i = 0; i < route.size(); i++)
    {
        ordinateur_jouer(route.at(i), result, tab);
    }
    afficherGrille(tab);
    std::cout << std::endl;
    if (partie_gagner(tab)) {
        std::cout << "Partie gagné" << std::endl;
    } else {
        if (partie_perdu(tab)) {
            std::cout << "Partie perdu" << std::endl;
        }
    }

}

int lancer_partie(std::vector<int> & result, std::vector<std::vector<int>> & tab) {
    int _return = 0;
    int checkPos, checkDepl, action; 
    int mSel = 0;
    bool continuer = true;
    while (continuer)
    {
        std::cout << "Choisissez un mouton de 0 à " << tab.size()-1 << ", (-1 pour quitter)" << std::endl;
        std::cin >> mSel; // un entier est attendu
        if (std::cin.fail()) {
            std::cin.clear(); // Efface l'état d'erreur de cin

            /*
            lorsqu'un utilisateur saisit du texte là où un nombre était attendu.
            Permet de vider le tampon d'entrée pour se débarrasser des données erronées ou superflues, 
            évitant ainsi des problèmes lors des lectures de données suivantes.
            */
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore le reste de la ligne
            
            std::cout << "Ce n'est pas un chiffre valide." << std::endl;
            continue;
        } else if (mSel == -1) {
            continuer = false;
            _return = 1;
            continue;
        } else if (mSel >= 0 || mSel > static_cast<int>(tab.size()-1)) {
            checkReturn(1, tab);
            continue;
        }

        resetResult(result);
        checkPos = checkPostion(static_cast<size_t>(mSel), tab, result);
        checkReturn(checkPos, tab);
        checkResult(result);
        std::cout << std::endl;

        if (checkPos == 0 && (result.at(0) == 1 || result.at(1) == 1)) {
            std::cout << "Avancer (0) ou Sauter (1) ?" << std::endl;
            std::cin >> action;
            if (std::cin.fail()) {
                std::cin.clear(); // Efface l'état d'erreur de cin
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore le reste de la ligne
                std::cout << "Ce n'est pas un chiffre valide." << std::endl;
                continue;
            } else if (action < 0 || action > 1) {
                checkDeplacement(1);
                continue;
            }

            checkDepl = deplacerMouton(static_cast<size_t>(mSel), static_cast<Action>(action), result, tab);
            if (checkDepl != 0) {
                std::cout << "Le mouton ne peut pas : " << actionToString(action) << std::endl;
                checkDeplacement(checkDepl);
                std::cout << std::endl;
            } 
            afficherGrille(tab);
            std::cout << std::endl;
        }

        if (partie_gagner(tab)) {
            std::cout << "Partie gagné" << std::endl;
            continuer = false;
            _return = 2;
        } else {
            if (partie_perdu(tab)) {
                std::cout << "Partie perdu" << std::endl;
                continuer = false;
                _return = 3;
            }
        }

    }  
    return _return;  
}



int main() {

    #if defined(_WIN32) || defined(_WIN64)
        SetConsoleOutputCP(65001); // Permet l'affichage des caractères spéciaux
    #endif

    std::vector<std::vector<int>> pos_moutons({{1,0}, {1,0}, {1,0}, {0,0}, {1,1}, {1,1}, {1,1}});
    std::vector<int> result({-1, -1, -1});


    afficherGrille(pos_moutons);
    std::cout << std::endl;
    int partie = lancer_partie(result, pos_moutons);
    if (partie == 1) {
        std::cout << "Partie quitté" << std::endl;
    } else if (partie == 2) {
        std::cout << "Partie gagné" << std::endl;
    } else if (partie == 3) {
        std::cout << "Partie perdu" << std::endl;
    } else {
        std::cout << "Le jeu n'a pas commencé" << std::endl;
    }

    // ordinateur_route(result, pos_moutons);

    /*
    std::cout << 
        "Mouton(0, " << tab.at(i).at(0) << ", " << 
        tab.at(i).at(1) << ") => Avancer: " << 
        result.at(0) << " Sauter: " << 
        result.at(1) << " Dir: " << 
        directionToString(result.at(2)) << std::endl;
    checkReturn(check, tab); 
    */

    #if defined(_WIN32) || defined(_WIN64)
        system("pause");
    #endif
    return 0;
}

