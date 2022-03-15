/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _WEBTOON_H_RPCGEN
#define _WEBTOON_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct commentaire {
	char pseudo[15];
	char comm[15];
};
typedef struct commentaire commentaire;

struct date {
	int jour;
	int mois;
	int annee;
};
typedef struct date date;

struct genre {
	char nomGenre[15];
};
typedef struct genre genre;

struct serie {
	char titre[15];
	double noteMoyenne;
	genre listGenre[15];
	date dateSerie;
	commentaire listComm[15];
	int nbrVue;
	int nbEpisode;
	char description[15];
};
typedef struct serie serie;

struct argAjoutComm {
	serie s;
	commentaire c;
};
typedef struct argAjoutComm argAjoutComm;

struct argAjouterNote {
	serie serieNote;
	int note;
};
typedef struct argAjouterNote argAjouterNote;

struct argTri {
	int tri;
	genre genreChoisi;
};
typedef struct argTri argTri;

struct listSerie {
	int nbSerie;
	serie listSerie[15];
};
typedef struct listSerie listSerie;

struct compte {
	char pseudo[15];
	char mdp[15];
	int carteBancaire;
	serie serieFavorite[15];
	int coin;
};
typedef struct compte compte;

struct argAchaCoin {
	compte compteAcheteur;
	int nbCoin;
};
typedef struct argAchaCoin argAchaCoin;

struct argAchaSerie {
	serie serieAchete;
	compte compteAcheteur;
};
typedef struct argAchaSerie argAchaSerie;

#define WEBTOON_PROG 0x20000001
#define WEBTOON_VERSION_1 1

#if defined(__STDC__) || defined(__cplusplus)
#define INIT 1
extern  void * init_1(void *, CLIENT *);
extern  void * init_1_svc(void *, struct svc_req *);
#define INSCRIPTION 2
extern  int * inscription_1(compte *, CLIENT *);
extern  int * inscription_1_svc(compte *, struct svc_req *);
#define MAJ_INFO 3
extern  int * maj_info_1(compte *, CLIENT *);
extern  int * maj_info_1_svc(compte *, struct svc_req *);
#define AFFICHER_SERIE 4
extern  listSerie * afficher_serie_1(argTri *, CLIENT *);
extern  listSerie * afficher_serie_1_svc(argTri *, struct svc_req *);
#define ACHETER_SERIE 5
extern  int * acheter_serie_1(argAchaSerie *, CLIENT *);
extern  int * acheter_serie_1_svc(argAchaSerie *, struct svc_req *);
#define AJOUTER_NOTE 6
extern  int * ajouter_note_1(argAjouterNote *, CLIENT *);
extern  int * ajouter_note_1_svc(argAjouterNote *, struct svc_req *);
#define ACHETER_COIN 7
extern  int * acheter_coin_1(argAchaCoin *, CLIENT *);
extern  int * acheter_coin_1_svc(argAchaCoin *, struct svc_req *);
#define AFFICHER_COIN 8
extern  int * afficher_coin_1(compte *, CLIENT *);
extern  int * afficher_coin_1_svc(compte *, struct svc_req *);
#define AJOUTER_FAVORIS 9
extern  int * ajouter_favoris_1(argAchaSerie *, CLIENT *);
extern  int * ajouter_favoris_1_svc(argAchaSerie *, struct svc_req *);
#define AFFICHER_FAVORIS 10
extern  listSerie * afficher_favoris_1(compte *, CLIENT *);
extern  listSerie * afficher_favoris_1_svc(compte *, struct svc_req *);
#define SUPPRIMER_FAVORIS 11
extern  int * supprimer_favoris_1(argAchaSerie *, CLIENT *);
extern  int * supprimer_favoris_1_svc(argAchaSerie *, struct svc_req *);
#define AJOUTER_COMMENTAIRE 12
extern  int * ajouter_commentaire_1(argAjoutComm *, CLIENT *);
extern  int * ajouter_commentaire_1_svc(argAjoutComm *, struct svc_req *);
#define SUPPRIMER_COMMENTAIRE 13
extern  int * supprimer_commentaire_1(argAjoutComm *, CLIENT *);
extern  int * supprimer_commentaire_1_svc(argAjoutComm *, struct svc_req *);
extern int webtoon_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define INIT 1
extern  void * init_1();
extern  void * init_1_svc();
#define INSCRIPTION 2
extern  int * inscription_1();
extern  int * inscription_1_svc();
#define MAJ_INFO 3
extern  int * maj_info_1();
extern  int * maj_info_1_svc();
#define AFFICHER_SERIE 4
extern  listSerie * afficher_serie_1();
extern  listSerie * afficher_serie_1_svc();
#define ACHETER_SERIE 5
extern  int * acheter_serie_1();
extern  int * acheter_serie_1_svc();
#define AJOUTER_NOTE 6
extern  int * ajouter_note_1();
extern  int * ajouter_note_1_svc();
#define ACHETER_COIN 7
extern  int * acheter_coin_1();
extern  int * acheter_coin_1_svc();
#define AFFICHER_COIN 8
extern  int * afficher_coin_1();
extern  int * afficher_coin_1_svc();
#define AJOUTER_FAVORIS 9
extern  int * ajouter_favoris_1();
extern  int * ajouter_favoris_1_svc();
#define AFFICHER_FAVORIS 10
extern  listSerie * afficher_favoris_1();
extern  listSerie * afficher_favoris_1_svc();
#define SUPPRIMER_FAVORIS 11
extern  int * supprimer_favoris_1();
extern  int * supprimer_favoris_1_svc();
#define AJOUTER_COMMENTAIRE 12
extern  int * ajouter_commentaire_1();
extern  int * ajouter_commentaire_1_svc();
#define SUPPRIMER_COMMENTAIRE 13
extern  int * supprimer_commentaire_1();
extern  int * supprimer_commentaire_1_svc();
extern int webtoon_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_commentaire (XDR *, commentaire*);
extern  bool_t xdr_date (XDR *, date*);
extern  bool_t xdr_genre (XDR *, genre*);
extern  bool_t xdr_serie (XDR *, serie*);
extern  bool_t xdr_argAjoutComm (XDR *, argAjoutComm*);
extern  bool_t xdr_argAjouterNote (XDR *, argAjouterNote*);
extern  bool_t xdr_argTri (XDR *, argTri*);
extern  bool_t xdr_listSerie (XDR *, listSerie*);
extern  bool_t xdr_compte (XDR *, compte*);
extern  bool_t xdr_argAchaCoin (XDR *, argAchaCoin*);
extern  bool_t xdr_argAchaSerie (XDR *, argAchaSerie*);

#else /* K&R C */
extern bool_t xdr_commentaire ();
extern bool_t xdr_date ();
extern bool_t xdr_genre ();
extern bool_t xdr_serie ();
extern bool_t xdr_argAjoutComm ();
extern bool_t xdr_argAjouterNote ();
extern bool_t xdr_argTri ();
extern bool_t xdr_listSerie ();
extern bool_t xdr_compte ();
extern bool_t xdr_argAchaCoin ();
extern bool_t xdr_argAchaSerie ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_WEBTOON_H_RPCGEN */
