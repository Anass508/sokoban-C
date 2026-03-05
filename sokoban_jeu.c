/* déclaration de fonctionnalités supplémentaires */
#include <stdio.h>
#include <stdlib.h>
/* declaration constantes et types utilisateurs */
#define L 6 
#define C 10
#define VRAI 1
#define FAUX 0


/* définitions des fonctions utilisateurs */
void bienvenue();
void grille_actualiser();
void coup_possible();
void position_joueur(int tableau[]);
void mouvement_joueur(int x,int y);
int victoire();
void match_perdu();
void jouer();


/*la grille doit etre défini en tant que variable globale sinon lorsque j'essayer dans le main il n'étais pas pris en compte*/
char grille[L][C]={
    "&&&&&&&&&&",  /*le symbole & représente les mur du donjon*/
    "&        &",  /*le symbole & représente les mur du donjon*/
    "&  $     &",
    "&   &&&&&&", 
    "& .    ! &", /*le symbole ! représente les mur du donjon*/
    "&&&&&&&&&&"
};

/*le tableau aussi doit etre défini en tant que variable globale sinon lorsque j'essayer dans le main il n'étais pas pris en compte */
int tableau[2];  /*va me servire a stocker la position du joueur  */

/*fonction principale : main */
int main(){     
    bienvenue();
    while(!victoire()){
      grille_actualiser();
      jouer();
    }
    
    grille_actualiser();
    printf("\n");
    printf("BRAVO vous avez rempli toutes les plaques de pression. \n");
    return EXIT_SUCCESS;     
}

/*déclarration des fonction */

/*fonction n°1 : Cette fonction sert de présentation du jeu au joueur. */
void bienvenue(){
  printf("______________________________________________________________________________________________________________\n");
  printf("BIENVENUE dans le jeu du sokoban ,\nUn donjon ou le but du jeu est de mettre le signe $ sur une plaque de pression nomme par le caractère .\n BONNE CHANCE \n");
  printf("______________________________________________________________________________________________________________\n\n");
}

/*fonction n°2 :Va nous servir à actualiser et à afficher notre grille en temps réel.*/
void grille_actualiser(){ /*Même principe que le programme tp3(exercice 3) avec le tracer de triangle */
  int i;
  int j;
  for(i=0;i<L;i++){ /*boucle parcourant les ligne de la grille*/
    for(j=0;j<C;j++){ /*boucle parcourant les colonnes de la grille*/
      printf("%c",grille[i][j]); 
    }
    printf("\n");
  }
}


/*fonction n°3: Va nous servir à afficher toutes les touches possibles pour le joueur.  */
void coup_possible(){
  printf("\nentrer p pour voter coup si vous etes bloquer\n");
  printf("Z=Haut\nQ=Gauche,\nD=Droite,\nS=Bas,\nP=perdu\n");
  printf("\n");
  printf("Quelle est votre coup ? :  ");
}

/*fonction n°4 : Cette fonction sert à stocker la position du joueur dans la grille pour être utiliser dans d'autres fonctions.*/
void position_joueur(int tableau[]){
  int i;
  int j;
  for(i=0; i<L; i++){
    for(j=0; j<C; j++){ /* parcouru la grille ,matrice */
      if(grille[i][j]=='!' || grille[i][j]=='+'){ /*ici ! représente le joueur et + le statue lorsqu'il est sur une plaque de pression*/
        tableau[0]=i;
        tableau[1]=j;
        return; 
      }
    }
  }
}


