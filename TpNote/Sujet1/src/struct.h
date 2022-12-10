#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <string.h>


#define MAX_BUFFER_SIZE 100
#define M 7918
#define k 1456

// BONUS 

#define M2 6331
#define M3 1588
    
    
/*  Structure d'un logement  */ 
   
typedef struct Logement {
    float id;
    float accommodates;
    float bedrooms;
    float bathrooms;
    float beds;
    float price;
    float minimum_nights;
    float maximum_nights;
    float number_of_reviews;
    float distance[8]; // c'est la distance entre le logement x et lui-même
}logement;