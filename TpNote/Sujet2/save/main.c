

#include "fonction.h"

/*----------------------------------------EXERCICE 2---------------------------------------------*/


int main (void){
    // on définit nos processus manuellement ci-dessous
    process p1;
    p1.nom = "processus 1";
    p1.time = 3;
    p1.prio = 1;

    process p2;
    p2.nom = "processus 2";
    p2.time = 3;
    p2.prio = 2;

    process p3;
    p3.nom = "processus 3";
    p3.time = 2;
    p3.prio = 1;

    process p4;
    p4.nom = "processus 4";
    p4.time = 2;
    p4.prio = 0;
    
    process p5;
    p5.nom = "processus 5";
    p5.time = 1;
    p5.prio = 0;
    
    process tab[5] = {p1, p2, p3, p4, p5};
    int taille = 5;
    // on ordonne les processus suivant leur ordre de priorité
    triTableau(tab, taille);
    f file = NULL;
    
    // on définit manuellement notre file de processus
    ordo ordinateur = NULL;
    ordinateur = creerOrdonnanceur(tab[0], NULL);
    file = creerFichier(ordinateur, ordinateur); // on creer notre file qui contient avec une tête égale à sa queue (car un seul élément)

    file->tete->suiv = creerOrdonnanceur(tab[1], NULL);
    file->queue->suiv = creerOrdonnanceur(tab[1], NULL);
    file->queue = file->queue->suiv;
    
    file->queue->suiv = creerOrdonnanceur(tab[2], NULL);
    file->queue = file->queue->suiv;

    file->queue->suiv = creerOrdonnanceur(tab[3], NULL);
    file->queue = file->queue->suiv;

    file->queue->suiv = creerOrdonnanceur(tab[4], NULL);

	run(file->tete);
}
