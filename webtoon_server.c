/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "webtoon.h"

static struct compte tabCompte[10];
static struct serie tabSerie[10];

void *
init_1_svc(void *argp, struct svc_req *rqstp)
{
	static char * result;

	struct serie s1;
	strcpy(s1.titre, "Comment je suis devenu un hero alors que j'étais un looser");
	s1.noteMoyenne;
	strcpy(s1.listGenre[0].nomGenre,"Humour");strcpy(s1.listGenre[0].nomGenre,"Action");
	s1.dateSerie.jour=10; s1.dateSerie.mois=1; s1.dateSerie.annee=2020;
	strcpy(s1.listComm[0].comm,"Sympa"); strcpy(s1.listComm[0].pseudo,"Pseudo 1"); 
	strcpy(s1.listComm[1].comm,"Bof deja vu"); strcpy(s1.listComm[1].pseudo,"Pseudo 2"); 
	s1.nbrVue=10;
	s1.nbEpisode=3;
	strcpy(s1.description, "Une aventure incroyable dans un monde parellele apres avoir été renversé par un tricycle");

	return (void *) &result;
}

int *
inscription_1_svc(compte *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *
maj_info_1_svc(compte *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

listSerie *
afficher_serie_1_svc(argTri *argp, struct svc_req *rqstp)
{
	static listSerie  result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *
acheter_serie_1_svc(argAchaSerie *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *
ajouter_note_1_svc(argAjouterNote *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *
acheter_coin_1_svc(argAchaCoin *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *
afficher_coin_1_svc(compte *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

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
