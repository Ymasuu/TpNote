        README


Dans notre projet, le sujet 1 contient un Makefile, un ReadMe et 4 répertoires.
Ces 4 répertoires : /bin ; /src ; /save ; /doc

    Informations utiles :

				LANCEMENT PROGRAMME
Pour lancer notre programme, 
Il faut tout d'abord le compiler à l'aide de la commande make all 
Puis pour le lancer on utilise make prog. 
Si on veut recommencer il faut commencer par supprimer les fichiers .o et l'éxecutable prog avec make clean 
Relancer avec les deux commandes vus précédemment. 
De plus, si on ne connait pas les commandes on peut utiliser make help
On aura alors toutes les commandes possibles pour nous aider

				CHANGEMENT DE DONNEES
Si l'on veut modifier les valeurs du logement x : fichier main.c 
Si l'on veut modifier les critères de la distance : fichier fonction.c et fonction "calcul_distance"
Si l'on veut modifier les k premiers logements : fichier struct.h et valeur k.
	PARTIE MAKEFILE :

Ensemble des commandes permettant de compiler, lancer, nettoyer notre programme

        DANS LE REPERTOIRE SRC
    On a 4 fichiers : struct.h / fonction.h / fonction.c / main.c

	PARTIE struct.h :

Dans ce fichier, il y a toute les structures de notre code
Mais aussi toute les librairies et ce qu'on définit 

	PARTIE fonction.h

Ici, on appelle les fonctions présentes dans le fichier fonction.c

	PARTIE fonction.c

On y retrouve l'intégralité de nos fonctions utiles pour la bonne réalisation du projet
Premièrement, on retrouve la procédure suivante :
    void recup_donnee(logement* tab)
Qui permet de récupérer les valeurs présentes dans le fichier csv. 
Pour ce faire, on doit ouvrir le fichier csv 
Ensuite, on lit ligne par ligne le fichier afin de récuperer les valeurs avec un fscanf dans un tableau de logement
Puis on ferme le fichier

Seconde fonction :
	logement calcul_distance(logement x, logement y)
Permet de calculer la distance entre notre logement x et les logements du fichier csv
On crée un réel qui stock la valeur distance que l'on calcul en faisant le carré de la valeur du logement x - celle du logement y (donnée du fichier csv) et qu'on incremente avec les autres carrés des autres valeurs 
Ensuite on fait la racine de la variable dist.
On stock également l'intégralité des valeurs dans les tableaux de notre structure afin de les récupérer plus facilement.

Fonction suivante :
    void randomiserTab(logement* tab, int taille)
Permet de randomiser l'intégralité de notre tableau logement

Fonction suivante :
    void echanger(logement *a, logement *b)
Permet de permuter les valeurs

Fonction suivante :
	void triTableau(logement* tab, int debut, int fin) 
Permet de trier notre tableau de façon après l'avoir randomiser. 
Ici on utilise la méthode d'un tri rapide (quick sort) afin d'améliorer la rapidité de notre programme.
On appelle la fonction "echanger" dedans.


Fonction suivante :
    float moyenne(logement* tab)
Cette fonction calcul simplement la moyenne du prix afin d'avoir le prix prédit par notre algorithme

PARTIE BONUS :

Par la suite on trouvera les fonctions qui permettent de réaliser la partie bonus du tp

Ces deux fonctions :
	void recupBonus_Entrainement(logement* tab)
	void recupBonus_Test(logement* tab)
sont identiques à celle "recup_donnee" présente dans la première partie du tp.
Possède exactement les mêmes caractéristiques.
Cependant, on agit ici sur les csv Entrainement et Test.

La fonction :
	void prediction(logement* tabEntrainement, logement* tabTest, float* tabPrediction)
Ici on prédit le prix des logements présent dans le fihcier csv Entrainement.
De ce fait, on calcul la distance.
Puis même méthode, on randomise et tri le tableau avant de récupérer les valeurs.
Et calcul de la moyenne.

La fonction :
	float MAE(logement* tabTest, float* tabPrediction)
qui permet de calculer le MAE avec la formule à l'aide de toutes les valeurs du prix prédit et du prix réel.


		PARTIE main.c
On initialise dans notre main le logement x.
Puis on fait l'appelle de nos fonctions dans l'ordre pour que notre programme fonctionne.
Et certain printf afin de visualiser les résultats obtenus après avoir lancer notre programme.

Pour plus d'informations précises sur les fonctions, il y a des commentaires dans le code.
Afin de mieux aider à la compréhension

        DANS LE REPERTOIRE BIN

On y retrouve les fichiers .o et l'exécutable que l'on crée lors de l'utilisation du Makefile et que l'on supprimer plus tard.

        DANS LE FICHIER DOC

Présence des 3 fichiers csv utile à la récupération des données.

        DANS LE FICHIER SAVE

Ici où l'on stock les fichiers si jamais on veut faire une backup ou si perte des fonctions.