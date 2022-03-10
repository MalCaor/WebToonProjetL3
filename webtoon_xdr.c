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
	 if (!xdr_vector (xdrs, (char *)objp->pseudo, 50,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->comm, 255,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_genre (XDR *xdrs, genre *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->nomGenre, 50,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_serie (XDR *xdrs, serie *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->titre, 100,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->noteMoyenne))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->listGenre, 10,
		sizeof (genre), (xdrproc_t) xdr_genre))
		 return FALSE;
	 if (!xdr_date (xdrs, &objp->dateSerie))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->listComm, 15,
		sizeof (commentaire), (xdrproc_t) xdr_commentaire))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->nbrVue))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->nbEpisode))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->description, 255,
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
	 if (!xdr_vector (xdrs, (char *)objp->listSerie, 50,
		sizeof (serie), (xdrproc_t) xdr_serie))
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
xdr_compte (XDR *xdrs, compte *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		 if (!xdr_vector (xdrs, (char *)objp->pseudo, 50,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->mdp, 50,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		buf = XDR_INLINE (xdrs, ( 16 ) * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->carteBancaire, 16,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;

		} else {
		{
			register int *genp;

			for (i = 0, genp = objp->carteBancaire;
				i < 16; ++i) {
				IXDR_PUT_LONG(buf, *genp++);
			}
		}
		}
		 if (!xdr_vector (xdrs, (char *)objp->serieFavorite, 50,
			sizeof (serie), (xdrproc_t) xdr_serie))
			 return FALSE;
		 if (!xdr_int (xdrs, &objp->coin))
			 return FALSE;
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		 if (!xdr_vector (xdrs, (char *)objp->pseudo, 50,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->mdp, 50,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		buf = XDR_INLINE (xdrs, ( 16 ) * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->carteBancaire, 16,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;

		} else {
		{
			register int *genp;

			for (i = 0, genp = objp->carteBancaire;
				i < 16; ++i) {
				*genp++ = IXDR_GET_LONG(buf);
			}
		}
		}
		 if (!xdr_vector (xdrs, (char *)objp->serieFavorite, 50,
			sizeof (serie), (xdrproc_t) xdr_serie))
			 return FALSE;
		 if (!xdr_int (xdrs, &objp->coin))
			 return FALSE;
	 return TRUE;
	}

	 if (!xdr_vector (xdrs, (char *)objp->pseudo, 50,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->mdp, 50,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->carteBancaire, 16,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->serieFavorite, 50,
		sizeof (serie), (xdrproc_t) xdr_serie))
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