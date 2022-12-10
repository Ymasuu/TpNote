README


Dans notre projet, le sujet 2 contient un Makefile, un ReadMe et 3 répertoires.
Ces 3 répertoires : /bin ; /src ; /save

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
Si l'on veut modifier les valeurs des processus : fichier main.c

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

La fonction suivante :
	ordo creerOrdonnanceur(process process_p, ordo suivant)
Qui permet de créer un ordonnanceur en lui affectant un processus


La fonction : 
	f creerFichier(ordo f1, ordo f2)
Qui premet de créer un file en lui affectant un ordonanceur

Cette fonction : 
	void triTableau(process* tab, int taille)
Sert à trier le tableau de processus en fonction de son ordre de priorité


La fonction : 
void step(ordo ordinateur)
qui exécute le processus d'un ordonnanceur à condition qu'il existe

La fonction : 
void run(ordo File)
Qui permet d'exécuter la fonction step pour une file entière à condition qu'elle soit pas vide */

		PARTIE main.c

On initialise dans notre main plusieurs processus avec leur nom, le temps d'execution et leur priorité.
Puis on fait les opérations sur la file afin d'obtenir les résultats après avoir lancer notre programme.

Pour plus d'informations précises sur les fonctions, il y a des commentaires dans le code.
Afin de mieux aider à la compréhension

        DANS LE REPERTOIRE BIN

On y retrouve les fichiers .o et l'exécutable que l'on crée lors de l'utilisation du Makefile et que l'on supprimer plus tard.

        DANS LE FICHIER SAVE

Ici où l'on stock les fichiers si jamais on veut faire une backup ou si perte des fonctions.