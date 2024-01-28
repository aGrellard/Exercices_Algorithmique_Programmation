#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Ajout d'une arête au graphe
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Recherche en largeur d'abord (BFS) pour vérifier l'existence d'un chemin
bool BFS(vector<int> adj[], int start, int end, int n) {
    vector<bool> visited(n, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == end) {
            return true;  // Chemin trouvé
        }

        // Parcourir les voisins
        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    return false;  // Chemin non trouvé
}

int main() {
    int n = 5;  // Nombre de nœuds dans le graphe
    vector<int> adj[n];  // Liste d'adjacence pour représenter le graphe

    // Création d'un graphe exemple
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);

    int start = 0;  // Nœud de départ
    int end = 4;    // Nœud d'arrivée

    if (BFS(adj, start, end, n)) {
        cout << "Il existe un chemin entre " << start << " et " << end << endl;
    } else {
        cout << "Il n'existe pas de chemin entre " << start << " et " << end << endl;
    }

    return 0;
}
