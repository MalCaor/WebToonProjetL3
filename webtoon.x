struct commentaire{char pseudo[50]; char comm[255];};
struct genre{char nomGenre[50];};
struct serie{char titre[100]; double noteMoyenne; genre listGenre[10]; date dateSerie; commentaire listComm[15]; int nbrVue; int nbEpisode; char description[255];};
struct argAjoutComm{serie s; commentaire c;};
struct argAjouterNote{serie serieNote; int note;};
struct argTri{int tri; genre genreChoisi;};
struct listSerie{int nbSerie; serie listSerie[50];};
struct date{int jour; int mois; int annee;};
struct compte{char pseudo[50]; char mdp[50]; int carteBancaire[16]; serie serieFavorite[50]; int coin;};
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