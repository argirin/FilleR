# FilleR

Filler est un jeu algorithmique qui consiste à remplir une grille d’une taille connue
à l’avance avec des pièces de taille et de formes aléatoires, sans que les pièces ne se superposent
de plus d’une seule case et sans qu’elles ne depassent de la grille. Si l’une de
ces conditions n’est pas remplie, la partie s’arrête.
Chaque pièce posée avec succès rapporte un certain nombre de points, et a un seul
joueur, le but du jeu pourrait être d’obtenir le meilleur score possible. Cepedant, c’est
avec deux joueurs que le filler prend tout son intérêt. Chaque joueur a pour but de poser
un maximum de pièces tout en tentant d’empêcher son adversaire de le faire. A la fin de
la partie, celui avec le plus de point remporte le match...

Sujet complet : https://github.com/argirin/FilleR/blob/master/filler.fr.pdf

# Usage

Compiler le projet avec la commande "make".

Utiliser l'executable "./filler_vm" fourni dans le dossier ressources.

Executer ./filler_vm -p1 "[chemin de votre joueur 1.filler]" -p2 "[chemin de votre joueur 2.filler] -f "[chemin de votre map]"

Exemple : ./filler_vm -p1 players/abanlin.filler -p2 players/carli.filler -f maps/map01
