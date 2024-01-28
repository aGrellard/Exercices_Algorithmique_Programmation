#include <iostream>
#include <string>

using namespace std;

int main() {
  int taille, forme;
  string caractere;

  cout << "Saisir la taille: ";
  cin >> taille;
  cout << "Saisir le caractere: ";
  cin >> caractere;
  cout << "Saisir la forme (1-Rectangle plein, 2-Rectangle creux, 3-Croix, "
          "4-Triangle, 5-Losange, 6-Damier): ";
  cin >> forme;

  int pos = 0;
  bool changementAxe = false;
  bool doubleLigne = false;
  int reste = taille % 2;
  int mid = (taille / 2) + reste;
  int mid2 = 0;
  if (reste) {
    mid2 = mid;
  } else {
    mid2 = mid + 1;
  }

  cout << endl;
  cout << "caractere: " << caractere << endl;
  cout << "taille: " << taille << endl;
  cout << "mid: " << mid << endl;
  cout << "reste: " << reste << endl;
  cout << endl;


  switch (forme) {
  case 1: // Rectangle plein
    for (int i = 0; i < taille; ++i) {
      for (int j = 0; j < taille; ++j) {
        cout << caractere;
      }
      cout << endl;
    }
    break;

  case 2: // Rectangle creux
    for (int i = 1; i <= taille; i++) {
      for (int j = 1; j <= taille; j++) {
        if (i == 1 || i == taille || j == 1 || j == taille) {
          cout << caractere;
        } else {
          cout << " ";
        }
      }
      cout << endl;
    }
    break;

  case 3: // Croix
    for (int row = 1; row <= taille; row++) {
      for (int col = 1; col <= taille; col++) {
        if (col == (pos+1) || col == (taille - pos)) {
          cout << caractere;
        } else {
          cout << " ";
        }
      }
      if (taille % 2 != 0) {
        if ((pos+1) * 2 > taille) {
          changementAxe = true;
        }
      } else {
        if ((pos+1) * 2 >= taille) {
          changementAxe = true;
          if (!doubleLigne) {
            doubleLigne = true;
            cout << endl;
            continue;
          }
        }
      }
      if (!changementAxe) {
        pos++;
      } else {
        pos--;
      }
      cout << endl;
    }
    break;

  case 4: // Triangle
    for (int row = 1; row <= taille; row++) {
      for (int col = 1; col <= taille; col++) {
        if (row == taille) {
          cout << caractere;
        } else {
          if (col == 1 || col == pos) {
            cout << caractere;
          } else {
            cout << " ";
          }
        }
      }
      pos++;
      if (pos == 1)
        pos = 2;
      cout << endl;
    }
    break;

  case 5:
    pos = 0;
    for (int row = 1; row <= taille; row++) {
      for (int col = 1; col <= taille; col++) {
        if (col == 1 && (row == mid || row == mid2)) {
          cout << caractere;
        } else if (col == taille && (row == mid || row == mid2)) {
          cout << caractere;
        } else if (row == 1 && (col == mid || col == mid2)) {
          cout << caractere;
        } else if (row == taille && (col == mid || col == mid2)) {
          cout << caractere;
        } else {
          if (row > 1 && row < mid) {
            if (pos == 0) {
              pos = 1;
            }
            if (pos) {
              if (col == (mid - pos) || col == (mid2 + pos)) {
                cout << caractere;
              } else
                cout << "-";
            }
          } else if (row > mid2) {
            if (col == (pos + 1) || col == (taille - pos)) {
              cout << caractere;
            } else
              cout << "-";
          } else
            cout << "-";
        }
      }
      if (pos)
        pos++;
      if (reste) {
        if (row == mid)
          pos = 1;
      } else {
        if (row == mid + 1)
          pos = 1;
      }
      cout << endl;
    }
    break;
  default:
    cout << "Forme non reconnue." << endl;
  }

#ifdef _WIN32
  system("pause");
#endif

  return 0;
}
