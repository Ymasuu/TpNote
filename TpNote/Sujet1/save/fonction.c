#include "fonction.h"

/*  Fonction qui permet d'apporter chaque valeur du fichier csv à un élément de la structure    */

void recup_donnee(logement* tab){
    
    /*  OUVERTURE D'UN FICHIER CSV  */

    FILE *fichier;
    fichier = fopen ("./doc/airbnb_donnees_propre.csv", "r");
    if (!fichier) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    

    /*  Lecture du fichier csv ligne par ligne + récupération de valeurs  */

    char str[MAX_BUFFER_SIZE];
    int i = 0;
    while (fgets(str, MAX_BUFFER_SIZE, fichier) != NULL){
        fscanf(fichier, "%f,%f,%f,%f,%f,%f,%f,%f,%f", &tab[i].id, &tab[i].accommodates, &tab[i].bedrooms, &tab[i].bathrooms, &tab[i].beds, &tab[i].price, &tab[i].minimum_nights, &tab[i].maximum_nights, &tab[i].number_of_reviews);
        i +=1;
    }

    fclose(fichier);
   
}

logement calcul_distance(logement x, logement y){
    float dist = 0;
    // on affecte dist en fonction des données que l'on veut (ici accommodates, bedrooms et beds)
    dist += pow((x.accommodates - y.accommodates),2);
    dist += pow((x.bedrooms - y.bedrooms), 2);
    //dist += pow((x.bathrooms - y.bathrooms),2);
    dist += pow((x.beds - y.beds), 2);
    //dist += pow((x.minimum_nights - y.minimum_nights), 2);
    //dist += pow((x.maximum_nights - y.maximum_nights),2);
    //dist += pow((x.number_of_reviews - y.number_of_reviews),2);
    dist = sqrt(dist);
    // les 6 lignes ci-dessous représentent la somme des différentes caractéristiques
    y.distance[0] = sqrt(pow((x.accommodates - y.accommodates),2));
    y.distance[1] = sqrt(pow((x.bedrooms - y.bedrooms), 2));
    y.distance[2] = sqrt(pow((x.bathrooms - y.bathrooms),2));
    y.distance[3] = sqrt(pow((x.beds - y.beds),2));
    y.distance[4] = sqrt(pow((x.minimum_nights - y.minimum_nights),2));
    y.distance[5] = sqrt(pow((x.maximum_nights - y.maximum_nights),2));
    y.distance[6] = sqrt(pow((x.number_of_reviews - y.number_of_reviews),2));
    y.distance[7] = dist;
    return y;
}

// permet d'échanger aléatoirement les éléments du tableau 
void randomiserTab(logement* tab, int taille){
    logement tmp;
    srand(time(NULL));
    for(int i = 0; i < taille; i++){
        int j = rand()%taille; // formule nombreAlea = (rand() % (MAX - MIN + 1)) + MIN;
        tmp = tab[j];
        tab[j] = tab[i]; 
        tab[i] = tmp;
    }
}

/*void triTableau(logement* tab, int taille){
	logement tmp;
    for(int i = 0; i < taille; i++){
        for(int j = 0; j < taille-1; j++){
            if(tab[j].distance[7] > tab[j+1].distance[7]){
                tmp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = tmp;
            }
        }
    }
}*/

// permute l'adresse de 2 logement grâce à une variable temporaire
void echanger(logement *a, logement *b) {
    logement tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

// fonction qui exécute un tri rapide d'un tableau de logement
void triTableau(logement* tab, int debut, int fin) {
    int pivot, i, j;
    if(debut < fin) {
        pivot = debut;
        i = debut;
        j = fin;
        while (i < j) {
            while(tab[i].distance[7] <= tab[pivot].distance[7] && i < fin)
                i++;
            while(tab[j].distance[7] > tab[pivot].distance[7])
                j--;
            if(i < j) {
                echanger(&tab[i], &tab[j]);
            }
        }
        echanger(&tab[pivot], &tab[j]);
        triTableau(tab, debut, j - 1);
        triTableau(tab, j + 1, fin);
    }
}



// calcule la moyenne des prix en fonction des k premiers logements du tableau
float moyenne(logement* tab){
    int prix = 0;
    for(int i = 0; i < k; i++){
        prix += tab[i].price;
    }
    return prix/k;
}

    /*  FONCTION PARTIE BONUS  */

// même principe que recup_donnee mais pour le fichier Entrainement.csv
void recupBonus_Entrainement(logement* tab){
     
    FILE *fichier2;
    fichier2 = fopen ("./doc/airbnbEntrainement.csv", "r");
    if (!fichier2) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    char str2[MAX_BUFFER_SIZE];
    int i = 0;
    while (fgets(str2, MAX_BUFFER_SIZE, fichier2) != NULL){
        fscanf(fichier2, "%f,%f,%f,%f,%f,%f,%f,%f,%f", &tab[i].id, &tab[i].accommodates, &tab[i].bedrooms, &tab[i].bathrooms, &tab[i].beds, &tab[i].minimum_nights, &tab[i].maximum_nights, &tab[i].number_of_reviews,&tab[i].price);
        i +=1;
    }

    fclose(fichier2);
}

// même principe que recup_donnee mais pour le fichier Test.csv
void recupBonus_Test(logement* tab){
     
    FILE *fichier3;
    fichier3 = fopen ("./doc/airbnbTest.csv", "r");
    if (!fichier3) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    char str3[MAX_BUFFER_SIZE];
    int i = 0;
    while (fgets(str3, MAX_BUFFER_SIZE, fichier3) != NULL){
        fscanf(fichier3, "%f,%f,%f,%f,%f,%f,%f,%f,%f", &tab[i].id, &tab[i].accommodates, &tab[i].bedrooms, &tab[i].bathrooms, &tab[i].beds, &tab[i].minimum_nights, &tab[i].maximum_nights, &tab[i].number_of_reviews, &tab[i].price);
        i +=1;
    }

    fclose(fichier3);
}


// on va prédire le prix de chaque logemient de tabTest
void prediction(logement* tabEntrainement, logement* tabTest, float* tabPrediction){
    for (int i = 0; i < M3; i++){
        for(int j = 0; j < M2; j++){
            tabEntrainement[j] = calcul_distance(tabTest[i], tabEntrainement[j]);
        } // segmentation fault
        randomiserTab(tabEntrainement, M2);
        triTableau(tabEntrainement, 0, M2-1);
        tabPrediction[i] = moyenne(tabEntrainement);
    }
}

// calcule le MAE en fonction du prix reel des logements de tabTest et du prix prédit de ces mêmes logements
float MAE(logement* tabTest, float* tabPrediction){
    float mae;
    for(int i = 0; i < M3; i++){
        mae += abs(tabTest[i].price - tabPrediction[i]);
    }
    return mae/M3;
}