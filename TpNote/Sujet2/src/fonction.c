#include "fonction.h"


// fonction qui premet de créer un ordonnanceur en lui affectant un processus
ordo creerOrdonnanceur(process process_p, ordo suivant){
	ordo activite = NULL;
	if ((activite = (ordo)malloc(sizeof(ordonnanceur)))== NULL) {
		fprintf(stderr, "ERREUR ALLOCATION MEMOIRE");
		exit(1);
	}
	activite->p = process_p;
	activite->suiv = suivant;
	return activite;
}

// fonction qui premet de créer un file en lui affectant un ordonanceur
f creerFichier(ordo f1, ordo f2){
	f fichier = NULL;
	if ((fichier = (f)malloc(sizeof(file)))== NULL) {
		fprintf(stderr, "ERREUR ALLOCATION MEMOIRE");
		exit(1);
	}
	fichier->tete = f1;
	fichier->queue = f2;
	return fichier;
}

/* cette fonction sert à trier le tableau de processus en fonction de 
son ordre de priorité*/
void triTableau(process* tab, int taille){
	process tmp;
    for(int i = 0; i < taille; i++){
        for(int j = 0; j < taille-1; j++){
            if(tab[j].prio > tab[j+1].prio){
                tmp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = tmp;
            }
            else { // si les ordres de priorité sont le même, on trie en fonction du temps d'exécution
                if(tab[j].prio == tab[j+1].prio && tab[j].time > tab[j+1].time){
					tmp = tab[j];
					tab[j] = tab[j+1];
					tab[j+1] = tmp;
                }
            }
        }
    }
}


// fonction qui exécute le processus d'un ordonnanceur à condition qu'il existe
void step(ordo ordinateur){
	if(ordinateur == NULL){
		puts("la file est vide, on ne fait rien");
	}else {
		printf("on execute %s pendant %d seconde(s).\n", ordinateur->p.nom, ordinateur->p.time);
		sleep(ordinateur->p.time);	
	}
}

/* fonction qui permet d'exécuter la fonction step pour une file entière à condition qu'elle soit pas vide */
void run(ordo File){
	if(File == NULL){
		printf("la file est vide, on ne faite rien");
	}else {
		while(File != NULL){
			step(File);
			File = File->suiv;
		}
		printf("Tout à été exécuté.\n");
	}
}

