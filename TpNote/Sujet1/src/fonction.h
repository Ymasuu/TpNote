#include "struct.h"

    /*  APPEL DE FONCTION   */

void recup_donnee(logement*);
logement calcul_distance(logement, logement);
void randomiserTab(logement*, int);
void echanger(logement* ,logement*);
void triTableau(logement*, int, int );
float moyenne(logement*);

    /*  APPEL FONCTION DE LA PARTIE BONUS  */

void recupBonus_Entrainement(logement*);
void recupBonus_Test(logement*);
void prediction(logement*, logement*, float*);
float MAE(logement*, float*);
