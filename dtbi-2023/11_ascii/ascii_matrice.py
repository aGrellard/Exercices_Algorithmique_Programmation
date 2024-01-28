# https://chat.openai.com/share/0e85bd41-6e9b-41c2-9924-6c3e8cb10373 install numpy et matplotlib + algo python
# https://chat.openai.com/share/afd2b704-be10-4ba5-8481-ecb419f921c8 convertion cpp || pseudocode -> python


import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def plot_pattern_scatter(pattern, marker='o'):
    """
    Affiche le motif en utilisant scatter avec un type de marqueur spécifié.
    """
    # Coordonnées pour la valeur 'car' (par exemple, 1)
    x_car, y_car = np.where(pattern == 1)
    plt.scatter(y_car, taille - 1 - x_car, color='black', marker=marker)  # Inverser et ajuster l'axe x

    # Coordonnées pour la valeur 'bg' (par exemple, 0)
    x_bg, y_bg = np.where(pattern == 0)
    plt.scatter(y_bg, taille - 1 - x_bg, color='white', marker=marker)  # Inverser et ajuster l'axe x

    # Coordonnées pour la valeur 'autre' (par exemple, 2)
    x_autre, y_autre = np.where(pattern == 2)
    plt.scatter(y_autre, taille - 1 - x_autre, color='gray', marker=marker)  # Inverser et ajuster l'axe x

    plt.xlabel('Axe Y')
    plt.ylabel('Axe X')
    plt.xticks(range(taille))
    plt.yticks(range(taille))
    plt.grid(True)  # Afficher la grille
    plt.show()
    
def create_pattern(forme=0, taille=10, car=1, bg=0):
    pattern = np.full((taille, taille), bg)
    reste = taille % 2
    for j in range(taille):
        for i in range(taille):
            match forme:
                case 0:
                    pattern[j, i] = car
                case 1:
                    if i == taille - 1 or i == 0 or j == taille - 1 or j == 0 :
                        pattern[j, i] = car
                case 2:
                    if (i+j) % 2 == 0:
                        pattern[j, i] = car
                case 3:
                    if i == taille - 1 or i == j or j == 0:
                        pattern[j, i] = car
                case 4:
                    if i == j or i+j == taille-1:
                        pattern[j, i] = car
                case 5:
                    if i == 0 or j == taille-1 or i == j or i+j == taille-1:
                        pattern[j, i] = car
                case 6:
                    if (    (j + i+1 == (taille+reste) / 2) or 
                            (i - j+reste == (taille+reste) / 2) or
                            (i == (taille-reste) / 2 or i == (taille-2 ) / 2) or
                            (j == (taille-reste) / 2 or j == (taille-2 ) / 2) or
                            (j+reste - i ==  (taille+reste) / 2) or
                            (j+reste + i+1 == taille +(taille+reste) / 2)  
                            ):
                        pattern[j, i] = car


    return pattern

taille = 19
i = 6
pattern = create_pattern(i, taille, 1, 0)
print(pattern)
plot_pattern_scatter(pattern)    
