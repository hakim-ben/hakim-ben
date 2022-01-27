#include <stdlib.h>
#include "abr.h"
#include "pile.h"

ppile_t creer_pile ()
{
  /*
    a completer
  */
  ppile_t p= malloc(sizeof(pile_t));
  p->sommet=-1;
  return p;
}

int detruire_pile (ppile_t p)
{
  /*
    a completer
  */
  if(p==NULL){return 0;}

  for (size_t i = 0; i < MAX_PILE_SIZE; i++) {
    p->Tab[i]=NULL;
  }
 free(p);
  return 1 ;
}

int pile_vide (ppile_t p)
{
  /*
     a completer
  */
if (p->sommet== -1){
return 1;
}
  return 0 ;
}

int pile_pleine (ppile_t p)
 {
  /*
     a completer
  */
  if (p->sommet== MAX_PILE_SIZE-1){
  return 1;
  }

  return 0 ;
}

pnoeud_t depiler (ppile_t p)
{
  /*
     a completer
  */
if(p->sommet ==-1){
   return NULL;
}else{
  pnoeud_t a= p->Tab[p->sommet];
  p->Tab[p->sommet]=NULL;
  p->sommet--;
  return a;
}
}

int empiler (ppile_t p, pnoeud_t pn)
  {

  /*
     a completer
  */

if(p->sommet <MAX_PILE_SIZE-1){
p->sommet++;
p->Tab[p->sommet]=pn;
  return 1 ;
}
return 0;
}
