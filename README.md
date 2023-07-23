# Sudoku-solver
Sudoku solver create in a course NF04 at UTT


## **Objectifs :**
L’objectif du programme est de résoudre un sudoku.
On utilise une technique connue : le backtracking. Elle consiste à remplir la grille au fur et à mesure, en vérifiant constamment qu'elle reste toujours potentiellement valide, on arrive assez vite à des situations de blocage ou il ne sert à rien de continuer. Dans un tel cas, on reviendra en arrière et on ajoute 1, puis on répète le processus jusqu’à arriver à la dernière case.

## **Spécifications :**
L’utilisateur nous donne la grille de sudoku sous forme d’une matrice.
Le programme retourne la matrice totalement résolue ou une erreur si la grille n’est pas bonne.

## **Analyse :**
Pour ce programme nous avons besoin d’une matrice qui sera un tableau à deux dimensions pour stocker et résoudre le sudoku.
Au lancement du programme nous devrons avoir deux boucles for pour balayer en hauteur et en largeur la matrice pour permettre à l’utilisateur de remplir chaque case.
Ensuite le programme va chercher une case vide grâce à des conditions de type « if ». Lorsque qu’il trouve une case vide, dans une boucle while il va tester avec des chiffres de 1 à 9 de remplir la case et va vérifier que le chiffre ne case pas le programme grâce à des sous algorithmes. Si un des chiffres respecte les conditions le programme passe à la case vide d’après. La boucle while se finit lorsque l’on arrive à la fin de la grille ou que le programme est bloqué car il y a une erreur sur la grille.

## **Conclusion :**
Ce programme m’a permis de découvrir de nombreuse fonctionnalité du langages C.
J’ai rencontré des difficultés surtout lors de l’écriture de la grille par l’utilisateur surtout par rapport aux espaces en trop qui peuvent casser le programme. Il faut rentrer parfaitement la grille pour qu’elle soit résolu.
