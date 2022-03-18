/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "webtoon.h"


void
webtoon_prog_1(char *host)
{
	CLIENT *clnt;
	void  *result_init;
	char *init_1_arg;
	int  *result_inscription;
	compte  inscription_1_arg;
	int  *result_maj_info;
	compte  maj_info_1_arg;
	listSerie  *result_afficher_serie;
	argTri  afficher_serie_1_arg;
	int  *result_acheter_serie;
	argAchaSerie  acheter_serie_1_arg;
	int  *result_ajouter_note;
	argAjouterNote  ajouter_note_1_arg;
	int  *result_acheter_coin;
	argAchaCoin  acheter_coin_1_arg;
	int  *result_afficher_coin;
	compte  afficher_coin_1_arg;
	int  *result_ajouter_favoris;
	argAchaSerie  ajouter_favoris_1_arg;
	listSerie  *result_afficher_favoris;
	compte  afficher_favoris_1_arg;
	int  *result_supprimer_favoris;
	argAchaSerie  supprimer_favoris_1_arg;
	int  *result_ajouter_commentaire;
	argAjoutComm  ajouter_commentaire_1_arg;
	int  *result_supprimer_commentaire;
	argAjoutComm  supprimer_commentaire_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, WEBTOON_PROG, WEBTOON_VERSION_1, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	printf("--------------------1--------------------\n\n");

	result_init = init_1((void*)&init_1_arg, clnt);
	printf("+++ Start Server Init +++\n");
	if (result_init == (void *) NULL) {
		clnt_perror (clnt, "Init call failed");
	} else {
		printf("Initialisation termine\n");
	}
	printf("+++ End Server Init +++\n\n");
	
	printf("--------------------2--------------------\n\n");

	strcpy(inscription_1_arg.pseudo,"Le Narrateur");
	strcpy(inscription_1_arg.mdp,"1234");
	inscription_1_arg.carteBancaire=0;
	inscription_1_arg.coin=0;
	result_inscription = inscription_1(&inscription_1_arg, clnt);
	printf("+++ Start Add User +++\n");
	if (result_inscription == (int *) NULL) {
		clnt_perror (clnt, "Inscription call failed");
	} else {
		if (*result_inscription == 0){
			// echec
			printf("Inscription echec\n");
		}else{
			//echec
			printf("Inscription reussie\n");
		}
	}
	printf("+++ End Add User +++\n\n");


	printf("--------------------3--------------------\n\n");


	// update mdp with abcd
	maj_info_1_arg = inscription_1_arg;
	strcpy(maj_info_1_arg.mdp,"abcd");
	printf("+++ Start Maj Info +++\n");
	result_maj_info = maj_info_1(&maj_info_1_arg, clnt);
	if (result_maj_info == (int *) NULL) {
		clnt_perror (clnt, "Maj Info call failed");
	} else {
		if (*result_maj_info == 0){
			// echec
			printf("maj_info_1 echec\n");
		}else{
			//echec
			printf("maj_info_1 reussi\n");
		}
	}
	printf("+++ End Maj Info +++\n\n");
	

	printf("--------------------4--------------------\n\n");


	printf("+++ Start Afficher Series +++\n");
	strcpy(afficher_serie_1_arg.genreChoisi.nomGenre, "peur");
	*afficher_serie_1_arg.genreChoisi.nomGenre = 1;
	result_afficher_serie = afficher_serie_1(&afficher_serie_1_arg, clnt);
	if (result_afficher_serie == (listSerie *) NULL) {
		clnt_perror (clnt, "Afficher Serie call failed");
	}else{
		if(result_afficher_serie != NULL){
			printf("Les Series : %s\n", afficher_serie_1_arg.genreChoisi.nomGenre);
			for(int i=0; i<result_afficher_serie->nbSerie; i++){
				printf("%s\n",result_afficher_serie->listSerie[i].titre);
			}
		}
	}
	printf("+++ End Afficher Series +++\n\n");
	

	printf("--------------------5--------------------\n\n");


	printf("+++ Start Acheter Series +++\n");
	strcpy(acheter_serie_1_arg.serieAchete.titre,"Locked");
	strcpy(acheter_serie_1_arg.compteAcheteur.pseudo,"Le Narrateur");
	result_acheter_serie = acheter_serie_1(&acheter_serie_1_arg, clnt);
	if (result_acheter_serie == (int *) NULL) {
		clnt_perror (clnt, "Acheter Serie call failed");
	} else {
		if (*result_acheter_serie == 0){
			// echec
			printf("acheter_serie_1 echec\n");
		}else{
			//echec
			printf("acheter_serie_1 reussi\n");
		}
	}
	printf("+++ End Acheter Series +++\n\n");


	printf("--------------------6--------------------\n\n");


	printf("+++ Start Acheter Coin +++\n");
	strcpy(acheter_coin_1_arg.compteAcheteur.pseudo,"Le Narrateur");
	acheter_coin_1_arg.nbCoin = 100;
	result_acheter_coin = acheter_coin_1(&acheter_coin_1_arg, clnt);
	if (result_acheter_coin == (int *) NULL) {
		clnt_perror (clnt, "Acheter Coin call failed");
	} else {
		if (*result_acheter_coin == 0){
			// echec
			printf("acheter_coin_1 echec\n");
		}else{
			//echec
			printf("acheter_coin_1 reussi\n");
		}
	}
	printf("+++ End Acheter Coin +++\n\n");


	printf("--------------------7--------------------\n\n");


	printf("+++ Start Maj Info +++\n");
	maj_info_1_arg.carteBancaire = 123412341;
	result_maj_info = maj_info_1(&maj_info_1_arg, clnt);
	if (result_maj_info == (int *) NULL) {
		clnt_perror (clnt, "Maj Info call failed");
	}else{
		if (*result_maj_info == 0){
			// echec
			printf("maj_info_1 echec\n");
		}else{
			//echec
			printf("maj_info_1 reussi\n");
		}
	}
	printf("+++ End Maj Info +++\n\n");


	printf("--------------------8--------------------\n\n");


	printf("+++ Start Acheter Coin +++\n");
	// acheter_coin_1_arg est deja remplie au premier appel
	result_acheter_coin = acheter_coin_1(&acheter_coin_1_arg, clnt);
	if (result_acheter_coin == (int *) NULL) {
		clnt_perror (clnt, "Acheter Coin call failed");
	} else {
		if (*result_acheter_coin == 0){
			// echec
			printf("acheter_coin_1 echec\n");
		}else{
			//ok
			printf("acheter_coin_1 reussi\n");
			printf("Vous avez acheté %d coins\n",acheter_coin_1_arg.nbCoin);
		}
	}
	printf("+++ End Acheter Coin +++\n\n");


	printf("--------------------9--------------------\n\n");


	printf("+++ Start Afficher Coin +++\n");
	strcpy(afficher_coin_1_arg.pseudo,"Le Narrateur");
	result_afficher_coin = afficher_coin_1(&afficher_coin_1_arg, clnt);
	if (result_afficher_coin == (int *) NULL) {
		clnt_perror (clnt, "Afficher Coincall failed");
	}else{
		printf("Vous avez : %d coin(s) \n",*result_afficher_coin);
	}
	printf("+++ End Afficher Coin +++\n\n");

	
	printf("--------------------10--------------------\n\n");


	printf("+++ Start Acheter Series +++\n");
	result_acheter_serie = acheter_serie_1(&acheter_serie_1_arg, clnt);
	if (result_acheter_serie == (int *) NULL) {
		clnt_perror (clnt, "Acheter Serie call failed");
	} else {
		if (*result_acheter_serie == 0){
			// echec
			printf("acheter_serie_1 echec\n");
		}else{
			//echec
			printf("acheter_serie_1 reussi\n");
		}
	}
	printf("+++ End Acheter Series +++\n\n");


	printf("--------------------11--------------------\n\n");


	printf("+++ Start Afficher Coin +++\n");
	result_afficher_coin = afficher_coin_1(&afficher_coin_1_arg, clnt);
	if (result_afficher_coin == (int *) NULL) {
		clnt_perror (clnt, "Afficher Coincall failed");
	}else{
		printf("Vous avez : %d coin(s) \n",*result_afficher_coin);
	}
	printf("+++ End Afficher Coin +++\n\n");
	

	printf("--------------------12--------------------\n\n");


	printf("+++ Start Ajouter Favoris +++\n");
	strcpy(ajouter_favoris_1_arg.serieAchete.titre,"Le Hero");
	strcpy(ajouter_favoris_1_arg.compteAcheteur.pseudo,"Le Narrateur");
	result_ajouter_favoris = ajouter_favoris_1(&ajouter_favoris_1_arg, clnt);
	if (result_ajouter_favoris == (int *) NULL) {
		clnt_perror (clnt, "Ajouter Favoris call failed");
	} else {
		if (*result_ajouter_favoris == 0){
			// echec
			printf("ajouter_favoris_1 echec\n");
		}else{
			//echec
			printf("ajouter_favoris_1 reussi\n");
		}
	}
	printf("+++ End Ajouter Favoris +++\n\n");


	printf("--------------------13--------------------\n\n");


	printf("+++ Start Ajouter Favoris +++\n");
	strcpy(ajouter_favoris_1_arg.serieAchete.titre,"Locked");
	strcpy(ajouter_favoris_1_arg.compteAcheteur.pseudo,"Le Narrateur");
	result_ajouter_favoris = ajouter_favoris_1(&ajouter_favoris_1_arg, clnt);
	if (result_ajouter_favoris == (int *) NULL) {
		clnt_perror (clnt, "Ajouter Favoris call failed");
	} else {
		if (*result_ajouter_favoris == 0){
			// echec
			printf("ajouter_favoris_1 echec\n");
		}else{
			//echec
			printf("ajouter_favoris_1 reussi\n");
		}
	}
	printf("+++ End Ajouter Favoris +++\n\n");


	printf("--------------------14--------------------\n\n");


	printf("+++ Start Afficher Favoris +++\n");
	strcpy(afficher_favoris_1_arg.pseudo,"Le Narrateur");
	result_afficher_favoris = afficher_favoris_1(&afficher_favoris_1_arg, clnt);
	if (result_afficher_favoris == (listSerie *) NULL) {
		clnt_perror (clnt, "Afficher Favoris call failed");
	}else{
		if(result_afficher_favoris != NULL){
			printf("Les Series favorites de %s\n", afficher_favoris_1_arg.pseudo);
			for(int i=0; i<result_afficher_favoris->nbSerie; i++){
				printf("%s\n",result_afficher_favoris->listSerie[i].titre);
			}
		}
	}
	printf("+++ End Afficher Favoris +++\n\n");
	
	
	printf("--------------------15--------------------\n\n");


	printf("+++ Start Ajouter Commentaire +++\n");
	strcpy(ajouter_commentaire_1_arg.c.comm, "sympa");
	strcpy(ajouter_commentaire_1_arg.c.pseudo, "Le Narrateur");
	strcpy(ajouter_commentaire_1_arg.s.titre,"Locked");
	result_ajouter_commentaire = ajouter_commentaire_1(&ajouter_commentaire_1_arg, clnt);
	if (result_ajouter_commentaire == (int *) NULL) {
		clnt_perror (clnt, "Ajouter Commentaire call failed");
	} else {
		if (*result_inscription == 0){
			// echec
			printf("ajouter_commentaire_1 echec\n");
		}else{
			//echec
			printf("ajouter_commentaire_1 reussi\n");
		}
	}
	printf("+++ End Ajouter Commentaire +++\n\n");

	
	printf("--------------------16--------------------\n\n");


	printf("+++ Start Ajouter Note +++\n");
	ajouter_note_1_arg.note = 10;
	strcpy(ajouter_note_1_arg.serieNote.titre,"Locked");
	result_ajouter_note = ajouter_note_1(&ajouter_note_1_arg, clnt);
	if (result_ajouter_note == (int *) NULL) {
		clnt_perror (clnt, "Ajouter Note call failed");
	} else {
		if (*result_inscription == 0){
			// echec
			printf("ajouter_note_1 echec\n");
		}else{
			//echec
			printf("ajouter_note_1 reussi\n");
		}
	}
	printf("+++ End Ajouter Note +++\n\n");

	
	printf("--------------------17--------------------\n\n");


	printf("+++ Start Supprimer Favoris +++\n");
	strcpy(supprimer_favoris_1_arg.serieAchete.titre,"Locked");
	strcpy(supprimer_favoris_1_arg.compteAcheteur.pseudo,"Le Narrateur");
	result_supprimer_favoris = supprimer_favoris_1(&supprimer_favoris_1_arg, clnt);
	if (result_supprimer_favoris == (int *) NULL) {
		clnt_perror (clnt, "Supprimer Favoris call failed");
	} else {
		if (*result_inscription == 0){
			// echec
			printf("supprimer_favoris_1 echec\n");
		}else{
			//echec
			printf("supprimer_favoris_1 reussi\n");
		}
	}
	printf("+++ End Supprimer Favoris +++\n\n");


	printf("--------------------18--------------------\n\n");


	printf("+++ Start Afficher Favoris +++\n");
	strcpy(afficher_favoris_1_arg.pseudo,"Le Narrateur");
	result_afficher_favoris = afficher_favoris_1(&afficher_favoris_1_arg, clnt);
	if (result_afficher_favoris == (listSerie *) NULL) {
		clnt_perror (clnt, "Afficher Favoris call failed");
	}else{
		if(result_afficher_favoris != NULL){
			printf("Les Series favorites de %s\n", afficher_favoris_1_arg.pseudo);
			for(int i=0; i<result_afficher_favoris->nbSerie; i++){
				printf("%s\n",result_afficher_favoris->listSerie[i].titre);
			}
		}
	}
	printf("+++ End Afficher Favoris +++\n\n");


	printf("--------------------19--------------------\n\n");


	printf("+++ Start Supprimer Commentaire +++\n");
	strcpy(supprimer_commentaire_1_arg.c.comm,"sympa");
	strcpy(supprimer_commentaire_1_arg.c.pseudo,"Le Narrateur");
	strcpy(supprimer_commentaire_1_arg.s.titre,"Locked");
	result_supprimer_commentaire = supprimer_commentaire_1(&supprimer_commentaire_1_arg, clnt);
	if (result_supprimer_commentaire == (int *) NULL) {
		clnt_perror (clnt, "Supprimer Commentaire call failed");
	} else {
		if (*result_inscription == 0){
			// echec
			printf("supprimer_commentaire_1 echec\n");
		}else{
			//echec
			printf("supprimer_commentaire_1 reussi\n");
		}
	}
	printf("+++ End Supprimer Commentaire +++\n");

#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	webtoon_prog_1 (host);
exit (0);
}
