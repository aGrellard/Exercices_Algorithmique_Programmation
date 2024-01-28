import numpy as np
import matplotlib.pyplot as plt

val = 1
taille = 4
i = 0
j = 0
pattern = np.full((taille, taille), 1)
for i in range(taille):
    for j in range(taille):
        pattern[i, j] = i+val
        val += taille
    val = 1
print(pattern)

# solution david
for i in range(taille):
    for j in range(taille):
        pattern[j, i] = val
        val += 1
print(pattern)

# plt.imshow(pattern, cmap='Blues', interpolation='none')
# plt.axis('off')
# plt.show()
