#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "abr.h"
#include "pile.h" 
  int nberreur=0;
void ensure(int test, char *msg)
{
  if (test != 0)
  {
    return;
  }
  nberreur++;
  printf("%s\n", msg);
}
int main (int argc, char**argv)
{
  Arbre_t a ;

  if (argc != 2)
    {
      fprintf (stderr, "il manque le parametre nom de fichier\n") ;
      exit (-1) ;
    }

  a = lire_arbre (argv[1]) ;
  
  afficher_arbre (a,0) ;

  /*
     appeler les fonctions que vous
     avez implementees
  */ 
  printf("tests pile\n");
  ppile_t pile = creer_pile();

  ensure(!pile_pleine(pile), "la pile ne devrait pas etre pleine");
  ensure(pile_vide(pile), "la pile devrait etre vide");

  //on teste si on peut remplir la pile au max
  for (int i = 0; i < MAX_PILE_SIZE; i++)
  {
    pnoeud_t pneu = malloc(sizeof(noeud_t));
    pneu->cle = i;
    ensure(empiler(pile, pneu), "ça n'empile pas");
  }
  /*
  on a rempli la pile au max
  on teste si elle est considérée comme pleine
  */
  ensure(pile_pleine(pile), "la pile devrait etre pleine");

  //on regarde si on peut encore la remplir
  pnoeud_t pneu = malloc(sizeof(noeud_t));
  ensure(!empiler(pile, pneu), "ça empile trop");

  for (int i = 0; i < MAX_PILE_SIZE; i++)
  {
    ensure(depiler(pile)->cle == MAX_PILE_SIZE - i - 1, "ça ne depile pas ce qu'il faut ou pas assez");
  }
  ensure(depiler(pile) == NULL, "ça ne devrait pas depiler");
  ensure(pile_vide(pile), "la pile devrait etre vide");

  ensure(detruire_pile(pile), "devrait reussir à detruire la pile");
  if (nberreur==0){ 
 printf("tout les tests on reussi\n");
  }
}
