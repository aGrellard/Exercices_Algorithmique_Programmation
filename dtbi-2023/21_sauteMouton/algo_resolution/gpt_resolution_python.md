Le jeu du saute-mouton, tel que vous l'avez décrit, peut être considéré comme un problème de puzzle où les moutons doivent être déplacés selon certaines règles jusqu'à ce qu'un état cible soit atteint. Pour résoudre ce problème, nous pouvons utiliser une approche algorithmique, telle que la recherche en largeur d'abord (Breadth-First Search, BFS) ou la recherche en profondeur d'abord (Depth-First Search, DFS).

Dans ce cas, je vais utiliser l'algorithme BFS car il est bien adapté pour trouver le chemin le plus court dans les jeux de puzzle avec un petit nombre de mouvements possibles.

Chaque état du jeu peut être représenté par une chaîne de caractères de 7 caractères, où chaque caractère représente une case de la grille. Par exemple, "BBB0NNN" représenterait un état avec 3 moutons blancs (B) à gauche, la case vide (0) au milieu, et 3 moutons noirs (N) à droite. L'état cible serait "NNN0BBB".

Je vais écrire un algorithme pour trouver la séquence de mouvements qui mène à cet état cible.

J'ai trouvé une solution au jeu du saute-mouton. Voici les étapes pour amener les moutons blancs à droite et les moutons noirs à gauche, séparés par la case vide :

1. BBB0NNN
2. BB0BNNN
3. BBNB0NN
4. BBNBN0N
5. BBN0NBN
6. B0NBNBN
7. 0BNBNBN
8. NB0BNBN
9. NBNB0BN
10. NBNBNB0
11. NBNBN0B
12. NBN0NBB
13. N0NBNBB
14. NN0BNBB
15. NNNB0BB
16. NNN0BBB

Chaque étape représente un mouvement où soit un mouton avance dans la case vide, soit il saute par-dessus un autre mouton pour atteindre la case vide. Cette séquence de mouvements permet d'atteindre l'état cible où les moutons noirs (N) sont à gauche, les moutons blancs (B) à droite, et la case vide (0) est entre eux.

```python
from collections import deque

def is_valid_move(state, pos, move):
    """ Check if a move is valid. """
    if move == -1:
        # Move left
        return pos > 0 and state[pos-1] != state[pos]
    elif move == 1:
        # Move right
        return pos < len(state) - 1 and state[pos+1] != state[pos]
    elif move == -2:
        # Jump left
        return pos > 1 and state[pos-2] != state[pos] and state[pos-1] != state[pos]
    elif move == 2:
        # Jump right
        return pos < len(state) - 2 and state[pos+2] != state[pos] and state[pos+1] != state[pos]
    return False

def get_next_states(state):
    """ Get all possible next states from the current state. """
    next_states = []
    empty_pos = state.find('0')
    moves = [-1, 1, -2, 2]  # Left, Right, Jump left, Jump right

    for move in moves:
        if is_valid_move(state, empty_pos, move):
            new_pos = empty_pos + move
            new_state = list(state)
            new_state[empty_pos], new_state[new_pos] = new_state[new_pos], new_state[empty_pos]
            next_states.append("".join(new_state))

    return next_states

def find_solution(start_state, end_state):
    """ Find the solution using Breadth-First Search. """
    queue = deque([(start_state, [start_state])])  # State and path
    visited = set()

    while queue:
        current_state, path = queue.popleft()
        if current_state == end_state:
            return path  # Found the solution

        for next_state in get_next_states(current_state):
            if next_state not in visited:
                visited.add(next_state)
                queue.append((next_state, path + [next_state]))

    return None  # No solution found

# Starting state and ending state
start_state = "BBB0NNN"
end_state = "NNN0BBB"

# Find the solution
solution = find_solution(start_state, end_state)
```

Ce code utilise une recherche en largeur d'abord (Breadth-First Search, BFS) pour trouver le chemin le plus court du début à la fin. Les fonctions `is_valid_move` et `get_next_states` sont utilisées pour générer tous les états valides suivants à partir de l'état actuel. La fonction `find_solution` parcourt l'espace des états jusqu'à trouver la solution.