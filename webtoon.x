struct commentaire{char pseudo[15]; char comm[15];};
struct date{int jour; int mois; int annee;};
struct genre{int idGenre; char nomGenre[15];};

struct serie{int idSerie; char titre[10]; double noteMoyenne; int listGenre[10]; date dateSerie; int nbCommentaire; commentaire listComm[5]; int nbrVue; int nbEpisode; char description[10];};
struct argAjoutComm{serie s; commentaire c;};
struct argAjouterNote{serie serieNote; int note;};
struct argTri{int tri; genre genreChoisi;};
struct listSerie{int nbSerie; serie listSerie[5];};
struct compte{char pseudo[15]; char mdp[15]; int carteBancaire; int nbSerieFavorite; int serieFavorite[15]; int nbSerieAchete; int serieAchete[15]; int coin;};
struct argAchaCoin{compte compteAcheteur; int nbCoin;};
struct argAchaSerie{serie serieAchete; compte compteAcheteur;};


program WEBTOON_PROG {
    version WEBTOON_VERSION_1 {
        void INIT(void)=1;
        int INSCRIPTION(compte)=2;
        int MAJ_INFO(compte)=3;
        listSerie AFFICHER_SERIE(argTri)=4;
        int ACHETER_SERIE(argAchaSerie)=5;
        int AJOUTER_NOTE(argAjouterNote)=6;
        int ACHETER_COIN(argAchaCoin)=7;
        int AFFICHER_COIN(compte)=8;
        int AJOUTER_FAVORIS(argAchaSerie)=9;
        listSerie AFFICHER_FAVORIS(compte)=10;
        int SUPPRIMER_FAVORIS(argAchaSerie)=11;
        int AJOUTER_COMMENTAIRE(argAjoutComm)=12;
        int SUPPRIMER_COMMENTAIRE(argAjoutComm)=13;
    } = 1;
} = 0x20000001;