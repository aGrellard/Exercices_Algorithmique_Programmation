#include <iostream>
#include <queue>
 
using namespace std;
 
int main() {
    queue<int> fileAttente;
    fileAttente.push(10);
    fileAttente.push(20);
    fileAttente.push(50);
    fileAttente.push(70);
    fileAttente.push(30);
 
    cout<< "Sommet de la file d'attente : "<<fileAttente.front()<<'\n';
    cout<< "La queue de la file d'attente : "<<fileAttente.back()<<'\n';
    cout<< "Taille de la file d'attente : "<<fileAttente.size();
    cout<<'\n';
      
    fileAttente.pop(); // Supprimer le sommet
     
    // Afficher l'ensemble des éléments
    cout<< "Les elements de la file d'attente : ";
    while (!fileAttente.empty()) {
        cout << fileAttente.front() << ' ' ; // Afficher le sommet
        fileAttente.pop(); // supprimer le sommet
    }
 
    cout<<'\n';
 
    cout<< "Taille de la file d'attente apres: "<<fileAttente.size();
 
    return 0;
}