/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "webtoon.h"

compte tabCompte[10];
static int nbCompte = 0;
serie tabSerie[10];
static int nbSerie = 0;
genre tabGenre[5];
static int nbGenre = 0;

void *
init_1_svc(void *argp, struct svc_req *rqstp)
{
	static char * result;

	// start init
	printf("+++ Start Server Init +++\n");

	struct serie s1;
	strcpy(s1.titre, "Le Hero");
	s1.listGenre[0]=0;s1.listGenre[1]=2;
	s1.dateSerie.jour=10; s1.dateSerie.mois=1; s1.dateSerie.annee=2020;
	s1.idSerie = 0;
	strcpy(s1.listComm[0].comm,"Sympa"); strcpy(s1.listComm[0].pseudo,"Le Narrateur"); 
	strcpy(s1.listComm[1].comm,"deja vu"); strcpy(s1.listComm[1].pseudo,"Malcaor"); 
	s1.nbrVue=10;
	s1.nbEpisode=3;
	s1.noteMoyenne=0;
	strcpy(s1.description, "Une ");

	struct serie s2;
	strcpy(s2.titre, "Locked");
	s2.listGenre[0]=0;s2.listGenre[1]=1;
	s2.dateSerie.jour=10; s2.dateSerie.mois=1; s2.dateSerie.annee=2020;
	s2.idSerie = 1;
	strcpy(s2.listComm[0].comm,"lol"); strcpy(s2.listComm[0].pseudo,"Le Narrateur"); 
	strcpy(s2.listComm[1].comm,"Je pleurais"); strcpy(s2.listComm[1].pseudo,"Malcaor"); 
	s2.nbrVue=10;
	s2.nbEpisode=3;
	s2.noteMoyenne=15;
	
	strcpy(s2.description, "A l'aide.\n");

	tabSerie[nbSerie] = s1;
	nbSerie++;
	tabSerie[nbSerie] = s2;
	nbSerie++;

	tabGenre[0].idGenre = 0;
	strcpy(tabGenre[0].nomGenre,"rire");
	tabGenre[1].idGenre = 1;
	strcpy(tabGenre[1].nomGenre,"peur");
	tabGenre[0].idGenre = 0;
	strcpy(tabGenre[0].nomGenre,"film");
	nbGenre=3;

	printf("+++ End Server Init +++\n\n");

	return (void *) &result;
}

int *
inscription_1_svc(compte *argp, struct svc_req *rqstp)
{
	printf("+++ Start Add User +++\n");
	static int  result;
	struct serie s[15];
	struct compte *c = (struct compte *) malloc(sizeof(struct compte));
	strcpy(c->pseudo, argp->pseudo);
	printf("- pseudo : %s\n", c->pseudo);
	strcpy(c->mdp,argp->mdp);
	printf("- mdp : %s\n", c->mdp);
	if(argp->carteBancaire>0){
		c->carteBancaire = argp->carteBancaire;
	}else{
		c->carteBancaire = 0;
	}
	printf("- carte bancaire : %i\n", c->carteBancaire);
	c->coin = argp->coin;
	c->nbSerieAchete=0;
	c->nbSerieFavorite=0;
	printf("- coin : %i\n", c->coin);

	
	
	tabCompte[nbCompte] = *c;
	if(&tabCompte[nbCompte] != NULL){result=1;nbCompte++;}else{result=0;}

	printf("+++ End Add User +++\n\n");
	
	return &result;
}

int *
maj_info_1_svc(compte *argp, struct svc_req *rqstp)
{
	printf("+++ Start Maj Info +++\n");
	static int  result = 0;

	for(int i=0;i<nbCompte;i++){
		if(strcmp(argp->pseudo,tabCompte[i].pseudo)==0){
			printf("- carte bancaire : %i => ", tabCompte[i].carteBancaire);
			tabCompte[i].carteBancaire = argp->carteBancaire;
			printf("%i\n", tabCompte[i].carteBancaire);
			printf("- mdp : %s => ", tabCompte[i].mdp);
			strcpy(tabCompte[i].mdp, argp->mdp);
			printf("%s\n", tabCompte[i].mdp);
			result = 1;
		}
	}

	printf("+++ End Maj Info +++\n\n");
	return &result;
}

listSerie *
afficher_serie_1_svc(argTri *argp, struct svc_req *rqstp)
{
	static listSerie  result;
	printf("test %s\n", argp->genreChoisi.nomGenre);
	printf("+++ Start Afficher Serie +++\n");
	
	for (size_t i = 0; i < nbSerie; i++){
		result.listSerie[i] = tabSerie[i];
	}

	result.nbSerie = nbSerie;
	
	printf("send %i serie\n", result.nbSerie);
	printf("--- test Result ---\n");
	for (size_t i = 0; i < result.nbSerie; i++){
		printf("- serie : %s\n", result.listSerie[i].titre);
	}
	

	printf("+++ End Afficher Serie +++\n\n");

	return &result;
}

