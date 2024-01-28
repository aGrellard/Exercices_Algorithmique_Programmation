#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>


float stringToFloat(const std::string &value) {
  std::string temp = value;
  std::replace(temp.begin(), temp.end(), ',', '.');
  std::stringstream ss(temp);
  float result;
  ss >> result;
  return result;
}
bool noteSaisieIsDigit(const std::string &value) {
  if (value == "-1") return true;
  for (char c : value) {
    if (!std::isdigit( static_cast<unsigned char>(c)) && c!='.' && c!=',') {
      return false;
    }
  }
  return true;
}

int main() {

  const int TAILLE_MAX = 5;
  const std::string demander_note =
      "Saisissez un note, (-1 pour terminer la saisie)";

  float notes[TAILLE_MAX];
  int nb_notes = 0;
  float moyenne = 0;
  float notes_somme = 0;

  float terminer_saisie = -1;
  float saisie = 0;
  std::string saisieStr = "";

  while (nb_notes < TAILLE_MAX && saisie != terminer_saisie) {
    std::cout << demander_note
              << ", vous pouvez saisir encor : " << (TAILLE_MAX - nb_notes)
              << " notes" << std::endl;
    std::cin >> saisieStr;
    if (noteSaisieIsDigit(saisieStr)) {
      saisie = stringToFloat(saisieStr);
      if (saisie != terminer_saisie) {
        notes[nb_notes] = saisie;
        notes_somme += saisie;
        nb_notes++;
      }
    }
  }
  if (nb_notes>0) {
    std::cout << "la moyenne des notes (";
    for (int i = 0; i <= nb_notes -1; i++) {
      if (i > 0)
        std::cout << "; ";
      std::cout << notes[i];
    }
    moyenne = (notes_somme / static_cast<float>(nb_notes));
    std::cout << std::fixed << std::setprecision(2);
    std::cout << ") est de " << abs(moyenne) << std::endl;
    std::cout << "sur un total de: " << nb_notes << " notes pour une somme de: " << notes_somme << std::endl;
  }

  return 0;
}
