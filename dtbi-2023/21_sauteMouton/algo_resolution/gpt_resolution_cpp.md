# code 

```cpp
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool IsValidMove(const string& current, const string& next) {
    int diff_count = 0, last_diff = -1;
    for (int i = 0; i < current.size(); ++i) {
        if (current[i] != next[i]) {
            diff_count++;
            if (last_diff == -1) last_diff = i;
            else if (abs(i - last_diff) > 2) return false;
        }
    }
    return diff_count == 2;
}

vector<string> GetNextStates(const string& state) {
    vector<string> next_states;
    int empty_index = state.find('V');

    for (int i : {-1, 1, -2, 2}) {
        if (empty_index + i >= 0 && empty_index + i < state.size()) {
            string next_state = state;
            swap(next_state[empty_index], next_state[empty_index + i]);
            if (IsValidMove(state, next_state)) {
                next_states.push_back(next_state);
            }
        }
    }

    return next_states;
}

vector<string> SolveSheepPuzzle() {
    string initial_state = "BBBVNNN";
    string target_state = "NNNVBBB";
    queue<pair<string, vector<string>>> q;
    set<string> visited;

    q.push({initial_state, {initial_state}});
    visited.insert(initial_state);

    while (!q.empty()) {
        auto [current_state, path] = q.front();
        q.pop();

        if (current_state == target_state) {
            return path;
        }

        for (const auto& next_state : GetNextStates(current_state)) {
            if (!visited.count(next_state)) {
                visited.insert(next_state);
                vector<string> new_path = path;
                new_path.push_back(next_state);
                q.push({next_state, new_path});
            }
        }
    }

    return {};
}

int main() {
    vector<string> solution = SolveSheepPuzzle();
    for (const string& state : solution) {
        cout << state << endl;
    }
    return 0;
}
```

Ce code utilise une file d'attente pour gérer la recherche en largeur d'abord (BFS), un ensemble pour suivre les états déjà visités, et des fonctions pour générer les états suivants et vérifier la validité des mouvements. Lorsqu'il trouve la solution, il l'imprime à l'écran.

## fonctionnement

### 1. `IsValidMove`

Cette fonction détermine si un mouvement d'un état à un autre est valide en se basant sur les règles du jeu.

- **Entrée**: Deux chaînes de caractères, représentant l'état actuel et l'état suivant.
- **Processus**: Elle compare les deux chaînes et compte le nombre de différences. Un mouvement valide aura exactement deux différences : la case vide et la position du mouton qui s'est déplacé. En outre, ces différences ne doivent pas être à plus de deux positions d'écart, ce qui correspond soit à un déplacement direct dans une case vide adjacente, soit à un saut par-dessus un mouton.
- **Sortie**: Renvoie `true` si le mouvement est valide, `false` sinon.

### 2. `GetNextStates`

Cette fonction génère tous les états possibles suivant l'état actuel, en respectant les règles de mouvement.

- **Entrée**: Une chaîne de caractères représentant l'état actuel.
- **Processus**: Elle trouve l'index de la case vide, puis essaie de déplacer ou de faire sauter les moutons adjacents dans cette case vide. Pour chaque mouvement potentiel, elle vérifie si c'est un mouvement valide en utilisant `IsValidMove`.
- **Sortie**: Renvoie un vecteur de chaînes de caractères, chaque chaîne représentant un état valide suivant l'état actuel.

### 3. `SolveSheepPuzzle`

Cette fonction implémente l'algorithme BFS pour trouver la solution au puzzle.

- **Processus**:
    - Initialisation : Elle commence par l'état initial ("BBBVNNN") et le place dans une file d'attente, avec le chemin parcouru jusqu'à présent (initialisé à l'état initial).
    - Boucle BFS : La fonction boucle jusqu'à ce que la file d'attente soit vide. À chaque itération, elle retire un élément de la file, vérifie si c'est l'état cible. Si ce n'est pas le cas, elle génère tous les états suivants possibles et les ajoute à la file d'attente, en s'assurant de ne pas revisiter les états déjà explorés.
- **Sortie**: Renvoie un vecteur de chaînes de caractères représentant le chemin de l'état initial à l'état cible.

### 4. `main`

La fonction `main` est le point d'entrée du programme. Elle appelle `SolveSheepPuzzle` et affiche la solution.

- **Processus**: Appelle `SolveSheepPuzzle` et itère sur le vecteur de chaînes de caractères retourné pour imprimer chaque état du chemin de la solution.

Chacune de ces fonctions joue un rôle crucial dans la résolution du puzzle, en travaillant ensemble pour explorer systématiquement toutes les possibilités jusqu'à ce que la solution soit trouvée.