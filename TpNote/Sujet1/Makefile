CC = gcc -Wall
RM = rm -f $(OBJ) $(PROG)
HELP = echo "make all : pour compiler \nmake clean : pour supprimer les fichiers créer (les .o et l'exécutable) \nmake prog : sert à exécuter le fichier exécutable (./bin/prog) \nmake save : permet de sauvegarder les fichiers de ./src dans le répertoire ./save \nmake restore : permet de remplacer les fichiers de ./src par ceux de ./save"
#Cherche tous les .c dans le repertoire correspondant
SRC = $(wildcard $(srcdir)*.c)
HEAD = $(wildcard $(srcdir)*.h)
#Utilisation : $(subst from,to,text), permet de remplacer
OBJ = $(subst $(srcdir),$(bindir),$(SRC:.c=.o))
PROG = ./bin/prog
#Les 4 prochaines lignes permettent de simplifier la lisibilité des commandes en dessous
srcdir = ./src/
bindir = ./bin/
savedir = ./save/

CP = cp $(SRC) $(HEAD) $(savedir)

#copie les fichiers du dossier save dans le repertoire source
RT = cp $(savedir)* $(srcdir)
all : $(PROG)

#on cherche tous les .o qui doivent dependre des .c
$(bindir)%.o : $(srcdir)%.c 
	$(CC) -c $< -o $@


$(PROG) : $(OBJ) #notre programme depend de tous les .o 
	$(CC) $^ -o $@ -lm
.PHONY : clean  #permet d'exécuter la commande 'clean' meme si un fichier existe
clean : 
	$(RM) 
.PHONY : save  #permet d'exécuter la commande 'save' meme si un fichier existe
save :
	$(CP)
restore :
	$(RT)
.PHONY : prog #permet d'exécuter la commande 'prog' meme si un fichier existe
prog : # le '@' empeche l'affichage de la commande sur le terminaleù
	@$(PROG)

help :
	@$(HELP)
