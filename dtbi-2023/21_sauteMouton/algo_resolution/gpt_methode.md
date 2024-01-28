# Algorithme tilisé pour résoudre le jeu de saute-mouton

1. **Représentation de l'état** : Chaque état du jeu est représenté par une chaîne de 7 caractères, où 'B' représente un mouton blanc, 'N' un mouton noir, et 'V' la case vide. Par exemple, 'BBBVNNN' est l'état initial.

2. **Validation des mouvements** : La fonction `is_valid_move` vérifie si un mouvement entre deux états est valide. Un mouvement est valide si un mouton se déplace dans une case vide adjacente ou saute par-dessus un autre mouton pour atteindre une case vide.

3. **Génération des états suivants** : La fonction `get_next_states` génère tous les états possibles à partir de l'état actuel en déplaçant les moutons selon les règles.

4. **Recherche en largeur d'abord (BFS)** : L'algorithme utilise une recherche en largeur d'abord pour explorer systématiquement toutes les combinaisons possibles à partir de l'état initial. Il utilise une file (queue) pour suivre les états à explorer et un ensemble (visited) pour enregistrer les états déjà visités.

5. **Trouver la solution** : L'algorithme parcourt les états jusqu'à ce qu'il atteigne l'état cible ('NNNVBBB'). Une fois cet état atteint, il renvoie le chemin suivi pour y parvenir.

L'algorithme est efficace pour ce type de puzzle car il explore toutes les options possibles de manière structurée et garantit de trouver la solution si elle existe.


## BFS

pour cet algorithme la méthode de recherche en largeur d'abord (Breadth-First Search, BFS) teste les liens directs entre les sommets (états du jeu). Voici comment cela fonctionne :

1. **États et Liens**: Chaque état du jeu est représenté par une configuration spécifique des moutons blancs, noirs et de la case vide (par exemple, "BBBVNNN"). Un "lien" dans ce contexte est un mouvement valide d'un état à un autre, comme le déplacement d'un mouton dans une case vide adjacente ou le saut par-dessus un autre mouton.

2. **Exploration des Liens Directs**: La méthode BFS commence par l'état initial et explore tous les liens directs (mouvements valides) à partir de cet état. Ces mouvements mènent à de nouveaux états qui sont ajoutés à la file d'attente pour une exploration ultérieure.

3. **Pas d'Exploration Indirecte**: La méthode BFS n'explore pas les liens indirects dans le sens où elle ne saute pas d'états. Elle suit chaque mouvement possible à partir de l'état actuel, puis passe au prochain état dans la file d'attente, en respectant l'ordre d'arrivée.

4. **Objectif**: L'objectif est de trouver le chemin de l'état initial à l'état cible ("NNNVBBB") en suivant les règles du jeu. La BFS est idéale pour cela, car elle garantit de trouver le chemin le plus court si un chemin existe.

En résumé, la BFS dans ce code teste uniquement les liens directs, c'est-à-dire les mouvements valides d'un état à l'autre, sans sauter d'états ou explorer des chemins indirects.

## BFS 2

La recherche en largeur d'abord (Breadth-First Search, BFS) est un algorithme de parcours ou de recherche dans les structures de données en graphe ou en arbre. Voici quelques points clés de cet algorithme :

1. **Niveau par Niveau** : BFS explore tous les nœuds (ou états) d'un niveau avant de passer au niveau suivant. Cela signifie qu'il examine d'abord tous les nœuds directement accessibles depuis le nœud de départ, puis tous les nœuds accessibles en deux mouvements, et ainsi de suite.

2. **File d'Attente** : BFS utilise une file d'attente pour gérer l'ordre de visite des nœuds. Les nœuds sont ajoutés à la file lorsqu'ils sont découverts et retirés de la file lorsqu'ils sont explorés.

3. **Découverte et Exploration** : Lorsqu'un nœud est découvert pour la première fois, il est ajouté à la file. Lorsqu'un nœud est retiré de la file, il est considéré comme exploré, et tous ses voisins non explorés sont ajoutés à la file.

4. **Sans Redondance** : Pour éviter de revisiter les mêmes nœuds, BFS garde une trace des nœuds déjà visités.

Dans l'algorithme du puzzle des moutons, la mise en place de BFS se fait comme suit :

- **Initialisation** : L'état initial est ajouté à la file d'attente. Cet état est également marqué comme visité.

- **Boucle Principale** : Tant que la file d'attente n'est pas vide, l'algorithme retire le premier état de la file. Cet état est alors considéré comme exploré.

- **Génération des États Suivants** : À partir de l'état actuel, tous les états suivants possibles sont générés (en respectant les règles de mouvement des moutons).

- **Vérification et Ajout à la File** : Chaque nouvel état généré est vérifié pour s'assurer qu'il n'a pas été visité auparavant. S'il est nouveau, il est ajouté à la file d'attente et marqué comme visité.

- **Recherche de la Solution** : Ce processus continue jusqu'à ce que l'état cible (solution) soit trouvé ou que la file d'attente soit vide (ce qui signifie qu'il n'y a pas de solution).

La file d'attente garantit que l'algorithme parcourt les états de manière systématique, en explorant toutes les possibilités à un niveau donné avant de passer au niveau suivant, assurant ainsi une exploration exhaustive de l'espace des états.