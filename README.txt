           ************************************************
	    	Sokoban : le jeu du Gardien d'entrepôt
           ************************************************
           
Description du jeu:
  le joueur doit ranger des caisses sur des cases cibles. 
  Il peut se déplacer  dans les quatre directions, et pousser 
  (mais pas tirer) une seule caisse à la fois. Une fois toutes les caisses rangées 
  (c'est parfois un vrai casse-tête), le niveau est réussi.
  L'idéal est de réussir avec le moins de coups possibles.
  
 
Installation:
  Le jeu ne dépend que de la bibliothèque standard du C donc devrait pouvoir être installé sur toute
  machine disposant d’un compilateur C. En supposant que celui-ci est gcc, 
  l’installation se fait de la façon suivante :
  $ gcc sokoban_jeu.c -o sokoban_jeu
  Puis pour lancer le jeu, dans le répertoire contenant l’exécutable sokoban_jeu :
  $ ./sokoban_jeu


Comment jouer:
  Lancer le programme sokoban_jeu
  Le jeu vous propose de jouer vous  au super jeu du sokoban
  composer d'une grille.Le jeu se compose de 5 coups possibles: 
  avancer, reculer, allez à droite ou gauche et le coup perdu si
  le joueur est bloqué.
  
  
Organisation du code:
  Nous avons choisi d’utiliser quelques variables globales pour représenter l’état du jeu :
  — char grille[L][C]; qui est ma grille.
  — int tableau[2];  qui va servire a stocker la position du joueur 
  Notre choix d’utiliser des variables globales est motivé par les raisons suivantes :
  — Ces données sont manipulées par une grande partie des fonctions du programme.
  Ensuite le code est découpé en fonctions.
  — La fonction void jouer(); Cette fonction sert a déplacer le joueur sur la grille
  — La fonction void coup_possible(); Va nous servir à afficher toutes les touches possibles pour le joueur.
  — La fonction void position_joueur(int tableau[]);
  — La fonction void mouvement_joueur(int x,int y); Cette fonction sert a tester tous les coups possible et donner une réponse adapter
  — La fonction int victoire(); Vérifie si le joueur a bien respecter tout les condition pour gagner une partie
  — La fonction void match_perdu(); cette fonction sert a donner un coup de sortie si le joueur est bloquer ,en d'autre termes quitter le jeu
  Les autres fonctions servent à produire un affichage très sommaire du plateau de jeu.

  
  
Bugs et TODO :
  Le jeu dans sa version actuelle ne semble pas présenter de bug.
  Toutefois, faute de temps et/ou de
  connaissance, nous n’avons pas implémenté les choses suivantes :
  — L’interaction utilisateur (une touche puis entrée) n’est pas satisfaisant, 
  une simple touche serait plus pratique, mais nous ne savons pas encore comment
  faire avec nos connaissances actuelles.
  —Le manque de diversité par rapport au niveau,
  Avec le peu de temps faire plusieurs niveaux sokoban plus difficile.


Plaisir d'avoir codé ce jeu:
  Cela a été un grand plaisir pour moi de coder ce jeu de Sokoban.
  J'ai pu  développer mes compétences et découverts de nouvelle méthode de 
  résolution de problème.Par cela,j'ai bien aimé la parti de debugger le code
  même si celle-ci ma était complexe du a un problème de variable globale.
  Celui-ci découlait d'une mauvaise utilisation de ma grille et du tableau 
  qui sert a stocker les coordonner du joueur.





