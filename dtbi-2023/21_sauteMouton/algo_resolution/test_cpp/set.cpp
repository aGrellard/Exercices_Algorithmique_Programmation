#include <set>
#include <iostream>

int main() {
    std::set<int> mySet;

    // Ajouter des éléments
    mySet.insert(3);
    mySet.insert(1);
    mySet.insert(2);

    // Tenter d'ajouter un doublon
    mySet.insert(2);

    // Afficher les éléments
    for (int element : mySet) {
        std::cout << element << " "; // Les éléments seront affichés dans l'ordre trié: 1 2 3
    }

    return 0;
}
