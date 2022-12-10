#include "fonction.h"

int main(void){

    /*   Initialisation du logement x   */

    logement x;
    x.id = 9999;
    x.accommodates = 5;
    x.bedrooms = 3;
    x.bathrooms = 1;
    x.beds = 5;
    x.minimum_nights = 2;
    x.maximum_nights= 780;
    x.number_of_reviews = 14;

    logement tab[M];
    recup_donnee(tab);
    for(int i = 0; i < M; i++){
        tab[i] = calcul_distance(x, tab[i]);
    }
    printf("EXEMPLES DE DONNEES AVANT TRI : \nTAB[1000] ID : %f --> Distance : %f\n", tab[1000].id, tab[1000].distance[7]);
    printf("TAB[7900] ID : %f --> Distance : %f\n\n", tab[7900].id, tab[7900].distance[7]);
    randomiserTab(tab, M);
    triTableau(tab,0, M-1);
    printf("EXEMPLES DE DONNEES APRES TRI : \nTAB[1000] ID : %f --> Distance : %f\n", tab[1000].id, tab[1000].distance[7]);
    printf("TAB[7900] ID : %f --> Distance : %f\n\n", tab[7900].id, tab[7900].distance[7]);
    x.price = moyenne(tab);
    printf("Logement x : \nID : %f --> Prix prédi : %f\n", x.id, x.price);

    // PARTIE BONUS 
    
    logement tabEntrainement[M2];
    recupBonus_Entrainement(tabEntrainement);
    logement tabTest[M3];
    recupBonus_Test(tabTest);
    float tabPrediction[M3];
    prediction(tabEntrainement, tabTest, tabPrediction);
    /* Si on veut voir les valeur 
    puts("\ntabPrediction : ");
    for(int i = 0; i < M3; i++){
        printf(" %f", tabPrediction[i]);
    }*/
    float mae = MAE(tabTest, tabPrediction);
    printf("\nCalcul de MAE pour k = %d : \nMAE = %f\n", k, mae);
}