int *
acheter_serie_1_svc(argAchaSerie *argp, struct svc_req *rqstp)
{
	static int  result;

	printf("+++ Start Acheter Serie +++\n");
	printf("compte a trouver : %s\n",argp->compteAcheteur.pseudo);

	for(int i=0;i<nbCompte;i++){
		if(strcmp(argp->compteAcheteur.pseudo,tabCompte[i].pseudo)==0){
			printf("Compte trouvé\n");
			if(tabCompte[i].coin>=50){
				int dejaAchete = 0;

				//on regarde si la serie est deja achté
				//1 on parcours la liste des serie deja acheté par le comte
				for(int serieAchete=0;serieAchete<tabCompte[i].nbSerieAchete;serieAchete++){
					//2 on parcours la liste de toutes le series
					for(int lesSeries=0;lesSeries<nbSerie;lesSeries++){
						//3 on compare les titres de la series qu'on regarde actuellement (tabSerie[lesSeries]) et la serie qu'on essai d'ajouter
						if(strcmp(argp->serieAchete.titre,tabSerie[lesSeries].titre)==0){
							//4 on regarde si la serie qu'on regarde actuellement (tabSerie[lesSeries]) est deja dans les series acheté ou non
							if(tabCompte[i].serieAchete[serieAchete]==tabSerie[lesSeries].idSerie){
								dejaAchete=1;
								printf("- serie deja acheté -\n");
							}
						}
					}
				}

				if(dejaAchete==0){
					for(int lesSeries=0;lesSeries<nbSerie;lesSeries++){
						if(strcmp(argp->serieAchete.titre,tabSerie[lesSeries].titre)==0){
							tabCompte[i].coin -= 50;
							result=1;
							tabCompte[i].serieAchete[tabCompte[i].nbSerieAchete] = tabSerie[lesSeries].idSerie;
							printf("- Transaction Effectué -\n");
							printf("- %s ajouté au compte du client -\n", tabSerie[lesSeries].titre);

						}
					}
				}
			}else{
				printf("- Acheteur trop pauvre -\n");
				// pas asser de coin
				result = 0;
			}

		}
	}

	printf("+++ End Acheter Serie +++\n\n");

	return &result;
}

int *
ajouter_note_1_svc(argAjouterNote *argp, struct svc_req *rqstp)
{
	printf("+++ Start Ajouter Note +++\n");
	printf("Serie a trouver : %s\n", argp->serieNote.titre);

	static int  result=0;

	for(int i=0;i<nbSerie;i++){
		if(strcmp(argp->serieNote.titre,tabSerie[i].titre)==0){
			printf("La serie a une note de : %f\n",tabSerie[i].noteMoyenne);
			if(tabSerie[i].noteMoyenne == 0){
				tabSerie[i].noteMoyenne = (double)argp->note;
			}else{
				tabSerie[i].noteMoyenne = (tabSerie[i].noteMoyenne+(double)argp->note)/2;
			}
			printf("La note de %d a été ajouté a la serie %s\n",argp->note,tabSerie[i].titre);
			printf("La serie a maintenant une note de : %f\n",tabSerie[i].noteMoyenne);
			result=1;
		}
	}

	printf("+++ End Ajouter Note +++\n\n");

	return &result;
}

int *
acheter_coin_1_svc(argAchaCoin *argp, struct svc_req *rqstp)
{
	static int  result;

	printf("+++ Start Acheter Coin +++\n");

	

	printf("pseudo a trouver : %s\n", argp->compteAcheteur.pseudo);

	for (size_t i = 0; i < nbCompte; i++)
	{
		if(strcmp(tabCompte[i].pseudo, argp->compteAcheteur.pseudo) == 0){
			// compte trouvé

			if(argp->nbCoin <=0){
				printf("- nb coin negatif -\n");
				// nb Coin negatif
				result = 0;
				printf("+++ End Acheter Coin +++\n\n");
				return &result;
			}else{
				if(tabCompte[i].carteBancaire <=0){
					printf("- pas de carte bancaire -\n");
					// pas de carte bancaire
					result = 0;
					printf("+++ End Acheter Coin +++\n\n");
					return &result;
				}else{
					tabCompte[i].coin += argp->nbCoin;
					printf("- Transaction Effectué -\n");
					printf("- %i coins ajouté au compte du client -\n", argp->nbCoin);

					printf("+++ End Acheter Coin +++\n\n");

					result = 1;

					return &result;
				}
			}

			

			
		}
	}
	

	printf("- aucun client trouvé-\n");
	printf("+++ End Acheter Coin +++\n\n");

	result = 0;

	return &result;
}

int *
afficher_coin_1_svc(compte *argp, struct svc_req *rqstp)
{
	static int  result;

	printf("+++ Start Afficher Coin +++\n");

	printf("pseudo a trouver : %s\n", argp->pseudo);

	for (size_t i = 0; i < nbCompte; i++)
	{
		if(strcmp(tabCompte[i].pseudo, argp->pseudo) == 0){
			printf("Pseudo trouvé avec %i coins\n", tabCompte[i].coin);

			result = tabCompte[i].coin;

			printf("+++ End Afficher Coin +++\n\n");
			return &result;
		}
	}

	result = -1;

	printf("+++ End Afficher Coin +++\n\n");

	return &result;
}

int *
ajouter_favoris_1_svc(argAchaSerie *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

listSerie *
afficher_favoris_1_svc(compte *argp, struct svc_req *rqstp)
{
	static listSerie  result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *
supprimer_favoris_1_svc(argAchaSerie *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *
ajouter_commentaire_1_svc(argAjoutComm *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *
supprimer_commentaire_1_svc(argAjoutComm *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}
