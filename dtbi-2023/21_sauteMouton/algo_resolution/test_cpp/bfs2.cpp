#include <iostream>
#include <list>
#include <queue>

class Graph {
    int numVertices;             // Nombre de sommets
    std::list<int> *adjLists;    // Liste d'adjacence

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjLists = new std::list<int>[vertices];
    }

    void addEdge(int src, int dest) {
        adjLists[src].push_back(dest); // Ajouter une arête du src au dest
    }

    void BFS(int startVertex) {
        std::vector<bool> visited(numVertices, false);
        std::queue<int> queue;

        visited[startVertex] = true;
        queue.push(startVertex);

        while (!queue.empty()) {
            int currVertex = queue.front();
            std::cout << "Visited " << currVertex << " ";
            queue.pop();

            for (int adjVertex : adjLists[currVertex]) {
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    queue.push(adjVertex);
                }
            }
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    std::cout << "BFS starting from vertex 0:\n";
    g.BFS(0);

    return 0;
}
