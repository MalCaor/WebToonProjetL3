/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "webtoon.h"

bool_t
xdr_commentaire (XDR *xdrs, commentaire *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->pseudo, 15,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->comm, 15,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_date (XDR *xdrs, date *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->jour))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->mois))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->annee))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_genre (XDR *xdrs, genre *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_int (xdrs, &objp->idGenre))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->nomGenre, 15,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_serie (XDR *xdrs, serie *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		 if (!xdr_int (xdrs, &objp->idSerie))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->titre, 10,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_double (xdrs, &objp->noteMoyenne))
			 return FALSE;
		buf = XDR_INLINE (xdrs, ( 10 ) * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->listGenre, 10,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;

		} else {
		{
			register int *genp;

			for (i = 0, genp = objp->listGenre;
				i < 10; ++i) {
				IXDR_PUT_LONG(buf, *genp++);
			}
		}
		}
		 if (!xdr_date (xdrs, &objp->dateSerie))
			 return FALSE;
		 if (!xdr_int (xdrs, &objp->nbCommentaire))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->listComm, 5,
			sizeof (commentaire), (xdrproc_t) xdr_commentaire))
			 return FALSE;
		 if (!xdr_int (xdrs, &objp->nbrVue))
			 return FALSE;
		 if (!xdr_int (xdrs, &objp->nbEpisode))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->description, 10,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		 if (!xdr_int (xdrs, &objp->idSerie))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->titre, 10,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_double (xdrs, &objp->noteMoyenne))
			 return FALSE;
		buf = XDR_INLINE (xdrs, ( 10 ) * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->listGenre, 10,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;

		} else {
		{
			register int *genp;

			for (i = 0, genp = objp->listGenre;
				i < 10; ++i) {
				*genp++ = IXDR_GET_LONG(buf);
			}
		}
		}
		 if (!xdr_date (xdrs, &objp->dateSerie))
			 return FALSE;
		 if (!xdr_int (xdrs, &objp->nbCommentaire))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->listComm, 5,
			sizeof (commentaire), (xdrproc_t) xdr_commentaire))
			 return FALSE;
		 if (!xdr_int (xdrs, &objp->nbrVue))
			 return FALSE;
		 if (!xdr_int (xdrs, &objp->nbEpisode))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->description, 10,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->idSerie))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->titre, 10,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->noteMoyenne))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->listGenre, 10,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	 if (!xdr_date (xdrs, &objp->dateSerie))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->nbCommentaire))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->listComm, 5,
		sizeof (commentaire), (xdrproc_t) xdr_commentaire))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->nbrVue))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->nbEpisode))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->description, 10,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_argAjoutComm (XDR *xdrs, argAjoutComm *objp)
{
	register int32_t *buf;

	 if (!xdr_serie (xdrs, &objp->s))
		 return FALSE;
	 if (!xdr_commentaire (xdrs, &objp->c))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_argAjouterNote (XDR *xdrs, argAjouterNote *objp)
{
	register int32_t *buf;

	 if (!xdr_serie (xdrs, &objp->serieNote))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->note))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_argTri (XDR *xdrs, argTri *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->tri))
		 return FALSE;
	 if (!xdr_genre (xdrs, &objp->genreChoisi))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_listSerie (XDR *xdrs, listSerie *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_int (xdrs, &objp->nbSerie))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->listSerie, 5,
		sizeof (serie), (xdrproc_t) xdr_serie))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_compte (XDR *xdrs, compte *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		 if (!xdr_vector (xdrs, (char *)objp->pseudo, 15,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->mdp, 15,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		buf = XDR_INLINE (xdrs, (4 +  15  + 15 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->carteBancaire))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->nbSerieFavorite))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->serieFavorite, 15,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->nbSerieAchete))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->serieAchete, 15,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->coin))
				 return FALSE;
		} else {
			IXDR_PUT_LONG(buf, objp->carteBancaire);
			IXDR_PUT_LONG(buf, objp->nbSerieFavorite);
			{
				register int *genp;

				for (i = 0, genp = objp->serieFavorite;
					i < 15; ++i) {
					IXDR_PUT_LONG(buf, *genp++);
				}
			}
			IXDR_PUT_LONG(buf, objp->nbSerieAchete);
			{
				register int *genp;

				for (i = 0, genp = objp->serieAchete;
					i < 15; ++i) {
					IXDR_PUT_LONG(buf, *genp++);
				}
			}
			IXDR_PUT_LONG(buf, objp->coin);
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		 if (!xdr_vector (xdrs, (char *)objp->pseudo, 15,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->mdp, 15,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		buf = XDR_INLINE (xdrs, (4 +  15  + 15 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->carteBancaire))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->nbSerieFavorite))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->serieFavorite, 15,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->nbSerieAchete))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->serieAchete, 15,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->coin))
				 return FALSE;
		} else {
			objp->carteBancaire = IXDR_GET_LONG(buf);
			objp->nbSerieFavorite = IXDR_GET_LONG(buf);
			{
				register int *genp;

				for (i = 0, genp = objp->serieFavorite;
					i < 15; ++i) {
					*genp++ = IXDR_GET_LONG(buf);
				}
			}
			objp->nbSerieAchete = IXDR_GET_LONG(buf);
			{
				register int *genp;

				for (i = 0, genp = objp->serieAchete;
					i < 15; ++i) {
					*genp++ = IXDR_GET_LONG(buf);
				}
			}
			objp->coin = IXDR_GET_LONG(buf);
		}
	 return TRUE;
	}

	 if (!xdr_vector (xdrs, (char *)objp->pseudo, 15,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->mdp, 15,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->carteBancaire))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->nbSerieFavorite))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->serieFavorite, 15,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->nbSerieAchete))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->serieAchete, 15,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->coin))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_argAchaCoin (XDR *xdrs, argAchaCoin *objp)
{
	register int32_t *buf;

	 if (!xdr_compte (xdrs, &objp->compteAcheteur))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->nbCoin))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_argAchaSerie (XDR *xdrs, argAchaSerie *objp)
{
	register int32_t *buf;

	 if (!xdr_serie (xdrs, &objp->serieAchete))
		 return FALSE;
	 if (!xdr_compte (xdrs, &objp->compteAcheteur))
		 return FALSE;
	return TRUE;
}
