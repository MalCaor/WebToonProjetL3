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

	result_init = init_1((void*)&init_1_arg, clnt);
	if (result_init == (void *) NULL) {
		clnt_perror (clnt, "Init call failed");
	} else {
		printf("Initialisation termine\n");
	}
	
	strcpy(inscription_1_arg.pseudo,"Le Narrateur");
	strcpy(inscription_1_arg.mdp,"1234");
	inscription_1_arg.carteBancaire=0;
	inscription_1_arg.coin=0;
	result_inscription = inscription_1(&inscription_1_arg, clnt);
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

	// update mdp with abcd
	maj_info_1_arg = inscription_1_arg;
	strcpy(maj_info_1_arg.mdp,"abcd");

	result_maj_info = maj_info_1(&maj_info_1_arg, clnt);
	if (result_maj_info == (int *) NULL) {
		clnt_perror (clnt, "Maj Info call failed");
	} else {
		if (*result_inscription == 0){
			// echec
			printf("maj_info_1 echec\n");
		}else{
			//echec
			printf("maj_info_1 reussi\n");
		}
	}
	
	strcpy(afficher_serie_1_arg.genreChoisi.nomGenre, "humour");
	*afficher_serie_1_arg.genreChoisi.nomGenre = 1;
	result_afficher_serie = afficher_serie_1(&afficher_serie_1_arg, clnt);
	if (result_afficher_serie == (listSerie *) NULL) {
		clnt_perror (clnt, "Afficher Serie call failed");
	}else{
		if(result_afficher_serie != NULL){
			printf("Les Series : %s\n", afficher_serie_1_arg.genreChoisi);
			for(int i=0; i<result_afficher_serie->nbSerie; i++){
				printf("%s\n",result_afficher_serie->listSerie[i]);
			}
		}
	}
	
	strcpy(acheter_serie_1_arg.serieAchete.titre,"L'enfermation");
	strcpy(acheter_serie_1_arg.compteAcheteur.pseudo,"Le Narrateur");
	result_acheter_serie = acheter_serie_1(&acheter_serie_1_arg, clnt);
	if (result_acheter_serie == (int *) NULL) {
		clnt_perror (clnt, "Acheter Serie call failed");
	} else {
		if (*result_inscription == 0){
			// echec
			printf("acheter_serie_1 echec\n");
		}else{
			//echec
			printf("acheter_serie_1 reussi\n");
		}
	}

	strcpy(acheter_coin_1_arg.compteAcheteur.pseudo,"Le Narrateur");
	acheter_coin_1_arg.nbCoin = 100;
	result_acheter_coin = acheter_coin_1(&acheter_coin_1_arg, clnt);
	if (result_acheter_coin == (int *) NULL) {
		clnt_perror (clnt, "Acheter Coin call failed");
	} else {
		if (*result_inscription == 0){
			// echec
			printf("acheter_coin_1 echec\n");
		}else{
			//echec
			printf("acheter_coin_1 reussi\n");
		}
	}

	maj_info_1_arg.carteBancaire = 1234123412341234;
	result_maj_info = maj_info_1(&maj_info_1_arg, clnt);
	if (result_maj_info == (int *) NULL) {
		clnt_perror (clnt, "Maj Info call failed");
	}else{
		if (*result_inscription == 0){
			// echec
			printf("maj_info_1 echec\n");
		}else{
			//echec
			printf("maj_info_1 reussi\n");
		}
	}

	// acheter_coin_1_arg est deja remplie au premier appel
	result_acheter_coin = acheter_coin_1(&acheter_coin_1_arg, clnt);
	if (result_acheter_coin == (int *) NULL) {
		clnt_perror (clnt, "Acheter Coin call failed");
	} else {
		if (*result_inscription == 0){
			// echec
			printf("acheter_coin_1 echec\n");
		}else{
			//echec
			printf("acheter_coin_1 reussi\n");
		}
	}

	/*
	result_afficher_coin = afficher_coin_1(&afficher_coin_1_arg, clnt);
	if (result_afficher_coin == (int *) NULL) {
		clnt_perror (clnt, "Afficher Coincall failed");
	}
	result_ajouter_favoris = ajouter_favoris_1(&ajouter_favoris_1_arg, clnt);
	if (result_ajouter_favoris == (int *) NULL) {
		clnt_perror (clnt, "Ajouter Favoris call failed");
	} else {
		if (*result_inscription == 0){
			// echec
			printf("ajouter_favoris_1 echec\n");
		}else{
			//echec
			printf("ajouter_favoris_1 reussi\n");
		}
	}
	result_afficher_favoris = afficher_favoris_1(&afficher_favoris_1_arg, clnt);
	if (result_afficher_favoris == (listSerie *) NULL) {
		clnt_perror (clnt, "Afficher Favoris call failed");
	}
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
	}*/

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