/*fonction n°5 : Cette fonction sert a tester tous les coups possible et donner une réponse adapter*/
void mouvement_joueur(int x,int y){
    position_joueur(tableau);  /*appelle la fonction pour savoir la position du joueur */
    int i=tableau[0];  /*initialiser i avec la position (x) du joueur  */
    int j=tableau[1];  /*initialiser j avec la position (y) du joueur  */
    int o=i+x;   /*position abscisse: une casse devant le joueur pour savoir si caisse,barrière,etc...*/
    int k=j+y;   /*position ordonnée: une casse devant le joueur pour savoir si caisse,barrière,etc...*/
    int w=i+x*2; /*position abscisse: 2 casse devant le joueur pour savoir si plaque de pression,barrière,etc...*/
    int z=j+y*2; /*position abscisse: 2 casse devant le joueur pour savoir si plaque de pression,barrière,etc...*/
    /* (*2) car si mouvement_joueur = (-1,0) v a donner (-2, 0) contrairement a +1 qui va neutraliser le -1 */
    
    if(grille[o][k]==' '){ /*Si la position 1 case devant le joueur est vide*/
      if(grille[i][j]=='+'){ /*si la position du joueur est est plaque de pression,pour le repérer */
        grille[i][j]='.'; /*pour signifier que le joueur est sur une plaque de pression */
      } 
      else{ 
        grille[i][j]=' '; /*si il n'est pas sur une plaque de pression */
      }
      if(grille[o][k]=='.'){
        grille[o][k]='+'; /*si la position du joueur est est plaque de pression alors */
      }  
      else{ 
        grille[o][k]='!'; /*si il n'est pas sur une plaque de pression  */
      }   
      
    }
    else if(grille[o][k]=='.'){ /*la position 1 case devant le joueur est une plaque de pression*/
      if(grille[i][j]=='+'){ /*si la position du joueur est est plaque de pression alors */
        grille[i][j]='.'; /*pour signifier que le joueur est sur une plaque de pression */
      } 
      else{ 
        grille[i][j]=' '; /*si il n'est pas sur une plaque de pression */
      }
      if(grille[o][k]=='.'){
        grille[o][k]='+'; /*si la position du joueur est est plaque de pression alors */
      }  
      else{ 
        grille[o][k]='!'; /*si il n'est pas sur une plaque de pression  */
      }   
    }
    /*pour les déplacement avec une caisse devants soit et condition de victoire*/
    else if((grille[o][k]=='$' || grille[o][k]=='*') && (grille[w][z]==' ' || grille[w][z]=='.')){
        if(grille[i][j]=='+'){
          grille[i][j]='.';
        } 
        else{
          grille[i][j]=' ';
        }
        if(grille[o][k]=='*') {
          grille[o][k]='+';
        } 
        else{
          grille[o][k]='!';
        }
        if(grille[w][z]=='.'){
          grille[w][z]='*';
        } 
        else{
          grille[w][z]='$';
        }
    }
}

/*fonction n°6 :Vérifie si le joueur a bien respecter tout les condition pour gagner une partie */
int victoire(){
  int i;
  int j;
  for(i=0;i < L;i++){
    for(j=0;j < C;j++){
      if(grille[i][j]=='.' || grille[i][j]=='+'){ /*rajout du + sinon le joueur peut gagner sans mettre la caisse sur la plaque de pression*/
       return FAUX;
      }
    }
  }
  return VRAI;
}

/*fonction n°7 : cette fonction sert a donner un coup de sortie si le joueur est bloquer ,en d'autre termes quitter le jeu*/
void match_perdu(){
  printf("Vous êtes bloquer dommage,relancer le jeu\n");
  exit(EXIT_SUCCESS); /*pour qu'il quitte le jeu comme demander en cas de défaite voulu du joueur */
}

/*fonction n°8 : Cette fonction sert a déplacer le joueur sur la grille*/
void jouer(){
    char choix;
    coup_possible();
    scanf(" %c", &choix);
    if(choix=='z'){
      mouvement_joueur(-1,0);
    }
    else if(choix=='q'){
      mouvement_joueur(0,-1);
    }
    else if(choix=='d'){
      mouvement_joueur(0,1);
    }
    else if(choix=='s'){
      mouvement_joueur(1,0);
    }
    else if(choix == 'p'){
      match_perdu();
    }
    else{
      printf("Votre coup n'existe pas veuillez réessayer \n");
    }
}


