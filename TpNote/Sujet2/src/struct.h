#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

#define MALLOC(x)((x * ) malloc(sizeof(x))) // permet d'utiliser la fonction malloc

// Création de la structure processus qui contient un nom, un temps d'exécution et un ordre de priorité
typedef struct Processus{
    char* nom;
    int time;
    int prio;
} process;

// Création du type ordonnanceur qui contient un process et un pointeur sur l'ordonnanceur suivant
typedef struct ordinateur{
    process p;
    struct ordinateur* suiv;
} ordonnanceur;
typedef ordonnanceur * ordo; // permet d'appeler plus facilement les pointeurs sur ordonnanceur

// Création d'une file d'ordonnanceur qui contient la tête et la queue de cette même file.
typedef struct File{
    ordo tete; 
    ordo queue;
} file;
typedef file * f; // permet d'appeler plus facilement les pointeurs sur file / renommer file* en f